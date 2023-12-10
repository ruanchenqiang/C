#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "bsem.h"

bsem_t g_mtx;
uint64_t g_counter = 0;

void *count_task(void *ctx)
{
	for(int i = 0; i < 10000000; ++i)
	{
		bsem_wait(&g_mtx);
		
		++g_counter;

		bsem_post(&g_mtx);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	bsem_init(&g_mtx, 1);

	pthread_t count_thrd;
	pthread_t count_thrd2;
	pthread_t count_thrd3;

	pthread_create(&count_thrd, NULL, count_task, NULL);
	pthread_create(&count_thrd2, NULL, count_task, NULL);
	pthread_create(&count_thrd3, NULL, count_task, NULL);

	pthread_join(count_thrd, NULL);
	pthread_join(count_thrd2, NULL);
	pthread_join(count_thrd3, NULL);

	printf("g_counter=%"PRIu64"\n", g_counter);

	bsem_destroy(&g_mtx);

	while (1)
	{
		sleep(1);
	}

	return 0;
}