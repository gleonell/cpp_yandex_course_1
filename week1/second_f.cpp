#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int a = 0;

    cin >> s;
    
    for (int i = 0; i <= (int)s.length(); ++i)
    {
        if (s[i] == 'f')
            a++;
        if (a == 2){
            cout << i;
            break;
        }
    }

    if (a == 0)
        cout << -2;
    else if (a == 1)
        cout << -1;
    
    return 0;
}