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


bool finPartida (Player* ganador)
{
    cout << "GAME OVER!!" << endl;
    cout << "Winner is player..." << endl;
    cout << "<<<< " << ganador->getNombre() << " >>>>" << endl;
    cout << "<<<< " << ganador->getPuntos() << " points >>>>" << endl;

    do{
        cout << endl << endl << "Play again? (Y/N): " ;
        char opt ;
        cin >> opt ;

        switch(opt)
        {
            case 'Y':
            case 'y':
                cout << endl;
                return true;
            break;

            case 'N':
            case 'n':
                cout << endl;
                return false;
            break;

            default:
                cout << "Invalid option" << endl;
        }
    }while(true);
}


bool option1()
{
    int numPlayers ;
    do {
        cout << "How many players are going to play? (MAX 10) " ;
        cin >> numPlayers;
        cout << endl;
    } while( numPlayers < 2 || numPlayers > 10);

    Player* jugadores [numPlayers];
    for(int i=0; i< numPlayers; ++i)
    {
        cout << "Name: ";
        string name ;
        cin >> name;

        jugadores[i] = new Player(i,name);
    }
    cout << endl;

    bool fin = false;
    int posGanador = -1;

    MontonCartas monton (1);
    monton.mezclar();

    int ronda = 1;
    int eliminados = 0;

    do
    {
        cout << "Round " << ronda << endl << endl;

        if(ronda == 1)
        {
            for(int i=0; i<numPlayers; ++i)
            {
                jugadores[i]->addCarta(monton.sacarCarta(0));
                jugadores[i]->showHand();

                if(jugadores[i]->isEliminado())
                {
                    eliminados ++ ;
                    cout << "Player " << jugadores[i]->getNombre() << " has lost with " << jugadores[i]->getPuntos() << " points!!" << endl;
                    if( eliminados == numPlayers -1 )
                    {
                        cout << "WE ALREADY HAVE A WINNER..." << endl;
                        fin = true;
                    }
                }

                cout << endl;
            }
        }
        else
        {
            for(int i=0; i<numPlayers; ++i)
            {
                if(!jugadores[i]->isEliminado())
                {
                    char respuesta ;
                    do{
                        jugadores[i]->showHand();
                        cout << "Player " << jugadores[i]->getNombre() ;
                        cout << ", want another card? (Y/N): " ;
                        cin >> respuesta;
                    }
                    while( respuesta != 'Y' && respuesta != 'y' && respuesta != 'N' && respuesta != 'n' );

                    if(respuesta == 'Y' || respuesta == 'y')
                    {
                        jugadores[i]->addCarta(monton.sacarCarta(0));

                        if(jugadores[i]->isEliminado())
                        {
                            eliminados ++ ;
                            cout << "Player " << jugadores[i]->getNombre() << " has lost with " << jugadores[i]->getPuntos() << " points!!" << endl;
                            if( eliminados == numPlayers -1 )
                            {
                                cout << "WE ALREADY HAVE A WINNER..." << endl;
                                fin = true;
                                break;
                            }
                        }
                        else if(jugadores[i]->getPuntos() == 7.5)
                        {
                            cout << "WE ALREADY HAVE A WINNER" << endl;
                            fin = true;
                            posGanador = i;
                            return finPartida(jugadores[posGanador]);
                        }

                    }else
                        cout << "Player " << jugadores[i]->getNombre() << " doesn't want a card" <<endl;

                }else
                    cout << "Player " << jugadores[i]->getNombre() << " has lost" <<endl;

                cout << endl;
            }

        }
        ronda ++ ;

        char basura;
        cout << "Click '-' to continue" ;
        cin >> basura ;
        cout << endl;
    }
    while(!fin);

    // buscamos al ganador...
    for(int x = 0; x < numPlayers; ++x)
    {
        if(!jugadores[x]->isEliminado())
        {
            posGanador = x ;
            break;
        }
    }

    return finPartida(jugadores[posGanador]);
}

bool option2()
{
    cout << endl;
    cout << "RULES" << endl;

    cout << endl;
    cout << "Each player has to obtain " << endl;
    cout << "the highest score without" <<endl;
    cout << "get over 7.5 points." << endl << endl;
    cout << "Cards 10, 11 and 12" << endl;
    cout << "add 0.5 points, while" << endl;
    cout << "the rest of the cards" << endl;
    cout << "add 1 point." << endl;
    cout << endl << endl << endl;

    return true;
}

bool option3()
{
    cout << "See you next time!" <<endl;
    return false;
}

bool optionChooser (int op)
{
    bool continuar ;
    switch(op)
    {
        case 1:
        {
            continuar = option1();
        }
        break;

        case 2:{ continuar = option2(); }break;
        case 3:{ continuar = option3(); }break;

        default:{ continuar=true; cout << "Invalid option" << endl; }
    }
    return continuar;
}


int main()
{
    bool continuar = true;
    do{
        continuar = optionChooser( on() );
    }while(continuar);
}
