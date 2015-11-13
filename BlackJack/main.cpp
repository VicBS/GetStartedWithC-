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
    // monton.mezclar();

    cout << "Mostramos el monton barajado" << endl << endl;
    monton.printMonton();

    cout << endl << "Sacamos una carta: " ;
    Carta *unaCarta = monton.sacarCarta(0);
    cout << (*unaCarta).num << (*unaCarta).palo << endl << "Y se la damos al jugador" << endl;


    Player player (1,"Alfonso");
    player.addCarta(unaCarta);

    cout<< endl << "Ahora mostramos la mano del jugador" << endl;
    player.showHand();


}

int main()
{
    test2();
}
