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

void test1()
{
    MontonCartas monton (1);

    monton.printMonton();

    cout << endl << "Sacamos una carta: ";
    Carta* carta = monton.sacarCarta(12);

    cout << (*carta).num << (*carta).palo << endl << endl;
    if((*carta).sig != 0)
        cout << "Apunta a otra carta" << endl << endl;
    else
        cout << "No apunta a ninguna carta" << endl << endl;


    monton.printMonton();
}

void test2 ()
{
    MontonCartas monton (1);

    monton.printMonton();

    cout << endl << "Sacamos una carta: ";
    Carta* carta = monton.sacarCarta(0);

    cout << (*carta).num << (*carta).palo << endl << endl;
    if((*carta).sig != 0)
        cout << "Apunta a otra carta" << endl << endl;
    else
        cout << "No apunta a ninguna carta" << endl << endl;

    Player player (1, "Victor");
    cout << "Se la damos a " << player.getNombre() << endl;
    double puntuacion = player.addCarta(carta);

    cout<< endl << "Mostramos la mano de " << player.getNombre() << endl;
    player.showHand();

    cout << endl << "Mostramos la puntuacion de " << player.getNombre() << endl;
    cout << puntuacion << endl << endl;

    cout << "Volvemos a mirar el monton" << endl;
    monton.printMonton();
}

int main()
{
    test2();
}
