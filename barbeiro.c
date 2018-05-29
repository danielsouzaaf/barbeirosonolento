#include <stdio.h>
#include <semaphore.h>

sem_t mutex = 1;
sem_t customers = 1;
sem_t barbers = 1;

void barber(void) 
{
	while (1 == 1) {
		down(&customers);
		down(&mutex);
		--waiting;
		up(&barbers);
		up(&mutex);
		cortar_cabelo;
}

void customer(void)
{
	down(&mutex);
	if (waiting < CHAIRS) {
		++waiting;
		up(&customers);
		up(&mutex);
		down(&barbers);
		receber_corte;
	} else up(&mutex);
}
