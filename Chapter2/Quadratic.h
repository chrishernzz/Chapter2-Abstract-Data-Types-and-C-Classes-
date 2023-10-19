#pragma once
#include<iostream>
#include<string>
#include<cmath>
using namespace std; 

//precondition: going to create the class that has the information of quadratic
//postcondition: going to create a default constructor, accessors, mutators, evaluate for x, numberOfRoots
class Quadratic{
private:
	double a, b, c;
public:
	//default constructor
	Quadratic();

	//getters(accessors)
	double getA() const;
	double getB() const;
	double getC() const;
	//setters(mutators)
	void setA(double newA);
	void setB(double newB);
	void setC(double newC);
	
	//evaluate the quadratic expression at a particular value of x
	double evaluate(double x) const;

	//returns the number of real roots of a quadratic expression
	string numberOfRoots();
	
	//two member functions that calcualte and return the real roots of a quadratric expression
	//smallest root member function
	double smallerRoot();
	//greatest root member function
	double greatestRoot();
	//this member function is going call the numberOfRoots() funciton and the smallerRoot() and greatestRoot()
	void getRealRoots();
};

