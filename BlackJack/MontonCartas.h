#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Carta {
    char palo;
    int num;
    Carta *sig; // this pointer is for iterate through the whole card stack
};

class MontonCartas
{
    Carta *p; // this is our stack, a simple pointer. Yeah, amazing xD

    public:
        MontonCartas();          // constructor that builds an empty Spanish card stack
        MontonCartas(int todas); // constructor that builds a complete Spanish card stack
        ~MontonCartas();

        MontonCartas& operator= (const MontonCartas& orig);

        void mezclar ();
        void insertarCarta (int n, char tipo);
        void eliminarCarta(int pos);
        void printMonton ();

        int sizeMonton () const;
        int getNumeroCarta (int pos) const;
        char getPaloCarta (int pos) const;
        Carta* getCarta (int pos) ;
};
