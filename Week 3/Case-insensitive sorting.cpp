#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

bool comp(std::string a, std::string b){
	std::transform(a.begin(), a.end(), a.begin(),
	    [](unsigned char c){ return std::tolower(c); });
	std::transform(b.begin(), b.end(), b.begin(),
		    [](unsigned char c){ return std::tolower(c); });

	if (a < b){
		return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	vector<string> strs(N);

	for (auto& str : strs){
		cin >> str;
	}

	sort(begin(strs), end(strs), comp);
	for (const auto& str : strs){
		cout << str << ' ';
	}

	return 0;
}
