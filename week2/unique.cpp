#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> s;

    while (n-- != 0)
    {       
        string str;  
        cin >> str;
        s.insert(str);
    }
    cout << s.size();
    return 0;
}
