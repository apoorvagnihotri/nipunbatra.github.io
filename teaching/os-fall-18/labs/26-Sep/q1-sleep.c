#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *print_thread(void *x)
{
    char *message = (char*)(x);
    printf("%s \n", message);
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    int rc1, rc2;
    printf("Inside main. Now creating the two threads\n");
    rc1 = pthread_create(&t1, NULL, print_thread, (void *)"A");
    rc2 = pthread_create(&t2, NULL, print_thread, (void *)"B");
    //sleep(0.05);
    printf("Exiting main\n");

    return 0;
}


