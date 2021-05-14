#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

pthread_t hThread[10][10];
int pass[10][10][2];

int M, K, N;
int mat1[10][10];
int mat2[10][10];
int res[10][10];

void ThreadProc(int* param)
{
    int row = param[0];
    int col = param[1];
    int rs = 0;

    int loop;
    for (loop = 0; loop < K; ++loop)
    {
        rs += mat1[row][loop] * mat2[loop][col];
    }
    res[row][col] = rs;
}

int main()
{
    int i, j;
    printf("输入矩阵的行数与列数：\n");
    scanf("%d%d", &M, &K);
    printf("输入矩阵：\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < K; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("输入矩阵的行数与列数：\n");
    scanf("%d%d", &K, &N);
    printf("输入矩阵：\n");
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; ++j)
        {
            pass[i][j][0] = i;
            pass[i][j][1] = j;
            pthread_create(&hThread[i][j], NULL, (void *)ThreadProc, pass[i][j]);
        }
    }

    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            pthread_join(hThread[i][j], NULL);
        }
    }
    printf("\n结果：");
    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}