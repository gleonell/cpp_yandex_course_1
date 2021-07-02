#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
   
    vector<int> days(n);
    
    for (int& day: days)
    {
        cin >> day;
        sum += day;
    }

    int k = 0;
    for (auto i: days)
        if (i > sum/n)
            k++;
    cout << k << endl;
    
    for(int i = 0; i < n; ++i)
        if (days[i] > sum/n)
            cout << i << " ";
        
    return 0;
}