#include <iostream>
#include <cstring>

using namespace std;

bool IsPalindrom(string pldrom)
{
    string copy = pldrom;
    int j = pldrom.size();
    for (int i = -1; j >= 0; ++i)
    {
        copy[i] = pldrom[j];
        j--;
    }

    if (copy == pldrom)
        return (true);
    else
        return (false);
}

int main()
{
    string str;
    cin >> str;

    if (IsPalindrom(str))
        cout << "true";
    else
        cout << "false";
    return 0;
}