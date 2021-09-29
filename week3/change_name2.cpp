#include <iostream>
#include <map>
#include <vector>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    string name;
    
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        } 
        else {
            break;
        }
    }
    return name;
}

string FindNameByYearWithHistory(const map<int, string>& names, int year) {
    string result;
    string tmp;
    vector<string> history;
  
    for (const auto& item : names) {
        if (item.first <= year) {
            if (tmp != item.second) {
                history.push_back(item.second);
                tmp = item.second;
            }
        } 
        else {
            break;
        }
    }
    
    if (history.size() <= 1)
        return tmp;
    else {
        for (int i = history.size() - 2; i >= 0; i--) {
            if (i == 0)
                result += history[i];
            else
                result += history[i] + ", ";
        }
        return history[history.size() - 1] + " (" + result + ")";
    }
}


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        
        if (first_name.empty() && last_name.empty())
            return "Incognito";
        else if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name"; 
        else
            return first_name + " " + last_name;
    }

    string GetFullNameWithHistory(int year) {
        const string first_name = FindNameByYearWithHistory(first_names, year);
        const string last_name = FindNameByYearWithHistory(last_names, year);
        
        if (first_name.empty() && last_name.empty())
            return "Incognito";
        else if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name"; 
        else
            return first_name + " " + last_name;
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1990, "Polina");
//   person.ChangeLastName(1990, "Volkova-Sergeeva");
//   cout << person.GetFullNameWithHistory(1990) << endl;
  
//   person.ChangeFirstName(1966, "Pauline");
//   cout << person.GetFullNameWithHistory(1966) << endl;
  
//   person.ChangeLastName(1960, "Sergeeva");
//   for (int year : {1960, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeLastName(1961, "Ivanova");
//   cout << person.GetFullNameWithHistory(1967) << endl;
  
//   return 0;
// }


// int main() {
//   Person person;

//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Appolinaria");

//   person.ChangeLastName(1965, "Sergeeva");
//   person.ChangeLastName(1965, "Volkova");
//   person.ChangeLastName(1965, "Volkova-Sergeeva");

//   for (int year : {1964, 1965, 1966}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   return 0;
// }