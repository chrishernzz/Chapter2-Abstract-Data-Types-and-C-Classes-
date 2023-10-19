#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

//precondition: going to create the class that has the information of a pseudorandom
//postcondition: going to create a constructor, generate next num, change seed, generate indirect next num, accessors, mutators
class Pseudorandom{
private:
	int seed, multiplier, increment,modulus;
	int nextNumber;
public:
	//constructor with 4 arguments
	Pseudorandom(int s, int m, int i, int);
	
	//member function to generate and return the next number in the pseudorandom sequence
	int generateNextNumber();
	//member function to permit the seed to be changed
	int permitChange();
	//member function generates the next pseudorandom number but does not return the number directly
	double generateIndirectNextNumber();

	//member function that produces a sequence of pseudorandom numbers with approximate Gaussian distribution
	vector<double> generateGaussian(int values, double mean, double sd);
	//member function that displays the random generator
	void displayGenerateGaussian();

	//getters(accessors)
	int getSeed() const;
	int getMultiplier() const;
	int getModulus() const;
	int getIncrement() const;
	//setters(mutators)
	void setSeed(int newSeed);
	void setMultiplier(int newMultiplier);
	void setModulus(int newModulus);
	void setIncrement(int newIncrement);
};

