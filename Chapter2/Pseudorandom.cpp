#include "Pseudorandom.h"

//precondition: scope class 
//postcondition: going to call my default constructor and initialize all privates seed,multiplier,increment,modulus,nextNumber, indirectNextNumber
Pseudorandom::Pseudorandom(int s, int m, int i, int mo): seed(s), multiplier(m), increment(i),modulus(mo), nextNumber(0){}

//precondition: going to get the next number (member function)
//postcondition: going to write down the formula to get my next number, then return the next number 
int Pseudorandom::generateNextNumber(){
	//formula for generating a sequence of pseudorandom numbers
	nextNumber = (multiplier * seed + increment) % modulus;
	return nextNumber;
}
//precondition: going to make sure the seed changes (member function)
//postcondition: going to return the seed which is equal to the nextNumber, seed will now have the next number
int Pseudorandom::permitChange(){
	seed = nextNumber;
	return seed;
}
//precondition: going to call my generateNextNumber() function
//postcondition: going to use static cast to convert to decimals, then return the total of it, divid the nextNumber with the modulus
double Pseudorandom::generateIndirectNextNumber(){
	//call my generateNextNumber() to generate the next pseudorandom number
	//but will not return the number directly, while calling this function
	//it will return the nextNumber divided the modulus (will be in range 0 to 1)
	generateNextNumber();
	//convert the nextNumber and modulus which are int to doubles by using static cast, get the total of that(the formula)
	double total = static_cast<double>(nextNumber) / static_cast<double>(modulus);
	return total;
}
//precondition: going to passed in 3 parameters (argu) that will tell me how many values, mean and the sd
//postcondition: going to then return a generateTotal, call my generateNumber() and getModulus() functions, push back the gaussianTotal
vector<double> Pseudorandom::generateGaussian(int values, double mean, double sd){
	vector<double> generateTotal;
	double sum = 0.0;
	for (int i = 0; i < values; ++i) {
		for (int j = 0; j < 12; ++j) {
			//call my generateNumber() and getModulus() functions to get the total of them
			double randomNumber = static_cast<double>(generateNextNumber()) / static_cast<double>(getModulus());
			sum += randomNumber;
		}
		//this is the gaussian sequence formula
		double gaussianTotal = mean + (sum - 6.0) * sd;
		generateTotal.push_back(gaussianTotal);
	}
	return generateTotal;
}
//precondition: going to be able to display the information
//postcondition: going to call my member function generateGaussian() to get the gaussian, then show the information
void Pseudorandom::displayGenerateGaussian(){
	const int SIZE = 10;
	double mean = 0.0, sd = 1.0;
	//keeping track of the number of occurrences, Size(10) , passed the mean and sd
	vector<double>numberOfOc = generateGaussian(SIZE, mean,sd);
	//doing the srand() so it can change random numbers and not be the same
	srand(time(0));
	//using the generate function to get the beginning and end of the vector size, then 3rd argu makes it rand()
	generate(numberOfOc.begin(), numberOfOc.end(), rand);
	//using the rand() to get random numbers
	setSeed(rand());
	setMultiplier(rand());
	setIncrement(rand());
	setModulus(rand());
	cout << "\n\t\texperiment of pseudorandom with random multiplier, increment and modulus: \n\n";
	cout << "\t\t" << string(76, char(205));
	cout << "\n\t\tmultiplier = " << getMultiplier() << ", increment = " << getIncrement() << ", modulus = " << getModulus();
	cout << "\n\n\t\tRange \t\tNumber of Occurrences";

	for (int i = 0; i < SIZE; i++) {
		cout << "\n\t\t["<< i / static_cast<double>(SIZE) << " ... " << (i + 1) / static_cast<double>(SIZE) << ")\t" << numberOfOc[i];
		numberOfOc[i] = static_cast<double>(rand()) / RAND_MAX;
	}
	//getting the standard deviation in the rand(values) in the gaussianSequence vector
	double sum = 0.0;
	for (double i : numberOfOc) {
		sum += pow(i - mean, 2.0);
	}
	double gaussianValue = sqrt(sum / SIZE);
	cout << "\n\n\t\tWith " << SIZE << " uniformly distributed rand number in the range[0...1.0),\n";
	cout << "\t\tthe approximate Gaussian distribution is "<< gaussianValue;
}

//precondition: going to get the seed
//postcondition: going to return the private seed
int Pseudorandom::getSeed() const{
	return seed;
}
//precondition: going to get the new seed
//postcondition: going to set the private seed with the new seed member, and get a random seed
void Pseudorandom::setSeed(int newSeed){
	seed = newSeed;
}

//precondition: going to get the multiplier
//postcondition: going to return the private multiplier
int Pseudorandom::getMultiplier() const{
	return multiplier;
}
//precondition: going to get the new multiplier
//postcondition: going to set the private multiplier with the new multiplier member
void Pseudorandom::setMultiplier(int newMultiplier) {
	multiplier = newMultiplier;
}

//precondition: going to get the modulus
//postcondition: going to return the private modulus
int Pseudorandom::getModulus() const {
	return modulus;
}
//precondition: going to get the new modulus
//postcondition: going to set the private modulus with the new modulus member
void Pseudorandom::setModulus(int newModulus) {
	modulus = newModulus;
}

//precondition: going to get the increment
//postcondition: going to return the private increment
int Pseudorandom::getIncrement() const {
	return increment;
}
//precondition: going to get the new increment
//postcondition: going to set the private increment with the new increment member
void Pseudorandom::setIncrement(int newIncrement) {
	increment = newIncrement;
}