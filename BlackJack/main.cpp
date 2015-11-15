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

    int pos = 13;
    cout << endl << "Posicion: " << pos << endl;

    cout << endl << "Sacamos una carta: ";
    Carta* carta = monton.sacarCarta( pos );

    cout << (*carta).num << (*carta).palo << endl << endl;

    Player player (1, "Victor");
    cout << "Se la damos a " << player.getNombre() << endl;
    double puntuacion = player.addCarta(carta);

    cout<< endl << "Mostramos la mano de " << player.getNombre() << endl;
    player.showHand();

    cout << endl << "Mostramos la puntuacion de " << player.getNombre() << endl;
    cout << puntuacion << " punto/s" << endl << endl;

    cout << "Volvemos a mirar el monton" << endl;
    monton.printMonton();
}


void test3()
{
    MontonCartas monton (1);

    monton.printMonton();

    int pos = 13;
    cout << endl << "Posicion: " << pos << endl;

    cout << endl << "Sacamos dos cartas: " << endl;
    Carta* carta = monton.sacarCarta( pos );
    Carta* carta2 = monton.sacarCarta( pos );

    cout << "Carta 1 -> " << (*carta).num << (*carta).palo << endl << endl;
    cout << "Carta 2 -> " << (*carta2).num << (*carta2).palo << endl << endl;

    Player player (1, "Victor");
    cout << "Se las damos a " << player.getNombre() << endl;
    double puntuacion = player.addCarta(carta);
    puntuacion = player.addCarta(carta2);

    cout<< endl << "Mostramos la mano de " << player.getNombre() << endl;
    player.showHand();

    cout << endl << "Mostramos la puntuacion de " << player.getNombre() << endl;
    cout << puntuacion << " punto/s" << endl << endl;

    cout << "Volvemos a mirar el monton" << endl;
    monton.printMonton();
}


void test4()
{
    cout << "Test 4" << endl << endl;

    MontonCartas monton (1);

    cout << "Monton ordenado" << endl;
    monton.printMonton();

    cout << "Monton mezclado" << endl;
    monton.mezclar();
    monton.printMonton();

    int pos = 13;
    cout << endl << "Posicion: " << pos << endl;

    cout << endl << "Sacamos dos cartas: " << endl;
    Carta* carta = monton.sacarCarta( pos );
    Carta* carta2 = monton.sacarCarta( pos );

    cout << "Carta 1 -> " << (*carta).num << (*carta).palo << endl ;
    cout << "Carta 2 -> " << (*carta2).num << (*carta2).palo << endl << endl;

    Player player (1, "Victor");
    cout << "Se las damos a " << player.getNombre() << endl;
    double puntuacion = player.addCarta(carta);
    puntuacion = player.addCarta(carta2);

    cout<< endl << "Mostramos la mano de " << player.getNombre() << endl;
    player.showHand();

    cout << endl << "Mostramos la puntuacion de " << player.getNombre() << endl;
    cout << puntuacion << " punto/s" << endl << endl;

    cout << "Volvemos a mirar el monton" << endl;
    monton.printMonton();


    cout << endl << "Limpiamos la mano de " << player.getNombre() << endl;
    player.limpiarMano();
    player.showHand();
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
