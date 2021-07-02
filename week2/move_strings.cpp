#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& s, vector<string>& d)
{
    for (auto w: s)
        d.push_back(w);
    s.clear();
}

// int main()
// {
//     vector<string> source =  {"a", "b", "c"};
//     vector<string> destination = { "a", "b", "c", "z"};

//     MoveStrings(source, destination);

//     for (auto w: destination)
//         cout << w << " ";
//     cout << endl <<source.size();
//     return 0;
// }