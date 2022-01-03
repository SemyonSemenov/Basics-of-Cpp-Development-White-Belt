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

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;

  if (is) {
      is >> n >> c >> d;
      if (is) {
          if (c == '/') {
              r = Rational(n, d);
          }
          else {
              is.setstate(ios_base::failbit);
          }
      }
  }

  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
