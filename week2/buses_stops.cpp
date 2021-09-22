#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void  buses_for_stop(map<string, vector<string>>& stops_to_buses)
{
  string stop;
  cin >> stop;

  if (stops_to_buses.count(stop) == 0) 
    cout << "No stop" << endl;
  else
  {
    for (const string& bus : stops_to_buses[stop])
      cout << bus << " "; 
    cout << endl;
  }                
}

void stop_for_buses(map<string, vector<string>>& buses_to_stops,
                    map<string, vector<string>>& stops_to_buses)
{
  string bus;
  cin >> bus;

  if (buses_to_stops.count(bus) == 0)
    cout << "No bus" << endl;
  else
  {
    for (const string& stop : buses_to_stops[bus])
    {
      cout << "Stop " << stop << ": ";
      if (stops_to_buses[stop].size() == 1)//checking how many buses in stop_to_buses map in current stop
            cout << "no interchange";
      else
      {
        for (const string& other_bus : stops_to_buses[stop])
          if (bus != other_bus)
            cout << other_bus << " ";
      }
      cout << endl;
    }
  }             
}

void all_buses_list(const map<string, vector<string>>& buses_to_stops)
{
  if (buses_to_stops.empty())
    cout << "No buses" << endl;
  else
  {
    for (const auto& bus_item : buses_to_stops)    //cycle for map
    {
      cout << "Bus " << bus_item.first << ": ";
      for (const string& stop : bus_item.second)//cycle for value of map (vector in our case)
        cout << stop << " ";
      cout << endl;
    }
  }             
}
int main() 
{
  map<string, vector<string>> buses_to_stops, //bus is key, vector of stops is value
  stops_to_buses;                            //stop is key, vector of all buses in current stop is value
  int q;
  cin >> q;

  while (q != 0) 
  { 
    string cmd;
    cin >> cmd;
    if (cmd == "NEW_BUS") 
    {
      string bus;
      int stop_count;
      cin >> bus;
      cin >> stop_count;
                                                    //in next line in buses_to_stops[bus] operation we create the bus key if it doesn't exist
      vector<string>& stops = buses_to_stops[bus]; //short name of buses_to_stops map
      stops.resize(stop_count);                   //size of stops amout
      for (string& stop : stops)                 //writing all stop names in current bus value
      {
        cin >> stop;
        stops_to_buses[stop].push_back(bus);  //also in second map we create all stops as keys and push_back bus name we need
      }
    } 
    else if (cmd == "BUSES_FOR_STOP") 
      buses_for_stop(stops_to_buses);
    else if (cmd == "STOPS_FOR_BUS")
      stop_for_buses(buses_to_stops, stops_to_buses);
    else if (cmd == "ALL_BUSES") 
      all_buses_list(buses_to_stops);
    else
      break;
    q--;
  }
  return 0;
}