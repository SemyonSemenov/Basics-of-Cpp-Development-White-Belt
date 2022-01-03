#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const int& a, const int& b){
	if (abs(a) < abs(b)){
		return true;
	}
	return false;
}

int main() {
	vector<int> nums;
	int N;
	cin >> N;
	for (int i = 0; i < N; i ++){
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(begin(nums), end(nums), comp);
	for (const auto& num : nums){
		cout << num << ' ';
	}
	return 0;
}
