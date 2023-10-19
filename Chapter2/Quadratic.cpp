#include "Quadratic.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the variables to 0 (initialize them)
Quadratic::Quadratic() : a(0.0), b(0.0), c(0.0) {}

//precondition: going to get the a(coefficient)
//postcondition: going to return the private a
double Quadratic::getA() const{
	return a;
}
//precondition: going to get the new a
//postcondition: going to set the private a with the new a member
void Quadratic::setA(double newA) {
	a = newA;
}

//precondition: going to get the b(coefficient)
//postcondition: going to return the private b
double Quadratic::getB() const{
	return b;
}
//precondition: going to get the new b
//postcondition: going to set the private b with the new a member
void Quadratic::setB(double newB) {
	b = newB;
}

//precondition: going to get the c(coefficient)
//postcondition: going to return the private c
double Quadratic::getC() const{
	return c;
}
//precondition: going to get the new b
//postcondition: going to set the private b with the new a member
void Quadratic::setC(double newC) {
	c = newC;
}

//precondition: going to evaluate the expression of x (ax^2+bx+c)
//postcondition: going to then return the total of the evaluation of x
double Quadratic::evaluate(double x) const{
	double total;
	//using the pow function to get the power of 2 (ax^2)
	//calling my getA(), getB(), getC() functions
	total = (getA() * pow(x, 2)) + (getB() * x) + getC();
	return total;
}

//precondition: going to check each cases to determine how many roots there are
//postcondition: going to then return the number of roots there is, each if statements will do the checking and tell us the roots
string Quadratic::numberOfRoots(){
	//if a, b, and c are all zero, then every value of x is a real root 
	//nested if statements
	if (getA() == 0) {
		if (getB() == 0) {
			if (getC() == 0) {
				return "infinity";
			}
			//else a and b are zero, but c is nonzero, then there are no real roots(return 0)
			else {
				return "0";
			}
		}
		//else a is zero, b is nonzero, then the only real root is x = -c/b
		else {
			return "1";
		}
	}
	//else a is nonzero (is a digit)
	else {
		//going to get the power of b (to the 2nd), call my getB() function
		double bTotal = pow(getB(), 2);
		//going to get the ac total, 4 times a times c, calling my getA() and getC() function;
		double acTotal = 4 * getA() * getC();

		//if b^2 < 4ac, then are no real roots
		if (bTotal < acTotal) {
			return "0";
		}
		//else if and b^2 = 4ac, then there is one real root
		else if (bTotal == acTotal) {
			return "1";
		}
		//else bTotal > acTotal (b^2 > 4ac), there are two roots
		else {
			return "2";
		}
	}
}
//precondition: going to get the smaller root, going to use the min
//postcondition: going to three statements to check, return the min, return the smallest number of this function
double Quadratic::smallerRoot(){
	//this is the discriminat formula D = b^2 - 4ac, using it for the quadratic formula
	double total = pow(getB(), 2) - 4 * getA() * getC();
	if (total > 0) {
		//using the quadratic formula, -b-(sqrt(b^2-4ac) / 2a, getting the min by calculating both roots
		//going to check which one is the smallest, calculate both - and +
		double root1 = (-b - sqrt(total)) / (2 * a);
		double root2 = (-b + sqrt(total)) / (2 * a);
		//getting the min, using the function min() to check which one was the smallest, if smallest then return min
		return min(root1, root2);
	}
}
//precondition: going to get the greatest root, going to use the max
//postcondition: going to three statements to check, return the min, return the greatest number of this function 
double Quadratic::greatestRoot(){
	//this is the discriminat formula D = b^2 - 4ac, using it for the quadratic formula
	double total = pow(getB(), 2) - 4 * getA() * getC();

	if (total > 0) {
		//using the quadratic formula, -b-(sqrt(b^2-4ac) / 2a, getting the min by calculating both roots
		//going to check which one is the greatest, calculate both - and +
		double root1 = (-b - sqrt(total)) / (2 * a);
		double root2 = (-b + sqrt(total)) / (2 * a);
		//getting the max, using hte function max()
		return max(root1, root2);
	}
}
//precondition: going to be printing out the information of the roots
//postcondition: going to call the numberOfRoots() functions to validate if its "infinity","1","2", if 2 call the real roots 
void Quadratic::getRealRoots(){
	//going to check each validation in the function numberOfRoots()
	//if the function in numberOfRoots() is infinity, run this
	if (numberOfRoots() == "infinity") {
		cout << "\n\tevery value of x is a real root";
	}
	//if the function in numberOfRoots() is 0, run this
	else if (numberOfRoots() == "0") {
		cout << "\n\tno real roots";
	}
	//else if the function in numberOfRoots() is 1, run this
	else if (numberOfRoots() == "1") {
		cout << "\n\tonly real root: 0";
	}
	//else 2 run this
	else {
		cout << "\n\ttwo real roots are: " << smallerRoot() << " and " << greatestRoot() << endl;
	}
}



