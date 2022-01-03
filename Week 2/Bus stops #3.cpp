#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	map<set<string>, int> routes;
	int num = 1;
	for(int i = 0; i < Q; i++){
		int N;
		cin >> N;
		set<string> route;
		for(int j = 0; j < N; j++){
			string tmp;
			cin >> tmp;
			route.insert(tmp);
		}
		if(routes.count(route) == 0){
			routes[route] = num;
			cout << "New bus " << num << endl;
			num++;
		}
		else{
			cout << "Already exists for " << routes[route] << endl;
		}
	}
	return 0;
}
