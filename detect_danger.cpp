#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // x0 y0 z0 are coordinates in the origin
	double radius, x0, y0, z0=0;
	cout<<"Please introduce geometric data to build our scanner (radius x y):"<<endl;
	cin>> radius >> x0 >> y0;
	cout<<endl;

	radius = radius*radius;

    // xt : refers to the x coordinate of a dangerous land (in Spanish --> terrestre) target
    // yt : refers to the y coordinate of a dangerous land target
    // xa : refers to the x coordinate of a dangerous air target
    // ya : refers to the y coordinate of a dangerous air target
    // za : refers to the z coordinate of a dangerous air target
    // perimT : perimeter of action of the land target
    // perimA : perimeter of action of the air target
	double xt, yt, xa, ya, za, perimT, perimA;

	// Says if the target is dangerous or not.
	// If the target is inside our area, of course it is. On the other hand, no.
	bool amenaza=false;

	// This var
	char letra;

	do{
        cout << "What type of target is it? (T or A)"
		cin>>letra;
		if(letra=='T' && !amenaza){

			cin>>xt>>yt;
			perimT=pow(xt-x0,2)+pow(yt-y0,2);

			if(perimT<r){
					cout<<"AMENAZA TERRESTRE."<<endl;
					amenaza=true;
			}
		}

		if(letra=='A' && !amenaza){

			cin>>xa>>ya>>za;
			perimA=pow(xa-x0,2)+pow(ya-y0,2)+za*za;

			if(perimA<r){
				cout<<"AMENAZA AEREA."<<endl;
				amenaza=true;
			}
		}

		if(letra=='D' && !amenaza){
			cout<<"NINGUNA AMENAZA."<<endl;
			amenaza=true;
		}
	}while(letra!='D'||amenaza!=true);
}
