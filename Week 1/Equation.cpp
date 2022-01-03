#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	double A, B, C;
	cin >> A >> B >> C;

	if (A != 0){
		double D = B * B - 4 * A * C;
		if (D >= 0)
		{
			D = sqrt(D);
			double x1 = (-B + D) / (2 * A);
			double x2 = (-B - D) / (2 * A);
			if (x1 == x2){
				cout << x1;
			}
			else{
				cout << x1 << ' ';
				cout << x2;
			}

		}
	}
	else if (A == 0){
		if (B != 0){
			double x = -C / B;
			cout << x;
		}
	}
	return 0;
}
