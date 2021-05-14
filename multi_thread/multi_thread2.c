#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

#define N 100
#define REPETITION 10
#define RANGE 10


int rand_seed = 5;

pthread_t hThread[N][N];
int pass[N][N][2];

int mat1[N][N];
int mat2[N][N];
int res[N][N];

void gene_matrix(int **matrix);

void print_matrix(const int **matrix);

void ThreadProc(int *param)
{
    int row = param[0];
    int col = param[1];
    int rs = 0;

    int loop;
    for (loop = 0; loop < N; ++loop)
    {
        rs += mat1[row][loop] * mat2[loop][col];
    }
    res[row][col] = rs;
}

int main()
{
    double total_time = 0;
    for (int time_i = 0; time_i < REPETITION; ++time_i)
    {
//        printf("time_i : %d\n", time_i);
        gene_matrix((int **) mat1);
        gene_matrix((int **) mat2);
        clock_t start = clock();
        int i, j;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; ++j)
            {
                pass[i][j][0] = i;
                pass[i][j][1] = j;
                pthread_create(&hThread[i][j], NULL, (void *) ThreadProc, pass[i][j]);
            }
        }

        for (i = 0; i < N; ++i)
        {
            for (j = 0; j < N; ++j)
            {
                pthread_join(hThread[i][j], NULL);
            }
        }
        clock_t finish = clock();
//        print_matrix((const int **)mat1);
//        print_matrix((const int **)mat2);
//        print_matrix((const int **)res);
        total_time += (double) (finish - start);
    }
    printf("matrix order is: %d, cycle times : %d\n", N, REPETITION);
    printf("average time of parallel computing is %.10f sec\n", (double) (total_time / REPETITION) / CLOCKS_PER_SEC);
    return 0;
}

void gene_matrix(int **matrix)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            rand_seed += rand();
            rand_seed = rand_seed % RANGE;
            *((int *) matrix + N * i + j) = rand_seed;
        }
    }
}

void print_matrix(const int **matrix)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int tmp = *((int *) matrix + N * i + j);
            printf("%d ", tmp);
        }
        printf("\n");
    }
}