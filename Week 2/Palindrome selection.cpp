
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void NEW_BUS(map<string, vector<string>>& bus_stops, string bus, string stop){
	bus_stops[bus].push_back(stop);
}

void BUSES_FOR_STOP(map<string, vector<string>>& bus_stops, vector<string> buses, string stop){
	/*if (bus_stops.count(stop) != 0){

	}*/
	bool exists = false;
	for (auto bus : buses){
		for (auto stop_i : bus_stops[bus]){
			if (stop_i == stop){
				cout << bus << " ";
				exists = true;
			}
		}
	}
	if (exists == false){
		cout << "No stop" << endl;
	}
	else{
		cout << endl;
	}
}

void STOPS_FOR_BUS(map<string, vector<string>>& bus_stops, vector<string> buses, string bus){
	bool bus_exists = false;
	if (bus_stops.count(bus) != 0){
		bus_exists = true;
	}

	if (bus_exists == true){
		for (auto stop : bus_stops[bus]){
			bool exists_inter = false;
			for (auto bus_i : buses){
				if (bus_i != bus){
					for (auto stop_i : bus_stops[bus_i]){
						if (stop_i == stop){
							if (exists_inter == false){
								cout << "Stop" << " " << stop << ":";
								cout << " " << bus_i;
								exists_inter = true;
							}
							else{
								cout << " " << bus_i;
							}
						}
					}
				}
			}
			if (exists_inter == false){
				cout << "Stop" << " " << stop << ": " << "no interchange" << endl;
			}
			else{
				cout << endl;
			}
		}
	}
	else{
		cout << "No bus" << endl;
	}
}

void ALL_BUSES(const map<string, vector<string>>& bus_stops){
	if (bus_stops.size() != 0){
		for (const auto& item : bus_stops){
			cout << "Bus " << item.first << ":";
			for (const auto& stop : item.second){
				cout << " " << stop;
			}
			cout << endl;
		}
	}
	else{
		cout << "No buses" << endl;
	}
}

int main() {
	map<string, vector<string>> bus_stops;
	vector<string> buses(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string com;
		cin >> com;
		if (com == "NEW_BUS"){
			string bus;
			cin >> bus;
			buses.push_back(bus);
			int stop_count;
			cin >> stop_count;
			for (int j = 0; j < stop_count; j++){
				string stop;
				cin >> stop;
				NEW_BUS(bus_stops, bus, stop);
			}
		}
		else if (com == "BUSES_FOR_STOP"){
			string stop;
			cin >> stop;
			BUSES_FOR_STOP(bus_stops, buses, stop);
		}
		else if (com == "STOPS_FOR_BUS"){
			string bus;
			cin >> bus;
			STOPS_FOR_BUS(bus_stops, buses, bus);
		}
		else if (com == "ALL_BUSES"){
			ALL_BUSES(bus_stops);
		}
	}
	return 0;
}
