#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>    // std::sort

using namespace std;

void printMyVector (vector<int> &v)
{
    for(int i=0; i<v.size();i++)
        cout<< v.at(i) << " ";
}

int main()
{
    int tmn;
    cout<<"Tell me a vector size: ";
    cin>>tmn;

    vector<int> v(tmn); // create an empty vector
    int elem;

    for(int i=0; i<v.size(); i++)
    {
        cout << "Give me an int number: ";
        cin >> elem;
        v.at(i) = elem;
    }

    cout << endl;
    cout << "This is your vector:" << endl;
    printMyVector(v);
    cout << endl;

    sort( v.begin(), v.end());

    cout<<endl;
    cout<< "This is your sorted vector:"<< endl;
    printMyVector(v);
    cout << endl;
}
