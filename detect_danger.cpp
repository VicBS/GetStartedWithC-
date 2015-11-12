#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // x0 y0 z0 are coordinates in the origin
	double radius, x0, y0, z0=0;
	cout<<"Please introduce geometric data to build our radar (radius x y):"<<endl;
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


	// This var indicates if the target is a land target or an air target.
	// Specified by the user.
	char letra;

	do {
        cout << "What type of target is it, T (land), A (air) or D (none)?: " ;
		cin >> letra;
		cout << endl;

		if(letra=='T')
        {
            cout << "Land target detected" << endl;
            cout << "Please give me its XY coordinates: ";
			cin >> xt >> yt;

			perimT = pow(xt-x0,2)+pow(yt-y0,2); // calculate the action perimeter

			if(perimT < radius)
            {
                cout<<"ALERT! LAND THREAT!"<<endl;
			}else
                cout << "It's OK" <<endl;
		}

		if(letra=='A')
        {
            cout << "Air target detected" << endl;
            cout << "Please give me its XYZ coordinates: ";

			cin >> xa >> ya >> za;

			perimA=pow(xa-x0,2)+pow(ya-y0,2)+za*za;

			if(perimA < radius)
            {
				cout<<"ALERT! AIR THREAT!"<<endl;
			}else
                cout << "It's OK" <<endl;
		}

		if(letra=='D')
        {
			cout<<"None Threat"<<endl;
			cout << "Good Bye" << endl;
		}

		cout << endl;

	} while( letra != 'D' );
}
