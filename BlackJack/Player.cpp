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
    ultimaCarta = 0;
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
    cout << this->nombre << ": la carta que me habeis dado es " ;
    cout << carta->num << carta->palo << endl;

    if(mano == 0)
    {
        mano = new Carta;
        ultimaCarta = mano;

        mano->num = carta->num;
        mano->palo = carta->palo;
        mano->sig = 0;
    }
    else
    {
        (*ultimaCarta).sig =  new Carta;
        ultimaCarta = (*ultimaCarta).sig;

        ultimaCarta->num = carta->num;
        ultimaCarta->palo = carta->palo;
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


void Player::limpiarMano()
{
    Carta* aux ;

    while(mano != ultimaCarta)
    {
        aux = mano ;
        mano = aux->sig;
        aux->sig = 0;
        delete aux;
    }

    ultimaCarta = 0;
    aux = 0;
    mano = new Carta;
    delete mano;

}
