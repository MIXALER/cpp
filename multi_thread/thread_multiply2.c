#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

/*定义矩阵中元素的上限，避免相乘后溢出*/
#define RANGE 100
/*矩阵A有M行N列，矩阵B有N行M列*/
#define M 200
#define N 300

void gene_matrix();

void read_matrix();

int matrixA[M][N];
int matrixB[N][M];
int arr[M][M][N];

void *func(void *arg);

int main()
{
    long total_time = 0;
    for (int time_i = 0; time_i < 50; ++time_i)
    {
        gene_matrix();                                      //用随机数产生两个待相乘的矩阵，并分别存入两个文件中
        read_matrix();                                      //从两个文件中读出数据赋给matrixA和matrixB
        clock_t start = clock();                              //开始计时
        int res[M][N] = {0};                                  //保存矩阵相乘的结果。非全局变量一定要显示初始化为0,否则为随机的一个数
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
        for (i = 0; i < M; i++)                                 //合。
            for (j = 0; j < M; j++)
                for (k = 0; k < N; k++)
                    res[i][j] += arr[i][j][k];
        clock_t finish = clock();                             //结束计算
        total_time += (long) (finish - start);
    }
    printf("并行计算用时%.2f秒\n", (long) (total_time / 50) / 1E6);
    exit(0);
}

void *func(void *arg)                                   //每个子线程要完成的任务
{
    int k = *(int *) arg;
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < M; j++)
            arr[i][j][k] = matrixA[i][k] * matrixB[k][j];
    pthread_exit(NULL);
}

void gene_matrix()
{
    FILE *file1, *file2;
    if ((file1 = fopen("./matrixA", "wt")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    if ((file2 = fopen("./matrixB", "wt")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    int i, j;
    srand((unsigned) time(NULL));
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            fprintf(file1, "%-8d", rand() % RANGE);
        fprintf(file1, "\n");
    }
    fclose(file1);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            fprintf(file2, "%-8d", rand() % RANGE);
        fprintf(file2, "\n");
    }
    fclose(file2);
}

void read_matrix()
{
    FILE *file1, *file2;
    if ((file1 = fopen("./matrixA", "rt")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    if ((file2 = fopen("./matrixB", "rt")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            fscanf(file1, "%d", &matrixA[i][j]);
    fclose(file1);
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            fscanf(file2, "%d", &matrixB[i][j]);
    fclose(file2);
}
