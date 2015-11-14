#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Carta.h"
#include "MontonCartas.h"

using namespace std;

class Banca
{
    MontonCartas* monton ;

    void init();

    public:

        Banca();
        ~Banca();

        Carta* darCarta();
        void reiniciar();
};
