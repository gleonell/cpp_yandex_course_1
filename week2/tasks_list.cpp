#include <iostream>
#include <vector>

using namespace std;

void    call_add(vector<vector<string>>& list)
{
    int i;
    string task;
    cin >> i;
    cin >> task;

    list[i].push_back(task);
}

void    call_dump(const vector<vector<string>>& list)
{
    int i;
    cin >> i;

    cout << list[i].size() << " ";
    for (auto x: list[i])
        cout << x << " ";
}

int     main()
{
    vector<vector<string>> day_list(31);
    string cmd;
    int q;
    //int first_in_flag = 0;
    
    cin >> q;

    while (q != 0)
    {
        cmd.clear();
        cin >> cmd;

        if (cmd == "ADD")
            call_add(day_list);
        else if (cmd == "DUMP")
            call_dump(day_list);
        else
            break;
        q--;
    }
    return 0;
}