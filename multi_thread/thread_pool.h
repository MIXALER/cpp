#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

typedef struct condition
{
    pthread_mutex_t pmutex;
    pthread_cond_t pcond;
} condition_t;

typedef struct task
{
    void *(*run)(void *arg);

    void *arg;
    struct task *next;
} task_t;

typedef struct threadpool
{
    condition_t ready;
    task_t *first;
    task_t *last;
    int counter;
    int idle;
    int max_threads;
    int quit;
} threadpool_t;


int condition_init(condition_t *cond)
{
    int status;
    if ((status = pthread_mutex_init(&cond->pmutex, NULL)))//返回0代表初始化成功
        return status;
    if ((status = pthread_cond_init(&cond->pcond, NULL)))
        return status;
    return 0;
}

int condition_lock(condition_t *cond)
{
    return pthread_mutex_lock(&cond->pmutex);
}

int condition_unlock(condition_t *cond)
{
    return pthread_mutex_unlock(&cond->pmutex);
}

int condition_wait(condition_t *cond)
{
    return pthread_cond_wait(&cond->pcond, &cond->pmutex);
}

int condition_timewait(condition_t *cond, const struct timespec *abstime)
{
    return pthread_cond_timedwait(&cond->pcond, &cond->pmutex, abstime);
}

int condition_signal(condition_t *cond)
{
    return pthread_cond_signal(&cond->pcond);
}

int condition_broadcast(condition_t *cond)
{
    return pthread_cond_broadcast(&cond->pcond);
}

int condition_destory(condition_t *cond)
{
    int status;
    if ((status = pthread_mutex_destroy(&cond->pmutex)))
        return status;
    if ((status = pthread_cond_destroy(&cond->pcond)))
        return status;
    return 0;
}


void *thread_routine(void *arg)
{
    struct timespec abstime;
    int timeout;
//    printf("thread 0x%0x is starting\n", (int) pthread_self());
    threadpool_t *pool = (threadpool_t *) arg;
    while (1)
    {
        timeout = 0;
        condition_lock(&pool->ready);
        pool->idle++;
        //Wait for the queue to be notified of the arrival of a task or thread pool destruction
        while (pool->first == NULL && !pool->quit)
        {
//            printf("thread 0x%0x is waiting\n", (int) pthread_self());
            clock_gettime(CLOCK_REALTIME, &abstime);
            abstime.tv_sec += 2;
            int status = condition_timewait(&pool->ready, &abstime);
            if (status == ETIMEDOUT)
            {
//                printf("thread 0x%0x is wait timed out\n", (int) pthread_self());
                timeout = 1;
                break;
            }

        }
        pool->idle--;

        if (pool->first != NULL)
        {
            task_t *t = pool->first;
            pool->first = t->next;
            //It needs to be unlocked in order to add new tasks.Other consumer threads can enter the wait task.
            condition_unlock(&pool->ready);
            t->run(t->arg);
            free(t);
            condition_lock(&pool->ready);
        }
        if (pool->quit && pool->first == NULL)
        {
            pool->counter--;
            if (pool->counter == 0)
            {
                condition_signal(&pool->ready);
            }
            condition_unlock(&pool->ready);
            break;
        }

        if (timeout && pool->first == NULL)
        {
            pool->counter--;
            condition_unlock(&pool->ready);
            break;
        }
        condition_unlock(&pool->ready);
    }

//    printf("thread 0x%0x is exiting\n", (int) pthread_self());
    return NULL;
}

void threadpool_init(threadpool_t *pool, int threads)
{
    condition_init(&pool->ready);
    pool->first = NULL;
    pool->last = NULL;
    pool->counter = 0;
    pool->idle = 0;
    pool->max_threads = threads;
    pool->quit = 0;
}

void threadpool_add_task(threadpool_t *pool, void *(*run)(void *arg), void *arg)
{
    task_t *newstask = (task_t *) malloc(sizeof(task_t));
    newstask->run = run;
    newstask->arg = arg;
    newstask->next = NULL;

    condition_lock(&pool->ready);
    if (pool->first == NULL)
    {
        pool->first = newstask;
    } else
        pool->last->next = newstask;
    pool->last = newstask;
    if (pool->idle > 0)
    {
        condition_signal(&pool->ready);
    } else if (pool->counter < pool->max_threads)
    {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_routine, pool);
        pool->counter++;
    }
    condition_unlock(&pool->ready);
}

void threadpool_destory(threadpool_t *pool)
{

    if (pool->quit)
    {
        return;
    }
    condition_lock(&pool->ready);
    pool->quit = 1;
    if (pool->counter > 0)
    {
        if (pool->idle > 0)
            condition_broadcast(&pool->ready);

        while (pool->counter > 0)
        {
            condition_wait(&pool->ready);
        }
    }
    condition_unlock(&pool->ready);
    condition_destory(&pool->ready);
}
