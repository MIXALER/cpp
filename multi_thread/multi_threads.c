#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

/*Define the upper bound of the elements in the matrix to avoid overflows after multiplication*/
#define RANGE 10
/*The order of the square matrix*/
#define N 2

int rand_seed = 5;

#define REPETITION 2

void gene_matrix(int **matrix);

void print_matrix(const int **matrix);

void *func(void *arg);

int matrixA[N][N] = {0};
int matrixB[N][N] = {0};
int arr[N][N][N] = {0};

int main()
{
    double total_time = 0;
    for (int time_i = 0; time_i < REPETITION; ++time_i)
    {
        gene_matrix((int **) matrixA);
        gene_matrix((int **) matrixB);
        int res[N][N] = {0};                                  //保存矩阵相乘的结果。非全局变量一定要显示初始化为0,否则为随机的一个数
        clock_t start = clock();                              //开始计时

        int i, j, k;
        pthread_t tids[N];
        for (i = 0; i < N; i++)
        {
            if (pthread_create(&tids[i], NULL, func, (void *) &i))   //分。产生线程，去完成矩阵相乘的部分工作量
            {
                perror("pthread_create");
                exit(1);
            }
        }
        for (i = 0; i < N; i++)
            pthread_join(tids[i], NULL);                         //合之前一定要等所有的子线程计算结束
        for (i = 0; i < N; i++)                                 //合。
            for (j = 0; j < N; j++)
                for (k = 0; k < N; k++)
                    res[i][j] += arr[i][j][k];
        clock_t finish = clock();                             //结束计算
        print_matrix((const int **) (int **) matrixA);
        print_matrix((const int **) (int **) matrixB);
        print_matrix((const int **) (int **) res);
        total_time += (double) (finish - start);
    }
    printf("average time of parallel computing is %.10f sec\n", (double) (total_time / REPETITION) / CLOCKS_PER_SEC);
    exit(0);
}

void *func(void *arg)                                   //每个子线程要完成的任务
{
    int k = *(int *) arg;
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            arr[i][j][k] = matrixA[i][k] * matrixB[k][j];
    pthread_exit(NULL);
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