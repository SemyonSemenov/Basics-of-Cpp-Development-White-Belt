#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <exception>
#include <stdexcept>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
    	num = 0;
    	den = 1;
    }

    Rational(int numerator, int denominator) {
    	if (numerator * denominator > 0){
    		num = abs(numerator);
    		den = abs(denominator);
    	}
    	else if(numerator * denominator < 0){
    		num = -abs(numerator);
    		den = abs(denominator);
    	}
    	else{
    		num = 0;
    		den = 1;
    	}
    }

    int Numerator() const {
    	return num / gcd(abs(num), abs(den));
    }

    int Denominator() const {
    	return den / gcd(abs(num), abs(den));
    }

private:
    int num;
    int den;
};

Rational operator+(const Rational& lhs, const Rational& rhs){
	// a / b + c / d = (ad + bc) / bd
	return Rational(lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs){
	// a / b - c / d = (ad - bc) / bd
	return Rational(lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

bool operator==(const Rational& lhs, const Rational& rhs){
	// a / b == c / d <=> ad == bc
	if(lhs.Numerator() * rhs.Denominator() == lhs.Denominator() * rhs.Numerator()){
		return true;
	}
	return false;
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    cout << "OK" << endl;
    return 0;
}

