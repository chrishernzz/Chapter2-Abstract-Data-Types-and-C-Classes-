//name: Christian Hernandez
//date: 9/14/2023
//subscription: CMPR131

#include<iostream>
#include<random>
#include"input (1).h"
#include"Quadratic.h"
#include"Pseudorandom.h"
#include"Rational.h"
using namespace std;

//PROTOYPES
char menuOption();
void challenge1();
void challenge2();
void challenge3();

int main()
{
    do {
        switch (toupper(menuOption())) {
        case 'X': exit(1); break;
        case '1': challenge1(); break;
        case '2': challenge2(); break;
        case '3': challenge3(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return EXIT_SUCCESS;
}

//precondition: making a menu option
//postcondition: it will return an char (the choice of the menu)
char menuOption()
{
    system("cls");
    cout << "\n\tCMPR131 Chapter 2 - ADT Assignments by Christian Hernandez(9/14/2023)";
    cout << "\n\t" << string(78, char(205));
    cout << "\n\t\t1> Quadratic Expression";
    cout << "\n\t\t2> Pseudorandom";
    cout << "\n\t\t3> Rational Number";
    cout << "\n\t" << string(78, char(205));
    cout << "\n\t\tX> Exit";
    cout << "\n\t" << string(78, char(205));
    //calling the input.h and we are inputting numbers from 0 through 8
    return inputChar("\n\t\tOption: ",static_cast<string>(("123X")));
}

//precondition: going to call my class Quadratic Class
//postcondition: going to create a menu, then going to get the coefficients of a,b, and c. then return the real roots
void challenge1()
{
    system("cls");
    char option;
    Quadratic expression;
    do {
        cout << "\n\t1> - Quadratic Menu";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tD. display the expression";
        cout << "\n\t\tA. set coefficient (a)";
        cout << "\n\t\tB. set coefficient (b)";
        cout << "\n\t\tC. set coefficient (c)";
        cout << "\n\t\tE. get evaluation (x)";
        cout << "\n\t\tN. get the number of real roots";
        cout << "\n\t\tR. get real root(s)";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\t0. return";
        cout << "\n\t" << string(82, char(205)) << "\n";
        option = inputChar("\t\tOption: ", (static_cast<string>("DABCENR0")));

        switch (toupper(option)) {
        case 'D': {
            cout << "\n\t" << expression.getA() << "x^2 + " << expression.getB() << "x + " << expression.getC();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break; 
        case 'A': {
            expression.setA(inputInteger("\n\tEnter a value and set coefficient (a): "));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'B': {
            expression.setB(inputInteger("\n\tEnter a value and set coefficient (b): "));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'C': {
            expression.setC(inputInteger("\n\tEnter a value and set coefficient (c): "));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'E': {
            double x = inputInteger("\n\tEnter a value of x: ");
            cout << "\n\tEvaluation result: " << expression.evaluate(x);
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'N': {
            cout << "\n\tnumber of real roots: " << expression.numberOfRoots();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'R': {
            expression.getRealRoots();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}

//precondition: going to call my class Pseudorandom Class with 4 arguments (parameters) 
//postcondition: going creating a menu that will be able to give me the pseudorandom, going to get the seed, multiplier,modulus etc. 
void challenge2()
{
    system("cls");
    char option;
    int seedNum = 1, multiplierNum = 40, incrementNum = 725, modulusNum = 729;
    //constructor that takes in four arguments(parameters)
    Pseudorandom randomGenerator(seedNum,multiplierNum,incrementNum,modulusNum);
    do {
        cout << "\n\t2> - Pseudorandom Menu";
        cout << "\n\t" << string(87, char(205));
        cout << "\n\t\tA. get seed";
        cout << "\n\t\tB. set seed";
        cout << "\n\t\tC. get multiplier";
        cout << "\n\t\tD. set multiplier";
        cout << "\n\t\tE. get modulus";
        cout << "\n\t\tF. set modulus";
        cout << "\n\t\tG. get increment";
        cout << "\n\t\tH. set increment";
        cout << "\n\t\tI. get next number";
        cout << "\n\t\tJ. get indirect next number";
        cout << "\n\t\tK. run experiment with different values (multiplier, increment, and modulus)";
        cout << "\n\t" << string(87, char(205));
        cout << "\n\t\t0. return";
        cout << "\n\t" << string(87, char(205)) << "\n";
        option = inputChar("\t\tOption: ", (static_cast<string>("ABCDEFGHIJK0")));

        switch (toupper(option)) {
        case 'A': {
            cout << "\n\tseed: " << randomGenerator.getSeed();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'B': {
            randomGenerator.setSeed(inputInteger("\n\tEnter a value for seed: ",true));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'C': {
            cout << "\n\tmultiplier: " << randomGenerator.getMultiplier();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
               break;
        case 'D': {
            randomGenerator.setMultiplier(inputInteger("\n\tEnter a value for multiplier: ", true));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'E': {
            cout << "\n\tmodulus: " << randomGenerator.getModulus();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'F': {
            randomGenerator.setModulus(inputInteger("\n\tEnter a value for modulus: ", true));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'G': {
            cout << "\n\tincrement: " << randomGenerator.getIncrement();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'H': {
            randomGenerator.setIncrement(inputInteger("\n\tEnter a value for increment: ", true));
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'I': {
            cout << "\n\tnext number: " << randomGenerator.generateNextNumber();
            randomGenerator.permitChange();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'J': {
            cout << "\n\tindirect next number: "<<randomGenerator.generateIndirectNextNumber();
            randomGenerator.permitChange();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'K': {
            randomGenerator.displayGenerateGaussian();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}

//precondition: going to call my class Ratioan Class, pass two instances one with a default constructor and the other one with a constructor two argu(parameters)
//postcondition: going to create a menu that will let me get the *,/,+,-,==,<, using overloading operators
void challenge3()
{
    system("cls");
    char option;
    Rational rationalNum1;
    int numeratorDigit = 36, denominatorDigit = 6;
    Rational rationalNum2(numeratorDigit,denominatorDigit);
    do {
        cout << "\n\t3> - Rational Number Menu";
        cout << "\n\t" << string(87, char(205));
        cout << "\n\t\tA. enter values of rational number R1";
        cout << "\n\t\tB. display R1";
        cout << "\n\t\tC. enter values for rational number R2";
        cout << "\n\t\tD. display R2";
        cout << "\n\t\tE. multiplication of rational numbers (R1 * R2)";
        cout << "\n\t\tF. division of 2 rational numbers (R1 / R2)";
        cout << "\n\t\tG. addition of 2 rational numbers (R1 + R2)";
        cout << "\n\t\tH. subtraction 2 rational numbers (R1 - R2)";
        cout << "\n\t\tI. (R1 == R2)";
        cout << "\n\t\tJ. (R1 < R2)";
        cout << "\n\t" << string(87, char(205));
        cout << "\n\t\t0. return";
        cout << "\n\t" << string(87, char(205)) << "\n";
        option = inputChar("\t\tOption: ", (static_cast<string>("ABCDEFGHIJ0")));

        switch (toupper(option)) {
        case 'A': {
            try {
                int numerator = inputInteger("\n\tEnter the value for the numerator: ");
                int denominator = inputInteger("\n\tEnter the value for the denominator: ");

                //check first if denominator is 0, if yes then throw the exception right away so it does not run the program
                if (denominator == 0) {
                    throw Rational::ZeroDenominator();
                }
                rationalNum1.setNumerator(numerator);
                rationalNum1.setDenominator(denominator);
            }
            catch (Rational::ZeroDenominator) {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot have this Rational number with a zero denominator value.\n";
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'B': {
            cout << "\n\tRational number R1: " << rationalNum1.toString();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'C': {
            try {
                int numerator2 = inputInteger("\n\tEnter the value for the numerator: ");
                int denominator2 = inputInteger("\n\tEnter the value for the denominator: ");

                //check first if denominator is 0, if yes then throw the exception right away so it does not run the program
                if (denominator2 == 0) {
                    throw Rational::ZeroDenominator();
                }
                rationalNum2.setNumerator(numerator2);
                rationalNum2.setDenominator(denominator2);
            }
            catch (Rational::ZeroDenominator) {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot have this Rational number with a zero denominator value.\n";
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'D': {
            cout << "\n\tRational number R1: " << rationalNum2.toString();
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'E': {
            cout << "\n\tR1 * R2: " << rationalNum1* rationalNum2;
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'F': {
            cout << "\n\tR1 / R2: " << rationalNum1 / rationalNum2;
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'G': {
            cout << "\n\tR1 + R2: " << rationalNum1 + rationalNum2;
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'H': {
            cout << "\n\tR1 - R2: " << rationalNum1 - rationalNum2;
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'I': {
            cout << "\n\tR1 == R2: ";
            if (rationalNum1 == rationalNum2) {
                cout << "true";
            }
            else {
                cout << "false";
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'J': {
            cout << "\n\tR1 < R2: ";
            if (rationalNum1 < rationalNum2) {
                cout << "true";
            }
            else {
                cout << "false";
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case'0': {
            return;
        }
        }

    } while (true);
}



