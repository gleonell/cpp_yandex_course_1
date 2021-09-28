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

    Person (const string& name, const string& surname, const int& year) {
        first_names[year] = name;
        last_names[year] = surname;
        born_year = year;  
    }

    void ChangeFirstName(const int& year, const string& first_name) {
        if (born_year <= year)
            first_names[year] = first_name;
    }

    void ChangeLastName(const int& year, const string& last_name) {
        if (born_year <= year)
            last_names[year] = last_name;
    }

    string GetFullName(const int& year) const {
        if (born_year > year)
            return "No person";
        else {
            const string first_name = FindNameByYear(first_names, year);
            const string last_name = FindNameByYear(last_names, year);

            if (first_name.empty())
                return last_name;
            else if (last_name.empty())
                return first_name;
            else
                return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) const {
        if (born_year > year)
            return "No person";
        else {
            const string first_name = FindNameByYearWithHistory(first_names, year);
            const string last_name = FindNameByYearWithHistory(last_names, year);

            if (first_name.empty())
                return last_name;
            else if (last_name.empty())
                return first_name;
            else
                return first_name + " " + last_name;
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
    int born_year;
};


// int main() {
//   Person person("Polina", "Sergeeva", 1960);
//   for (int year : {1959, 1960}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1965, "Appolinaria");
//   person.ChangeLastName(1967, "Ivanova");
//   for (int year : {1965, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   return 0;
// }

// #include <string>
// int main() {
//     Person person("first", "last", 1);
//     int year = 1;
//     person.ChangeFirstName(year, std::to_string(year) + "_Ifirst");
//     person.ChangeLastName(year, std::to_string(year) + "_Ilast");    
//     std::cout << "year: " << year << '\n';
//     std::cout << person.GetFullNameWithHistory(year) << '\n';
//     std::cout << person.GetFullName(year) << '\n';
//     return 0;
// }