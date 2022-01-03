#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Reverse(vector<int>& v){
	for (int i = 0; i < int(v.size() / 2); i++){
		int tmp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = tmp;
	}
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	for (int w : numbers){
		cout << w << " ";
	}
	return 0;
}
