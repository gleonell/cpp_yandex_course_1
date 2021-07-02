#include <iostream>
#include <vector>

using namespace std;

 vector<int> Reversed(const vector<int>& v)
 {
    vector<int> res;

    for (int i = (v.size() - 1); i >= 0; --i)
        res.push_back(v[i]);
    return res;
 }

// int main()
// {
//     vector<int> v =  {1 , 2 , 3 , 4};
//     vector<int> r;
//     r = Reversed(v);

//     for (auto w: r)
//         cout << w << " ";
    
//     return 0;
// }