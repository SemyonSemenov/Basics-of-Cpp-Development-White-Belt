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

Rational operator*(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
