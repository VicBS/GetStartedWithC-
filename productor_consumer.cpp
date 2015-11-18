/**

   This is an easy example of how to use semaphores in C++.
   Basically, we have two threads, one to write and another 
   to read, and the only thing they do is write simple long
   values and read them, showing messages on the terminal.

*/

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std ;


sem_t puede_escribir, puede_leer, mutex ;    // semaphores for: can write, can read, exclusion
unsigned long valor_compartido ;             // shared value
const unsigned long num_iter = 10 ;          // number of iterations


void* escribir( void* p ) 
{   
   unsigned long contador = 0 ;

   for( unsigned long i = 0 ; i < num_iter ; i++ )
   {  
      contador = contador + 1 ;

      sem_wait( &puede_escribir ) ;
      valor_compartido = contador ;
      sem_post( &puede_leer ) ;

      sem_wait( &mutex ) ;
      cout << "Written value ==> " << contador << endl << flush ;
      sem_post( &mutex ) ;
   }
   return NULL ;
}


void* leer( void* p ) 
{   
   unsigned long  valor_leido ;

   for( unsigned long i = 0 ; i < num_iter ; i++ )
   {  
      sem_wait( &puede_leer ) ;
      valor_leido = valor_compartido ;
      sem_post( &puede_escribir ) ;

      sem_wait( &mutex ) ;
      cout << "                                Readed value ==> " << valor_leido << endl << flush ;
      sem_post( &mutex ) ;
   }
   return NULL ;
}


int main()
{
   // these are our threads: one to write and another to read
   pthread_t hebra_escritora, hebra_lectora ;


   // init the semaphores

   sem_init( &mutex, 0, 1 ) ;          // EM sempahore init to 1
   sem_init( &puede_escribir, 0, 1);   // at the beginning we can write
   sem_init( &puede_leer,     0, 0);   // at the beginning we can not read (there's nothing written!)


   // init the threads
   pthread_create( &hebra_escritora, NULL, escribir, NULL );
   pthread_create( &hebra_lectora,   NULL, leer,     NULL );

   pthread_join( hebra_escritora, NULL ) ;
   pthread_join( hebra_lectora,   NULL ) ;

   // destroy the semaphores
   sem_destroy( &puede_escribir );
   sem_destroy( &puede_leer );      
}
