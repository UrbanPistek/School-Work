//Kathrine von Friedl 20760403
//Aurelie Sinclair 20784400
//Urban Pistek 20802700

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

class Polynomial {
protected:
	vector<int> pVector;
public:
	Polynomial(int A[], int size);
	Polynomial();
	Polynomial(string fileName);

	bool operator == (const Polynomial& target); //preforms *this == target
	void print(); //prints the polynomial (e.g., 2x^3 + 1x^0)

	Polynomial operator+(const Polynomial& target); //preforms *this + target
	Polynomial operator-(const Polynomial& target); //preforms *this - target
	Polynomial operator*(const Polynomial& target); //preforms *this * target

	Polynomial derivative(); //computes the derivative d/dx of *this

	~Polynomial(); //destructor the cleans up if needed
    friend class PolynomialTest;
};

#endif // IFNDEF POLYNOMIAL_H