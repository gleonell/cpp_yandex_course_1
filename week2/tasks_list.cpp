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
    cout << endl;
}

vector<vector<string>>    call_next(const vector<vector<string>>& list, bool& is_february, int& circle)
{
    vector<vector<string>> result;

    result.insert(end(result), begin(list), end(list));
    if (result.size() == 32)
    {
        if (is_february == 0){
            for (int i = 29; i <= 31; i++)
                result[28].insert(end(result[28]), begin(list[i]), end(list[i]));
            result.resize(29);
            is_february = 1;}
        else if(circle == 12 || circle == 7){
            if (circle == 12){
                is_february = 0;
                circle = 0;}
            return result;}
        else{
            result[30].insert(end(result[30]), begin(list[31]), end(list[31]));
            result.resize(31);}
    }
    else
        result.resize(32);
    return result;
}

int     main()
{
    vector<vector<string>> day_list(32);
    string cmd;
    int q;
    bool is_february = 0;
    int circle = 0;
    
    cin >> q;

    while (q != 0)
    {
        cmd.clear();
        cin >> cmd;

        if (cmd == "ADD")
            call_add(day_list);
        else if (cmd == "DUMP")
            call_dump(day_list);
        else if (cmd == "NEXT")
        {
            circle++;
            day_list = call_next(day_list, is_february, circle);
        }
        else
            break;
        q--;
    }
    return 0;
}