#include <iostream>
#include <string>

using namespace std;

int main()
{
    string one, two, free3;

    cin >> one >> two >> free3;
    
    if (one <= two && one <= free3)
        cout << one;
    else if (two <= one && two <= free3)
        cout << two;
    else
        cout << free3;
    
    return 0;
}