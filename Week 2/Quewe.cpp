#include <iostream>
#include <string>
#include <vector>
using namespace std;

void COME(vector<bool>& v, int k){
	v.resize(v.size() + k);
}

void WORRY(vector<bool>& v, int i){
	v[i] = true;
}

void QUIET(vector<bool>& v, int i){
	v[i] = false;
}

void WORRY_COUNT(vector<bool>& v){
	int sum = 0;
	for (auto w : v){
		if (w == true){
			sum += 1;
		}
	}
	cout << sum <<endl;
}

int main() {
	int Q;
	cin >> Q;
	vector<bool> v(0, false);
	for (int i = 0; i < Q; i++){
		string com;
		cin >> com;
		if (com == "WORRY_COUNT"){
			WORRY_COUNT(v);
		}
		else{
			int k;
			cin >> k;
			if (com == "COME"){
				COME(v, k);
			}
			else if (com == "QUIET"){
				QUIET(v, k);
			}
			else if (com == "WORRY"){
				WORRY(v, k);
			}
		}
	}
	return 0;
}
