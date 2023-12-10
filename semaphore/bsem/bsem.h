#ifndef BSEM_H
#define BSEM_H

#include <pthread.h>

typedef struct bsem_t
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;
} bsem_t;

void bsem_init(bsem_t* bsem, int value);
void bsem_destroy(bsem_t* bsem);
void bsem_wait(bsem_t* bsem);
void bsem_post(bsem_t* bsem);
void bsem_post_all(bsem_t* bsem);

#endif