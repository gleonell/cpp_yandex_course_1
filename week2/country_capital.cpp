#include <iostream>
#include <string>
#include <map>

using namespace std;

void    call_change(map<string, string>& country_capital)
{
    string country, new_capital;

    cin >> country >> new_capital;

    if (country_capital.count(country) == 0)
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    else {
        if (country_capital[country] == new_capital)
            cout << "Country " << country << " hasn't changed its capital" << endl;
        else
            cout << "Country " << country << " has changed its capital from " << country_capital[country] << " to " << new_capital << endl;
    }
    country_capital[country] = new_capital;

}

void    call_rename(map<string, string>& country_capital)
{
    string old_country, new_country;
    cin >> old_country >> new_country;

    if (old_country == new_country || country_capital.count(old_country) == 0 || country_capital.count(new_country) == 1)
        cout << "Incorrect rename, skip" << endl;
    else
    {
        cout << "Country " << old_country << " with capital " << country_capital[old_country] << " has been renamed to " << new_country << endl;
        country_capital[new_country] = country_capital[old_country];
        country_capital.erase(old_country);
    }
}

void    call_dump(const map<string, string>& country_capital)
{
    if (country_capital.empty())
        cout << "There are no countries in the world" << endl;
    else
        for (const auto& list: country_capital)
            cout << list.first << "/" << list.second << " ";
}

int     main()
{
    map<string, string> country_capital;
    string cmd;
    int q;
    
    cin >> q;

    while (q != 0)
    {
        cmd.clear();
        cin >> cmd;

        if (cmd == "CHANGE_CAPITAL")
            call_change(country_capital);
        else if (cmd == "RENAME")
            call_rename(country_capital);
        else if (cmd == "ABOUT")
        {
            string country;
            cin >> country;

            if (country_capital.count(country) == 0)
                cout << "Country " << country << " doesn't exist" << endl;
            else
                cout << "Country " << country << " has capital " << country_capital[country] << endl;
        }
        else if (cmd == "DUMP")
            call_dump(country_capital);
        else
            break;
        q--;
    }
    return 0;
}
