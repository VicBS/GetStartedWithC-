#include <iostream>

using namespace std;

#ifndef Included_Carta_H
#define Included_Carta_H

struct Carta
{
    char palo;
    int num;
    Carta *sig; // this pointer is for iterate through the whole card stack
};

#endif
