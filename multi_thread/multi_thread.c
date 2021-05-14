#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

/*Define the upper bound of the elements in the matrix to avoid overflows after multiplication*/
#define RANGE 10
/*The order of the square matrix*/
#define N 100
#define REPETITION 1000

struct multi_matrix
{
    int **matrixA;
    int **matrixB;
    int **res;
};


struct param
{
    struct multi_matrix *p_matrix;
    int row;
    int col;
    int order;
};

int rand_seed = 7;


void ThreadProc(struct param *tmp);

void gene_matrix(int **matrix, int order);

void print_matrix(const int **matrix, int order);

int **malloc_matrix(int n);

pthread_t **malloc_pthread(int n);

void free_matrix(int **matrix, int n);

void to_zero(int **res, int n);

void free_thread(pthread_t **hthread, int n);

struct param **malloc_struct_param(int n);

void free_param(struct param **pass, int n);


int main()
{
    setbuf(stdout, NULL);
    for (int order = 2; order <= N; ++order)
    {
        pthread_t **hThread = malloc_pthread(order);
        struct multi_matrix tmp_multi_matrix;
        tmp_multi_matrix.matrixA = malloc_matrix(order); tmp_multi_matrix.matrixB = malloc_matrix(order); tmp_multi_matrix.res = malloc_matrix(order);
        struct param **pass = malloc_struct_param(order);
        double total_time = 0;
        for (int time_i = 0; time_i < REPETITION; ++time_i)
        {
            gene_matrix(tmp_multi_matrix.matrixA, order);
            gene_matrix(tmp_multi_matrix.matrixB, order);
            to_zero(tmp_multi_matrix.res, order);
            clock_t start = clock();
            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; ++j)
                {
                    pass[i][j].row = i; pass[i][j].col = j; pass[i][j].order = order; pass[i][j].p_matrix = &tmp_multi_matrix;
                    pthread_create(&hThread[i][j], NULL, (void *) ThreadProc, &pass[i][j]);
                }
            }
            for (int i = 0; i < order; ++i)
            {
                for (int j = 0; j < order; ++j)
                {
                    pthread_join(hThread[i][j], NULL);
                }
            }
            clock_t finish = clock();
            total_time += (double) (finish - start);
        }
        free_matrix(tmp_multi_matrix.matrixA, order); free_matrix(tmp_multi_matrix.matrixB, order); free_matrix(tmp_multi_matrix.res, order);
        free_param(pass, order); free_thread(hThread, order);
        printf("matrix order is: %d, cycle times : %d, num of threads : %d\n", order, REPETITION, order * order);
        printf("average time of parallel computing is %.10f sec\n",
               (double) (total_time / REPETITION) / CLOCKS_PER_SEC);
    }
    return 0;
}

void ThreadProc(struct param *tmp)
{
    int row = tmp->row;
    int col = tmp->col;
//    printf("row: %d col: %d \n", row, col);
    int rs = 0;

    int loop;
    for (loop = 0; loop < tmp->order; ++loop)
    {
        rs += tmp->p_matrix->matrixA[row][loop] * tmp->p_matrix->matrixB[loop][col];
    }
//    printf("rs:  %d \n", rs);
    tmp->p_matrix->res[row][col] = rs;
}

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

pthread_t **malloc_pthread(int n)
{
    pthread_t **A = (pthread_t **) malloc(sizeof(pthread_t *) * n);
    for (int i = 0; i < n; i++)
        A[i] = (pthread_t *) malloc(sizeof(pthread_t) * n);

    return A;
}


struct param **malloc_struct_param(int n)
{
    struct param **A = (struct param **) malloc(sizeof(struct param *) * n);
    for (int i = 0; i < n; i++)
        A[i] = (struct param *) malloc(sizeof(struct param) * n);

    return A;
}

void free_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

void free_thread(pthread_t **hthread, int n)
{
    for (int i = 0; i < n; i++)
        free(hthread[i]);
    free(hthread);
}

void free_param(struct param **pass, int n)
{
    for (int i = 0; i < n; i++)
        free(pass[i]);
    free(pass);
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