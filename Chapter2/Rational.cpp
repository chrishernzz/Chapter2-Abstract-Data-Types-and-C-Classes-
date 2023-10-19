#include "Rational.h"

//precondition: going to pass in two arguments(parameters)
//postcondition: going to then return the greaters common dominator
int Rational::gcd(int a, int b) const{
	//abs() function will handle negative numbers, turning them to positive
	a = abs(a);
	b = abs(b);
	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else if (a == b) {
		return a;
	}
	else if (a > b) {
		return gcd(a - b, b);
	}
	else {
		return gcd(a, b - a);
	}
}
//precondition: going to call the denominator and the numerator with the gcd() function
//postcondition: going to then check for the greatest common denominator, using the abs(turn it to positive)
void Rational::normalize(){
	//if denominator is less than 0, turn the denominaotr and numerator to a positve
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}
	if (numerator != 0) {
		//abs() will turn the negative to a positive number
		int temp = gcd(abs(numerator), abs(denominator));
		numerator /= temp;
		denominator /= temp;
	}
}

//precondition: going to call the ZeroDenominator class
//postcondition: going to put it as a default constructor
Rational::ZeroDenominator::ZeroDenominator(){}

//precondition: going to pass in the Rational class to give you access to the toString() function
//postcondition: going to then now set the rational which is the ZeroDenominator private = to the toString()
Rational::ZeroDenominator::ZeroDenominator(Rational r){
	rational = r.toString();
}
//precondition: going to call the toString() function
//postcondition: going to return the rational (string)
string Rational::ZeroDenominator::toString(){
	return rational;
}

//precondition: going to call my default constructor
//postcondition: going to set the variables to 0 and 1 (initialize them)
Rational::Rational(){
	numerator = 0;
	denominator = 1;
}
//precondition: going to pass in two arguments that will accept the newNumerator and newDenominator
//postcondition: going to then now set the private variables with the new, check if denominator is 0, if 0 throw an error, call the normalize() function
Rational::Rational(int newNumerator, int newDenominator){
	numerator = newNumerator;
	denominator = newDenominator;
	//if the denominator is zero, throw
	if (denominator == 0) {
		throw ZeroDenominator(*this);
	}
	//call this function to check for the numerator and denominator
	normalize();
}
//precondition: going to turn the variables to a string since they are int
//postcondition: going to return the privates variables to a string, meaning if its 5 it will be "5"
string Rational::toString(){
	return to_string(numerator) + "/" + to_string(denominator);
}

