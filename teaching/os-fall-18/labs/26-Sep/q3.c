#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

volatile long long counter = 0;

typedef struct arguments {
    int number;
    char *s;
} ;

void *function_thread(void *x)
{
    struct arguments *args = (struct arguments *)x;
    printf("%s, %d \n", args->s, args->number);
    for (int i =0 ; i< args->number; i++)
    {
        counter++;
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    struct arguments a1, a2;
    a1.number = atoi(argv[1]);
    a1.s = "A";
    a2.number =  atoi(argv[1]);
    a2.s = "B";
    int rc1, rc2;
    printf("Inside main. Now creating the two threads\n");
    rc1 = pthread_create(&t1, NULL, function_thread, (void *)&a1);
    rc2 = pthread_create(&t2, NULL, function_thread, (void *)&a2);
    //sleep(0.05);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Exiting main\n");
    printf("Counter is: %lld \n", counter);

    return 0;
}


