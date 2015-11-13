#include "MontonCartas.h"

using namespace std;

MontonCartas::MontonCartas()
{
    p = 0;
}

MontonCartas::MontonCartas(int todas)
{
    char pal [] = {'O','C','B','E'};

    Carta *aux;
    bool primeraCarta = true;


    for(int i=0; i<4; i++)
    {
        char a = pal[3-i];
        aux = new Carta;

        for(int j=0; j<12; j++)
        {
            (*aux).palo = a;
            (*aux).num = 12-j;

            if(primeraCarta)
            {
                (*aux).sig = 0;
                primeraCarta = false;
            }else
                (*aux).sig = p;

            p = aux;

            aux = new Carta;
        }
    }
}

MontonCartas::~MontonCartas()
{
    Carta *aux;

    aux = (*p).sig;
    while(aux != 0)
    {
        delete p;
        p = aux;
        aux = (*aux).sig;
    }
    delete p;
}

MontonCartas& MontonCartas::operator= (const MontonCartas& orig)
{
    if(&orig != this)
    {
        if(this->p != 0)
        {
            Carta *Claus;
            Claus=this->p;
            while(Claus != 0)
            {
                Claus = (*Claus).sig;
                delete p;
                p = Claus;
            }
        }

        Carta *aux, *aux2;
        aux = this->p;
        aux2 = orig.p;
        bool primeraCarta = true;

        while(aux2 != 0)
        {
            aux = new Carta;

            if(primeraCarta)
            {
                (*aux).sig = 0;
                primeraCarta = false;
            }else
                (*aux).sig = p;

            p = aux;

            aux2 = (*aux2).sig;
        }

        //copiamos datos
        aux = this->p;
        aux2 = orig.p;
        while(aux2 != 0)
        {
            (*aux).num = (*aux2).num;
            (*aux).palo = (*aux2).palo;

            aux = (*aux).sig;
            aux2 = (*aux2).sig;
        }
    }
    return *this;
}

void MontonCartas::mezclar()
{
    Carta *aux;
    aux = p;
    int tam=0;
    for(tam; aux != 0; tam++)
        aux = (*aux).sig;

    Carta *aux2;

    for(int i=0; i<tam; i++)
    {
        aux = p;
        aux2 = p;

        srand(time(0));
        int a = rand()%tam;
        int b = rand()%tam;

        Carta *aux2a;
        Carta *auxan;
        aux2a = p;
        auxan = p;

        for(int h=0; h<a; h++)
            aux = (*aux).sig;
        for(int h=0; h<a-1; h++)
            auxan = (*auxan).sig;
        for(int h=0; h<b; h++)
            aux2 = (*aux2).sig;
        for(int h=0; h<b-1; h++)
            aux2a = (*aux2a).sig;

        if( (&aux != &aux2) && (&aux != &auxan) && (&aux2 != &aux2a) )
        {
            (*aux).sig = (*aux2).sig;
            (*aux2).sig = aux2a;
            (*aux2a).sig = aux;
            (*auxan).sig = aux2;
        }
        else if( (&aux == &auxan) || (&aux2 == &aux2a) )
        {//que sera cuando estén al principio

            (*aux).sig = (*aux2).sig;
            (*aux2).sig = aux2a;
            (*aux2a).sig = aux;
            p = aux2;
        }
    }
}

void MontonCartas::eliminarCarta (int pos)
{
    Carta *aux;
    Carta *aux2;
    aux = p;
    aux2 = p;

    for(int i=0; i<pos; i++)
        aux = (*aux).sig;
    for(int i=0; i<pos-1; i++)
        aux2 = (*aux2).sig;

    (*aux2).sig = (*aux).sig;

    delete aux;
}

int MontonCartas::getNumeroCarta (int pos) const
{
    Carta *aux = p;
    for(int i=0; i<pos; i++)
        aux = (*aux).sig;

    return (*aux).num;
}

char MontonCartas::getPaloCarta (int pos) const
{
    Carta *aux;
    aux = p;
    for(int i=0; i<pos; i++)
        aux = (*aux).sig;

    return (*aux).palo;
}

void MontonCartas::insertarCarta (int n, char tipo)
{
    //1º buscamos alguna carta igual en numero y palo
    bool encontrada = false;
    Carta *aux;
    aux = p;

    while(aux!=0 && !encontrada)
    {
        if((*aux).num == n && (*aux).palo == tipo)
        encontrada = true;
        aux = (*aux).sig;
    }

    //ahora la añadimos al final
    if(!encontrada)
    {
        aux = p;
        //movemos aux hasta el ultimo lugar
        while((*aux).sig != 0)
        {
            aux = (*aux).sig;
        }

        //creamos la nueva carta
        Carta *aux2 = new Carta;
        (*aux2).sig = 0;
        (*aux2).num = n;
        (*aux2).palo = tipo;

        (*aux).sig = aux2;
    }else
        cout<<"No se pudo añadir porque ya existe."<<endl;
}

int MontonCartas::sizeMonton() const
{
    int tam=0;
    Carta *aux;
    aux = p;
    for(tam; aux != 0; tam++)
        aux = (*aux).sig;

    return tam;
}

Carta* MontonCartas::getCarta(int pos)
{
    Carta* laCarta = p;

    for(int i=0; i<pos; i++)
        laCarta = (*laCarta).sig;

    return laCarta;
}


Carta* MontonCartas::sacarCarta(int pos)
{
    Carta * laCarta = getCarta(pos);
    eliminarCarta(pos);
    (*laCarta).sig = 0;
    return laCarta;
}


void MontonCartas::printMonton()
{
    Carta * aux = p;
    char palo = '#';

    while( aux != 0 )
    {
        if(palo == '#')
            palo = (*aux).palo ;

        if(palo != (*aux).palo)
        {
            palo = (*aux).palo ;
            cout << endl;
        }

        cout << (*aux).num << (*aux).palo << " ";

        aux = (*aux).sig;
    }
    cout << endl;
}
