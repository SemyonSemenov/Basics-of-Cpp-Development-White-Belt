#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int i = 0;
	int f = 0;
	for (char ch: s){
		if (ch == 'f'){
			f++;
			if(f == 2){
				cout << i;
				break;
			}
		}
		i++;
	}
	if (f == 1){
		cout << -1;
	}
	else if (f == 0){
		cout << -2;
	}
	return 0;
}
