#include <iostream>
#include <map>

using namespace std;

class Person {
public:

  void ChangeFirstName(int year, const string& first_name) {
      name_history[year] = first_name;
  }
  
  void ChangeLastName(int year, const string& last_name) {
      sername_history[year] = last_name;
  }

  string GetFullName(int year) {
      
    string name, sername;
    bool first_name = false;
    bool last_name = false;
    
    for (int i = year; i >= name_history.begin() -> first; i--) {
        if (name_history.count(i)) {
            name = name_history[i];
            first_name = true;
            break;
        }
    }
    for (int i = year; i >= sername_history.begin() -> first; i--) {
        if (sername_history.count(i)) {
            sername = sername_history[i];
            last_name = true;
            break;
        }
    }
    
    if (first_name && last_name)
        return name + " " + sername;
        else if (first_name)
            return name + " with unknown last name";
        else if (last_name)
            return sername + " with unknown first name";
        else 
            return "Incognito";
  }
private:
    map<int, string> name_history;
    map<int, string> sername_history;
};

/*
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
*/