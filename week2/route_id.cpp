#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
 
int main() {
    
    int q, n;
    map<vector<string>, int> roite_id;

    cin >> q;
    while (q-- != 0)
    {
        cin >> n;
        vector<string> stops(n);
        
        string stop;
        for (string& stop: stops) 
            cin >> stop;
        if (roite_id.count(stops))
            cout << "Already exists for " << roite_id[stops] << endl;
        else
        {
            int tmp = roite_id.size() + 1;
            roite_id[stops] = tmp;
            cout << "New bus " << roite_id[stops] << endl;
        }
    }
    return 0;
}