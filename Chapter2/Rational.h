#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//precondition: going to create the class that has the information of rational, then in public create the ZeroDenominato class
//postcondition: going to create a constructor for both class, gcd and normalize function, accessors, mutators, overloading operators to use
class Rational{
private:
	int numerator, denominator;
	//getting the greatest common dominator
	int gcd(int a, int b) const;
	//function will check if denominator is negative, then the negative sign is moved to the numerator
	void normalize();
public:
	class ZeroDenominator {
	private:
		string rational;
	public:
		//defualt constructor
		ZeroDenominator();
		//constructor one argument(parameter)
		ZeroDenominator(Rational r);
		string toString();
	};
	//defualt constructor
	Rational();
	//constructor
	Rational(int newNumerator, int newDenominator);

	//function that retuns a string expression of hte numerator/denominator
	string toString();

	//getters(accesors)
	int getNumerator() const;
	int getDenominator() const;
	//setters(mutators)
	void setNumerator(int newNumerator);
	void setDenominator(int newDenominator);

	//overloading operators  *,/,+,-,==,<
	friend string operator*(const Rational& obj1, const Rational& obj2);
	friend string operator/(const Rational& obj1, const Rational& obj2);
	friend string operator+(const Rational& obj1, const Rational& obj2);
	friend string operator-(const Rational& obj1, const Rational& obj2);
	friend bool operator==(const Rational& obj1, const Rational& obj2);
	friend bool operator<(const Rational& obj1, const Rational& obj2);
};

