/**
	SMOKERS - C++ semaphores

	Each smoker is represented by f1, f2 and f3:
	- f1 has tobacco
	- f2 has paper
	- f3 has matches

	Representation of pairs of ingredients that
	the shop assistant put on its shop:
	0 -> paper and matches
	1 -> matches and tobacco
	2 -> tobacco and paper

	If one smoker wants to smoke, he needs to have
	the three mentioned ingredients. At time, each
	smoker has only 1 ingredient, so they have to
	go to the shop to ask for the rest of ingredients.
*/

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h> 
using namespace std ;


const long NFUM = 3; 		// number of smokers
sem_t estanquer, fum[NFUM];	// semaphores: 'estangquer' is the shop assistant, and 'fum' are the smokers


/**
	It's the action of a smoker
*/
void fumar() 
{ 
	sleep (rand() % 5); 
}


/**
	Method that performs the shop assistant.
*/
void* Estanquero (void * arg)
{
	int ingredientes;

	while(true) // the shop assistat is always doing something
	{
		sem_wait( &estanquer ); 

		ingredientes = rand() % 3; // we choose one pair of ingredient

		if(ingredientes == 0)
		{
			cout<<"SA: Putting paper and matches..."<<endl;
			sem_post( &(fum[ ingredientes ]) );
		}
		else if(ingredientes == 1)
		{
			cout<<"SA: Putting matches and tobacco..."<<endl;
			sem_post( &(fum[ ingredientes ]) );
		}
		else if(ingredientes == 2)
		{
			cout<<"SA: Putting paper and tobacco..."<<endl;
			sem_post( &(fum[ ingredientes ]) );
		}
	}
}


/**
	Smokers perform this method.
	var t is the id number of each smoker.
*/
void* fumador (void* t)
{
	while(true)
	{
		sem_wait( &(fum[ (unsigned long)(t)]) );
		cout<< "Smoker "<< (unsigned long) t <<" starts to somke."<<endl;
		sem_post( &estanquer );

		fumar();

		cout<< "Smoker "<<(unsigned long) t <<" waits for ingredients."<<endl;
	}
}


int main()
{
	srand(time(NULL));

	// Init of semaphores
	sem_init( &estanquer, 0, 1);
	for(int i=0; i<NFUM; i++)
		sem_init( &(fum[i]), 0, 0);

	// Threads init
	pthread_t est, hebras[NFUM];

	pthread_create( &est, NULL, Estanquero, NULL );
	for(long i=0; i<NFUM; i++)
		pthread_create( &(hebras[i]), NULL, fumador, (void *) i );

	// wait for the threads
	pthread_join( est, NULL );
	for(long i=0; i<NFUM; i++)
		pthread_join( hebras[i], NULL );

	// destroy semaphores
	sem_destroy( &estanquer );
	for(int i=0; i<NFUM; i++)
		sem_destroy( &(fum[i]) );

}
