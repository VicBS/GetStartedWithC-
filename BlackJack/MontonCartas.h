#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Carta.h"

using namespace std;


class MontonCartas
{
    Carta *p; // this is our stack, a simple pointer. Yeah, amazing xD
    Carta *deleted ;

    void intercambiar(int pos1, int pos2);
    void eliminarCarta(int pos);

    public:
        MontonCartas();          // constructor that builds an empty Spanish card stack
        MontonCartas(int todas); // constructor that builds a complete Spanish card stack
        ~MontonCartas();

        MontonCartas& operator= (const MontonCartas& orig);

        void mezclar ();
        void insertarCarta (int n, char tipo);
        void printMonton ();

        int sizeMonton () const;
        int getNumeroCarta (int pos) const;
        char getPaloCarta (int pos) const;
        Carta* getCarta (int pos) ;
        Carta* sacarCarta (int pos) ;
};
