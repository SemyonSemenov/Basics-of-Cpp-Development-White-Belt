#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	string ans = "zzz";
	for(int i = 0; i < 3; i++)
	{
		string input;
		cin >> input;
		if (input < ans){
			ans = input;
		}
	}
	cout << ans;
	return 0;
}
