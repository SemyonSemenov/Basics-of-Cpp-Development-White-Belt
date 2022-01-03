#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
//    ofstream output("output.txt");

    int n = 0;
    int m = 0;
    input >> n;
    input.ignore(1);
    input >> m;
    input.ignore(1);


    for (int i = 0 ; i < n; i++){
    	for (int j = 0; j < m; j++){
    		int num = 0;
    		input >> num;
    		input.ignore(1);

    		if (j != m - 1){
    			cout << setw(10) << num << " ";
    		}
    		else{
    			cout << setw(10) << num;
    		}
    	}
    	if (i != n - 1){
    		cout << "\n";
    	}
    }

    return 0;
}
