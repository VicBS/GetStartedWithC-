#include <iostream>
#include "MontonCartas.h"
#include "Player.h"

using namespace std;

int on ()
{
    cout << "\t******** BLACK JACK ********" << endl << endl;
    cout << "\t1 - Play" <<endl;
    cout << "\t2 - Rules" << endl;
    cout << "\t3 - Exit" <<endl;

    int op ;
    cin >> op;
    return op;
}


void option1()
{
    MontonCartas monton (1);
    monton.mezclar();

    cout << "How many players are going to play? (MAX 10) " ;
    int numPlayers ;
    cin >> numPlayers;
    cout << endl;


}

void option2(){}

void option3(){}

void optionChooser (int op)
{
    switch(op)
    {
        case 1:
        {
            option1();
        }
        break;

        case 2:{ option2(); }break;
        case 3:{ option3(); }break;

        default:{ cout << "Invalid option" << endl; }
    }
}


int main()
{
    Player* jugadores [5];
}
