#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, set<string>> is_synonyms;
    while (q--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;

            is_synonyms[word1].insert(word2);
            is_synonyms[word2].insert(word1);
        }
        else if (cmd == "COUNT")
        {
            string word;
            cin >> word;

            if (is_synonyms.count(word))
                cout << is_synonyms[word].size() << endl;
            else
                cout << 0 << endl;
        }
        else if (cmd == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;
            if (is_synonyms[word1].count(word2))
                cout << "YES" << endl; 
            
            else
                cout << "NO" << endl;
        }
    }
}
