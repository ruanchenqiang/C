#include <stdio.h>
#include <stdlib.h>

#include "bsem.h"

void bsem_init(bsem_t* bsem, int value)
{
    if(value < 0 || value > 1)
    {
        fprintf(stderr, "bsem_init(): binary semaphore can take only values 0 or 1\n");
        exit(1);
    }

    pthread_mutex_init(&(bsem->mutex), NULL);
    pthread_cond_init(&(bsem->cond), NULL);
    bsem->value = value;
}

void bsem_destroy(bsem_t* bsem)
{
    pthread_mutex_destroy(&(bsem->mutex));
    pthread_cond_destroy(&(bsem->cond));
    bsem->value = 0;
}

void bsem_wait(bsem_t* bsem)
{
    pthread_mutex_lock(&(bsem->mutex));

    while(bsem->value == 0)
    {
        pthread_cond_wait(&(bsem->cond), &(bsem->mutex));
    }
    bsem->value = 0;

    pthread_mutex_unlock(&(bsem->mutex));
}

void bsem_post(bsem_t* bsem)
{
    pthread_mutex_lock(&(bsem->mutex));

    bsem->value = 1;

    pthread_cond_signal(&(bsem->cond));
    pthread_mutex_unlock(&(bsem->mutex));
}

void bsem_post_all(bsem_t* bsem)
{
    pthread_mutex_lock(&(bsem->mutex));

    bsem->value = 1;

    pthread_cond_broadcast(&(bsem->cond));
    pthread_mutex_unlock(&(bsem->mutex));
}
