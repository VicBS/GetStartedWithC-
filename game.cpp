#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    int n, x;
    int a;
    bool cerrar=true;
    srand(time(0));

    do
    {
        cout<<"\t+++++ GUESS +++++"<<endl<<endl;
        cout<<"\t- 1. Play\n";
        cout<<"\t- 2. Exit\n"<<endl<<endl;
        cout<<"\t- Choose an option: ";
        cin>>a;
        cout<<endl;

        switch(a)
        {
            case 1:
                cout<<"Set a max number: ";
                int max;
                cin>>max;

                n=rand()%max+1;

                cout<<endl;
                cout<<"I've thought a number. Do you know what is it?" <<endl;

                do{
                    cin>>x;

                    if(x>n)
                        cout<<"Incorrect. Number is smaller\n";
                    if(x<n)
                        cout<<"Incorrect. Number is bigger\n";
                    if(x==n)
                        cout<<"GOTCHA!"<<endl;

                    cout<<endl;
                }while(x!=n);

            break;

            case 2:
                cerrar=false;
            break;

            default:
                cout<<"Opcion no valida"<<endl;
                cout<<endl;
        }

    }while(cerrar==true);
}
