#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void ADD(vector<vector<string>>& v, int i, string s){
	v[i - 1].push_back(s);
}

void DUMP(const vector<vector<string>>& v, int i){
	cout << v[i - 1].size() << " ";
	for (auto deal : v[i - 1]){
		cout << deal << " ";
	}
	cout << endl;
}

void NEXT(vector<vector<string>>& v, int& curr){
	int next = (curr + 1) % 12;

	if (days[curr] < days[next]){
		v.resize(days[next]);
	}
	else if (days[curr] > days[next]){
		for (int j = days[next]; j < days[curr]; j++){
			for(auto deal : v[j]){
				v[days[next] - 1].push_back(deal);
			}
		}
		v.resize(days[next]);
	}
	curr = next;
}

int main() {
	int n;
	cin >> n;
	int curr = 0;
	vector<vector<string>> v(days[curr]);
	for (int j = 0; j < n; j++){
		string com;
		cin >> com;
		if (com == "ADD"){
			int i;
			string s;
			cin >> i;
			cin >> s;
			ADD(v, i, s);
		}
		else if (com == "DUMP"){
			int i;
			cin >> i;
			DUMP(v, i);
		}
		else if (com == "NEXT"){
			NEXT(v, curr);
		}
	}
	return 0;
}
