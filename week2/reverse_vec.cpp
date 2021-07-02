#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& r)
{
    int tmp;

    for (int i = 0; i < (int)r.size() / 2; ++i)
    {
        tmp = r[i];
        r[i] = r[(int)r.size() - i - 1];
        r[(int)r.size() - i - 1] = tmp;
    }
}

// int main()
// {
//     vector<int> r =  {1 , 2 , 3 , 4};
    

//     Reverse(r);

//     for (auto w: r)
//         cout << w << " ";
    
//     return 0;
// }