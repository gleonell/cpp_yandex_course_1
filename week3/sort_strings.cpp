#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main ()
{
    int n;
    cin >> n;

    vector<string> v(n);
    for (string& str: v)
    {
        cin >> str;
    }

    sort(begin(v), end(v), [](string str1, string str2){
        string low1 = str1;
        string low2 = str2;
        for (unsigned int i = 0; i < str1.size(); i++)
            low1[i] = tolower(str1[i]);
        for (unsigned int i = 0; i < str2.size(); i++)
            low2[i] = tolower(str2[i]);
        return low1 < low2;    
    });

    for (const auto& str: v)
    {
        cout << str << " ";
    }
    return 0;
}
