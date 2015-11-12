#include <iostream>
#include <string>

using namespace std;

/**

    We start with a code made only with 0's and 1's. In the code, each sequence
    of 1's means to be a number depending on the length of the sequence.
    For instance, 011101100001 would have the numbers 3, 2 and 1.

    At this point, we have to multiply each number to obtain a final number.

*/

int main()
{
    cout <<"Enter the code:"<<endl;
    string code ;
    getline(cin,code);

    int one_count = 0;
    int finalNumber = 1;

    for(int i=0; i<code.size(); ++i)
    {
        switch(code.at(i))
        {
            case '0':
            {
                if(one_count > 0)
                {
                    finalNumber *= one_count ;
                    one_count = 0;
                }
            }break;

            case '1':
            {
                one_count ++ ;
            }break;
        }
    }

    cout << "Final Number: " << finalNumber << endl;
}
