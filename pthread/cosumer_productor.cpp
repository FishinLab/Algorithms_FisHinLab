#include <iostream>
#include <pthread.h>

#define MAXLN 10

pthread_cond_t cond_t;
pthread_mutex_t mutex_t;

int product = 0;

void* producer(void* arg)
{
    pthread_mutex_lock(&mutex_t);
    while(product > 0){
        pthread_cond_wait(&cond_t, &mutex_t);
    }
    while(product <= MAXLN){
        product++;
        printf("Producor: %d\n", product);
    }
    pthread_cond_signal(&cond_t);
    pthread_mutex_unlock(&mutex_t);
}

void* consumer(void* arg)
{
    pthread_mutex_lock(&mutex_t);
    while(!(product > 0)){
        pthread_cond_wait(&cond_t, &mutex_t);
    }
    while(product > 0){
        product--;
        printf("Consumer: %d\n", product);
    }
    pthread_cond_signal(&cond_t);
    pthread_mutex_unlock(&mutex_t);
}

int main()
{
    pthread_mutex_init(&mutex_t, NULL);
    pthread_cond_init(&cond_t, NULL);

    pthread_t t[2];
    pthread_create(&t[0], NULL, producer, NULL);
    pthread_create(&t[1], NULL, consumer, NULL);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    pthread_cond_destroy(&cond_t);
    pthread_mutex_destroy(&mutex_t);
}
