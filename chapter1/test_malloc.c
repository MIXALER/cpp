#include<stdio.h>
#include<stdlib.h>

void input(int **A, int n, int m) //二级指针A
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("A[%d][%d]=", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void exchange(int **A, int **B, int n, int m) //二级指针A,B
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            B[j][i] = A[i][j];
        }
    }
}

void output(int **A, int n, int m) //二级指针A
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, i;
    scanf("%d%d", &n, &m);
    int **A = (int **) malloc(sizeof(int *) * n); //n行
    for (i = 0; i < n; i++)
        A[i] = (int *) malloc(sizeof(int) * m); //m列

    input(A, n, m);

    printf("\n");
    output(A, n, m);
    printf("\n");

    int **B = (int **) malloc(sizeof(int *) * m); //m行
    for (i = 0; i < m; i++)
        B[i] = (int *) malloc(sizeof(int) * n); //n列

    exchange(A, B, n, m);

    output(B, m, n);

    for (i = 0; i < n; i++)
        free(A[i]);
    free(A);
    A = NULL;

    for (i = 0; i < m; i++)
        free(B[i]);
    free(B);
    B = NULL;
    return 0;
}