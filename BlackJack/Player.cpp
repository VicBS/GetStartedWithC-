#include "Player.h"

using namespace std;

Player::Player(int id, string name)
{
    this->ID = id;
    this->nombre = name;
    this->mPuntos = 0;

    mano = 0;
    ultimaCarta = 0;
}

Player::~Player()
{
    Carta *aux;

    aux = (*mano).sig;
    while(aux != 0)
    {
        delete mano;
        mano = aux;
        aux = (*aux).sig;
    }
    delete mano;
}

double Player::sumarPuntos(double pts)
{
    mPuntos += pts ;
    return mPuntos;
}

int Player::getID() const
{
    return ID;
}


void Player::showHand()
{
    Carta* aux = mano ;

    cout << "Mano del jugador " << nombre << endl;
    while(aux != 0)
    {
        cout << (*aux).num << (*aux).palo << " ";
        aux = (*aux).sig;
    }
    cout << endl;
}


string Player::getNombre() const
{
    return nombre;
}


double Player::getPuntos() const
{
    return mPuntos;
}


double Player::addCarta(Carta* carta)
{
    if(mano == 0)
    {
        mano = carta;
        ultimaCarta = carta;
        (*mano).sig = 0;
    }
    else
    {
        (*ultimaCarta).sig = carta;
        ultimaCarta = (*ultimaCarta).sig;
        (*ultimaCarta).sig = 0;
    }

    int numero = (*ultimaCarta).num ;
    double pts ;
    if(numero == 10 || numero == 11 || numero == 12)
    {
        pts = 0.5;
    }else
        pts = (double)numero;

    return sumarPuntos(pts);
}
