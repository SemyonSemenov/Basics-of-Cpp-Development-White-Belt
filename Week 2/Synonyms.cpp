#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	// https://www.coursera.org/lecture/c-plus-plus-yellow/diekompozitsiia-rieshieniia-zadachi-sinonimy-Fs5uS
	int Q;
	cin >> Q;
	map<string, set<string>> syns;
	for(int i = 0; i < Q; i++){
		string com;
		cin >> com;
		if(com == "ADD"){
			string word1, word2;
			cin >> word1 >> word2;
			syns[word1].insert(word2);
			syns[word2].insert(word1);
		}
		else if(com == "CHECK"){
			string word1, word2;
			cin >> word1 >> word2;
			if(syns[word1].count(word2) != 0){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		else if(com == "COUNT"){
			string word;
			cin >> word;
			cout << syns[word].size()<< endl;
		}
	}
	return 0;
}
