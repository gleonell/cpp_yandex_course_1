#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    int q;
    map<set<string>, unsigned int> bus_list;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;
        set<string> stations;

        while (n--)
        {
            string station;
            cin >> station;

            stations.insert(station);
        }

        if (bus_list.count(stations))
            cout << "Already exists for " << bus_list[stations] << endl;
        else
        {
            bus_list[stations] = bus_list.size() + 1;
            cout << "New bus " << bus_list[stations] << endl;
        }
    }
}