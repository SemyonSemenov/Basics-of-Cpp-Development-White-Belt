#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec;
	if (n == 0){
		cout << 0;
	}
	while (n > 0){
		vec.push_back(n % 2);
		n = n / 2;
	}

	for (int i = vec.size() - 1; i >=0; i--){
		cout << vec[i];
	}
	return 0;
}
