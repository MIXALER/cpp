#include <stdio.h>
#include <stdlib.h>
#include "threadpool.h"
#include "thpool.c"

#define Max_no_of_threads 1000

int A[20][20];
int B[20][20];
int C[20][20];
int r1, c1, r2, c2;
int rn = 0, cn = 0;
int lrc = 0;
int input[30];

void multiply()
{
    printf("Thread #%u working on task\n", (int) pthread_self());
    int k;

    if (rn < r1 && rn >= 0)
    {
        if (cn < c2 && cn >= 0)
        {
            for (k = 0; k < c1; k++)
            {
                C[rn][cn] += A[rn][k] * B[k][cn];
            }
        }
        cn++;
        lrc++;
        if (lrc == (c2))
        {
            rn++;
            lrc = 0;
        }
    }
    if (cn == c2)
    {
        cn = 0;
    }
}

int main()
{
    int bufcount = 0;
    FILE *input_file = fopen("/home/mixaler/workspace/learncpp/input1.txt", "r");
    char buff[1000];
    if (!input_file)
        return 1;
    while (fgets(buff, 1000, input_file) != NULL)
    {
        input[bufcount] = atoi(buff);
        bufcount++;
    }
    r1 = input[0], c1 = input[1], r2 = input[2], c2 = input[3];
    if (c1 != r2)
    {
        printf("matrix multiplication cannot be done for this order");
        return 0;
    }
    int i, j;
    int mat1 = 4;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            A[i][j] = input[mat1];
            mat1++;
        }
    }
    printf("Elements of matrix 1 are \n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            B[i][j] = input[mat1];
            mat1++;
        }
    }
    printf("elements of matrix 2 are\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;
        }
    }
    int n1;
    n1 = input[mat1];
    if (n1 < 1 || n1 > Max_no_of_threads)
    {
        printf("More than the Max_no_of_threads");
        return 0;
    }

    printf("Making threadpool with %d threads\n", n1);
    threadpool thpool = thpool_init(n1);

    int i1;
    for (i1 = 0; i1 < (r1 * c2); i1++)
    {
        thpool_add_work(thpool, (void *) multiply, NULL);
    };


    int j1;

    thpool_wait(thpool);
    puts("Killing threadpool");
    thpool_destroy(thpool);
    for (i1 = 0; i1 < r1; i1++)
    {
        for (j1 = 0; j1 < c2; j1++)
        {
            printf("%d\t", C[i1][j1]);
        }
        printf("\n");
    }
    return 0;
}
