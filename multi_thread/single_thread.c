#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

/*Define the upper bound of the elements in the matrix to avoid overflows after multiplication*/
#define RANGE 10
/*The order of the square matrix*/
#define N 100
#define REPETITION 1000


int rand_seed = 7;


void gene_matrix(int **matrix, int order)
{
    int i, j;
    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
        {
            rand_seed += rand();
            rand_seed = rand_seed % RANGE;
//            *((int *) matrix + order * i + j) = rand_seed;
            matrix[i][j] = rand_seed;
        }
    }
}

void print_matrix(const int **matrix, int order)
{
    for (int i = 0; i < order; ++i)
    {
        for (int j = 0; j < order; ++j)
        {
            int tmp = matrix[i][j];
            printf("%d ", tmp);
        }
        printf("\n");
    }
}

int **malloc_matrix(int n)
{
    int **A = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        A[i] = (int *) malloc(sizeof(int) * n);


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = 0;
        }
    }

    return A;
}

void free_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

void to_zero(int **res, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[i][j] = 0;
        }
    }
}

int main()
{
    setbuf(stdout, NULL);
    for (int order = 2; order <= N; ++order)
    {
        int **matrixA = malloc_matrix(order);
        int **matrixB = malloc_matrix(order);
        int **res = malloc_matrix(order);
        double total_time = 0;
        for (int time_i = 0; time_i < REPETITION; ++time_i)
        {
            gene_matrix((int **) matrixA, order);
            gene_matrix((int **) matrixB, order);
            to_zero(res, order);
            clock_t start = clock();
            for (int i = 0; i < order; i++)
                for (int j = 0; j < order; j++)
                    for (int k = 0; k < order; k++)
                        res[i][j] += matrixA[i][k] * matrixB[k][j];
            clock_t finish = clock();
            total_time += (double) (finish - start);
        }
        free_matrix(matrixA, order);
        free_matrix(matrixB, order);
        free_matrix(res, order);
        printf("matrix order is: %d, cycle times : %d\n", order, REPETITION);
        printf("average time of serial calculation is %.10f sec\n",
               (double) (total_time / REPETITION) / CLOCKS_PER_SEC);
    }
    return 0;
}