//precondition: going to get the numerator
//postcondition: going to return the private numerator
int Rational::getNumerator() const{
	return numerator;
}
//precondition: going to get the new numerator
//postcondition: going to set the private numerator with the new numerator member
void Rational::setNumerator(int newNumerator) {
	numerator = newNumerator;
}
//precondition: going to get the denominator
//postcondition: going to return the private denominator
int Rational::getDenominator() const{
	return denominator;
}
//precondition: going to get the new denominator
//postcondition: going to set the private denominator with the new denominator member, check if its 0, if 0 throw an error
void Rational::setDenominator(int newDenominator){
	denominator = newDenominator;
	//if the denominator is zero, throw
	if (denominator == 0) {
		throw ZeroDenominator(*this);
	}
	normalize();
}
//precondition: going to passed in my objects, two objects so i can multiply and get the total, using the * 
//postcondition: going to then use the to_string() to turn it into strings, going to call my gcd() function to make sure i get the greatest common denominator
string operator*(const Rational& obj1, const Rational& obj2){
	//multiply the numerator first from both objects
	int numeratorTotal = (obj1.getNumerator() * obj2.getNumerator());
	//now multiply the denominator from both objects
	int denominatorTotal = (obj1.getDenominator() * obj2.getDenominator());
	
	//going to check for the greatest common denominator using my gcd() function
	//using the obj1 to give me access to the gcd (Rational class)
	int getGreatestCommonDiv = obj1.gcd(numeratorTotal, denominatorTotal);

	//going to divide both with the greatest common div
	numeratorTotal /= getGreatestCommonDiv;
	denominatorTotal /= getGreatestCommonDiv;
	//using to_string to the int go to a string;
	return to_string(numeratorTotal) + "/" + to_string(denominatorTotal);
}
//precondition: going to passed in my objects, two objects so i can multiply and get the total, using the / to divide
//postcondition: going to then use the to_string() to turn it into strings, calling my gcd() function to make sure i get the greatest common denominator
string operator/(const Rational& obj1, const Rational& obj2){
	//multiply the numerator for obj1 times the denomiator obj2
	int totalNumTimesDen = (obj1.getNumerator() * obj2.getDenominator());
	//multiply the denominator for obj1 times the numerator obj2
	int totalDenTimesNum = (obj1.getDenominator() * obj2.getNumerator());

	//checking if they are negatives 
	if (totalNumTimesDen < 0 && totalDenTimesNum < 0) {
		//if both negative, turn them to positive using the abs() function
		totalNumTimesDen = abs(totalNumTimesDen);
		totalDenTimesNum = abs(totalDenTimesNum);
	}
	//if denominator is a negative,  move it to the numerator
	if (totalDenTimesNum < 0) {
		//making numator negative
		totalNumTimesDen = -totalNumTimesDen;
		totalDenTimesNum = abs(totalDenTimesNum);
	}
	//if both numerators are 0
	if (obj1.getNumerator() == 0 && obj2.getNumerator() == 0) {
		//then its undefined  for the result
		return "Undefined"; 
	}
	//else if the first numerator is 0, then answer is 0
	else if (obj1.getNumerator() == 0) {
		return "0";
	}
	//else if second numerator 0, then its undefined
	else if (obj2.getNumerator() == 0) {
		return"Undefined";
	}
	//going to check for the greatest common denominator using my gcd() function
	//using the obj1 to give me access to the gcd (Rational class)
	int getGreatestCommonDiv = obj1.gcd(totalNumTimesDen, totalDenTimesNum);
	//going to divide both with the greatest common div
	totalNumTimesDen /= getGreatestCommonDiv;
	totalDenTimesNum /= getGreatestCommonDiv;

	//using to_string to the int go to a string;
	return to_string(totalNumTimesDen) + "/" + to_string(totalDenTimesNum);
}
//precondition: going to passed in my objects, two objects so i can multiply and get the total, using the + to add the object1 and object2
//postcondition: going to then use the to_string() to turn it into strings, calling my gcd() function to make sure i get the greatest common denominator
string operator+(const Rational& obj1, const Rational& obj2){
	//going to first multiply both denominators for obj1 and obj2
	int totalDenominator = (obj1.getDenominator() * obj2.getDenominator());
	//going to multiply the obj1 times the obj2 of the denominitor then add that with the same thing but now obj2 times obj1 denominator
	int totalNumerator = (obj1.getNumerator() * obj2.getDenominator()) + (obj2.getNumerator() * obj1.getDenominator());

	//going to check for the greatest common denominator using my gcd() function
	//using the obj1 to give me access to the gcd (Rational class)
	int getGreatestCommonDiv = obj1.gcd(totalNumerator, totalDenominator);
	//going to divide both with the greatest common div
	totalNumerator /= getGreatestCommonDiv;
	totalDenominator /= getGreatestCommonDiv;

	//using to_string to the int go to a string;
	return to_string(totalNumerator) + "/" + to_string(totalDenominator);
}
//precondition: going to do the same thing as addition, but now subtract
//postcondition: going to do the same as the addition by calling the same information,but this time return - (subtractting)
string operator-(const Rational& obj1, const Rational& obj2){
	//going to first multiply both denominators for obj1 and obj2
	int totalDenominator = (obj1.getDenominator() * obj2.getDenominator());
	//going to multiply the obj1 times the obj2 of the denominitor then add that with the same thing but now obj2 times obj1 denominator
	int totalNumerator = (obj1.getNumerator() * obj2.getDenominator()) - (obj2.getNumerator() * obj1.getDenominator());

	//going to check for the greatest common denominator using my gcd() function
	//using the obj1 to give me access to the gcd (Rational class)
	int getGreatestCommonDiv = obj1.gcd(totalNumerator, totalDenominator);
	//going to divide both with the greatest common div
	totalNumerator /= getGreatestCommonDiv;
	totalDenominator /= getGreatestCommonDiv;

	//using to_string to the int go to a string;
	return to_string(totalNumerator) + "/" + to_string(totalDenominator);
}
//precondition: going to passed in my objects, two objects so i can check the statement wherever i am using the ==
//postcondition: going to check if they are equal to each other, if so then true
bool operator==(const Rational& obj1, const Rational& obj2){
	return (obj1.getNumerator() * obj2.getDenominator()) == (obj2.getNumerator() * obj1.getDenominator());
}
//precondition: going to passed in my objects, two objects so i can check the statement wherever i am using the <
//postcondition: going to check if obj1 is less than obj2, if so then true
bool operator<(const Rational& obj1, const Rational& obj2){
	return (obj1.getNumerator() * obj2.getDenominator()) < (obj2.getNumerator() * obj1.getDenominator());
}
