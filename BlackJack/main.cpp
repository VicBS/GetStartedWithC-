#include <iostream>
#include "MontonCartas.h"
#include "Player.h"

using namespace std;

void on ()
{
    cout << "\t******** BLACK JACK ********" << endl << endl;
    cout << "\t1 - Play" <<endl;
    cout << "\t2 - Rules" << endl;
    cout << "\t3 - Exit" <<endl;
}

void test5()
{
    cout << "Test 5" << endl << endl;

    MontonCartas monton (1);
    monton.mezclar();
    monton.printMonton();

    int pos = 13;
    cout << "Posicion: " << pos << endl;

    cout << endl << "Sacamos dos cartas: " << endl;
    Carta* carta = monton.sacarCarta( pos );
    Carta* carta2 = monton.sacarCarta( pos );

    cout << "Carta 1 -> " << (*carta).num << (*carta).palo << endl ;
    cout << "Carta 2 -> " << (*carta2).num << (*carta2).palo << endl << endl;

    Player player (1, "Victor");
    cout << "Se las damos a " << player.getNombre() << endl;
    double puntuacion = player.addCarta(carta);
    puntuacion = player.addCarta(carta2);

    player.showHand();

    cout << endl << "Mostramos la puntuacion de " << player.getNombre() << endl;
    cout << puntuacion << " punto/s" << endl;

    cout << endl << "Limpiamos la mano de " << player.getNombre() << endl;
    player.limpiarMano();

    player.showHand();
}


void test6()
{
    cout << "Test 6" << endl << endl;

    MontonCartas monton (1);
    monton.printMonton();
}


int main()
{
    test6();
}
