#include <iostream>
#include "par.h"

using namespace std;

int main()
{
	par<int,char> uno;
	par<int,char> dos;

	int a;
	cout<< "Put an int number: ";
	cin >> a;

	char b;
	cout<< "Now put a char: ";
	cin >> b;

	uno.First() = a;
	uno.Second() = b;

	cout<< 2*uno.First() <<endl;
	cout<< uno.First() <<endl;

	dos = uno;
	cout<<"Segundo par: "<<endl;
	cout<< dos.First() << " " << dos.Second() <<endl;

	par<double,bool> tres (3.69,true);
	cout<<"Tercer par: "<<endl;
	cout<< tres.First() << " "<< tres.Second() <<endl;
}
