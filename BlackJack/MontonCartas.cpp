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

void MontonCartas::intercambiar(int pos1, int pos2)
{
    Carta* aux1;
    Carta* aux2 ;
    aux1 = p;
    aux2 = p;

    for(int i=0; i<pos1; ++i)
        aux1 = (*aux1).sig;

    for(int i=0; i<pos2; ++i)
        aux2 = (*aux2).sig;

    int numAux = (*aux1).num ;
    char paloAux = aux1->palo ;

    aux1->num = aux2->num;
    aux1->palo = aux2->palo;

    aux2->num = numAux;
    aux2->palo = paloAux;
}


Carta* MontonCartas::getCarta(int pos)
{
    Carta* laCarta = p;

    for(int i=0; i<pos; i++)
        laCarta = (*laCarta).sig;

    return laCarta;
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


int MontonCartas::sizeMonton() const
{
    int tam=0;
    Carta *aux;
    aux = p;
    for(tam; aux != 0; tam++)
        aux = (*aux).sig;

    return tam;
}


void MontonCartas::eliminarCarta (int pos)
{
    int tam = sizeMonton();
    Carta* aux ;
    aux = p;

    if(pos == 0)
    {
        p = p->sig;
    }
    else if(pos == tam-1)
    {
        Carta* aux2 ;
        aux2 = p;

        for(int i=0; i<pos; ++i)
            aux = aux->sig;

        for(int i=0; i<pos-1; ++i)
            aux2 = aux2->sig;

        aux2->sig = 0;
    }
    else
    {
        Carta* aux2 ;
        aux2 = p;

        for(int i=0; i<pos; ++i)
            aux = aux->sig;

        for(int i=0; i<pos-1; ++i)
            aux2 = aux2->sig;

        aux2->sig = aux->sig;
        aux->sig = 0;
    }

    delete aux;

    /*
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
    */
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




void MontonCartas::mezclar()
{
    // jajajajajajajajajajaaj
    int tam = sizeMonton();

    for(int i=0; i<tam; i++)
    {
        srand(time(0));
        int pos1 = rand()%tam;
        int pos2 = rand()%tam;

        intercambiar(pos1,pos2);
    }
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
