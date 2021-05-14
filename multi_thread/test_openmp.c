#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



char* thread_func1(void* arg) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s pid: %u, tid: %u (0x%x)\n", (char*)arg, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);

    char* msg = "thread_func1";
    return msg;
}

void* thread_func2(void* arg) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s pid: %u, tid: %u (0x%x)\n", (char*)arg, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
    char* msg = "thread_func2 ";
    while(1) {
        printf("%s running\n", msg);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    if (pthread_create(&tid1, NULL, (void*)thread_func1, "new thread:") != 0) {
        printf("pthread_create error.");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&tid2, NULL, (void*)thread_func2, "new thread:") != 0) {
        printf("pthread_create error.");
        exit(EXIT_FAILURE);
    }
    pthread_detach(tid2);

    char* rev = NULL;
    pthread_join(tid1, (void *)&rev);
    printf("%s return.\n", rev);
    pthread_cancel(tid2);

    printf("main thread end.\n");
    return 0;
}