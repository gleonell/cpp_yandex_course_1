#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    vector <int> bin;

    cin >> a;
    while (a > 0)
    {
        if (a % 2 == 0)
            bin.push_back(0);
        else
            bin.push_back(1);
        a /= 2;
    }
    
    int i = (int)bin.size();
    while(i-- != 0)
        cout << bin[i];
    return 0;
}