#include <iostream>
using namespace std;

int Factorial(int x){
	if(x <= 1){
		return 1;
	}
	else{
		int fact = 1;
		for (int i = 2; i <= x; i++){
			fact *= i;
		}
		return fact;
	}
}

int main() {
	int x;
	cin >> x;
	cout << Factorial(x);
	return 0;
}
