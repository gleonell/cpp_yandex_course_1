#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word)
{
    map<char, int> char_counter;

    for (const auto& c: word)
        ++char_counter[c];// if exist then ++, if not then create new key-value
    return char_counter;
}

int main()
{
    int n;
    string first_w, second_w;

    cin >> n;

    while (n != 0)
    {
        cin >> first_w >> second_w;
        if (BuildCharCounters(first_w) == BuildCharCounters(second_w))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        n --;
    }

    return 0;
}