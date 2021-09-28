#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int i, int j)
{
    if (abs(i) < abs(j))
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    while (n--)
    {
        int item;
        cin >> item;
        v.push_back(item);
    }

    sort(begin(v), end(v), comp);
    for (const auto& i: v)
    {
        cout << i << " ";
    }
    cout << endl;
   
    return 0;
}
