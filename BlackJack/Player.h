#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Carta.h"

using namespace std;

class Player
{
    int ID ;
    Carta* mano ;
    Carta* ultimaCarta;
    string nombre ;
    double mPuntos ;

    double sumarPuntos (double pts);

    public:

        Player(int id, string name);
        ~Player();

        void showHand () ;

        int getID () const ;
        string getNombre () const ;
        double getPuntos () const ;

        /**
            return Los puntos que tiene el jugador al añadir esa carta.
        */
        double addCarta (Carta* carta);
};
