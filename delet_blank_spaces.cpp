#include <iostream>
#include <string>

using namespace std;

/**
    This code erase blank spaces of a statement given by the user.
    After that, mentions the count of blank spaces that have been erased.
*/

int main()
{
	string s;
	cout << "DELETE BLANK SPACES" << endl;
	cout << "Input a phrase: " ;
	getline(cin,s); // read one line
	cout << endl;

	int tmn = s.size(); // save the length of the string
    int blank_count = 0;

	for(int a=0; a<s.size(); a++)
		if( s.at(a)==' ' )
        {
			s.erase(a,1);
			blank_count ++ ;
		}

	cout<<s<<endl;
	cout << "Deleted blank spaces: " << blank_count << endl;
	cout<<endl;
}
