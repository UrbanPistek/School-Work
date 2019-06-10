//Kathrine von Friedl 20760403
//Aurelie Sinclair 20784400
//Urban Pistek 20802700

#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include <fstream>
#include <time.h>
#include <algorithm>
#include <string>

using namespace std;
Polynomial::Polynomial(int* A, int size){
    pVector.resize(size);
    for (int index = 0; index < pVector.size(); index++){
        pVector[index]=A[index];
    }

}
Polynomial::Polynomial(){
    srand(time(0));
    pVector.resize(rand() % 1001); //generates a random number from 0 to 1000
    for (int index = 0; index < pVector.size() - 1; index++)
    {
        pVector[index] = (rand() % 2001) - 1000;
    }
    // std::random_device rd; // obtain a random number from hardware
    // std::mt19937 eng(rd()); // seed the generator
    // std::uniform_int_distribution<> distr(25, 63); // define the range
}
Polynomial::Polynomial(string fileName) {
    std::ifstream fin;
    fin.open(fileName.c_str());
    int polynomialSize = 0;
    fin >> polynomialSize;
    int temp = 0;
    for (int index = 0; index < polynomialSize; index++)
    {
        fin >> temp;
        pVector.push_back(temp);
    }
}

void Polynomial::print(){
    if(pVector.at(pVector.size() -1) != 0){
        cout << pVector.at(pVector.size()-1) << "x^" << pVector.size() - 1  << " ";
    }
    cout << showpos;
    for(int index = pVector.size() - 2; index > 0;index--){
        
        if(pVector.at(index)!=0){
            cout << pVector.at(index) << "x^" << index  << " ";
        }
    }
    if(pVector.at(0) != 0){
        cout << pVector.at(0);
    }
}
/*
bool Polynomial::operator== (const Polynomial& target)
{
    if (pVector.size() != target.pVector.size())
        return false;
    else {
        for (int index = 0; index < pVector.size() -1; index ++)
        {
            if (pVector[index] != target.pVector[index])
                return false;
        }
        return true;
    }
} //preforms *this == target

//void print(); //prints the polynomial (e.g., 2x^3 + 1x^0)

Polynomial Polynomial::operator+(const Polynomial& target){
    int maximum = max(pVector.size(), target.pVector.size());
    int* sum = new int[maximum];
    
    for (int index = 0; index < pVector.size() -1; index ++){
            sum[index] = pVector.at(index);
    }
    for (int index = 0; index < target.pVector.size() -1; index ++){
            sum[index] += target.pVector.at(index);
    }
    
    Polynomial pSum(sum,maximum);
    return pSum;
} //preforms *this + target

Polynomial Polynomial::operator-(const Polynomial& target){
    int maximum = max(pVector.size(), target.pVector.size());
    int* diff = new int[maximum];
    
    for (int index = 0; index < pVector.size() -1; index ++){
            diff[index] = pVector.at(index);
    }
    for (int index = 0; index < target.pVector.size() -1; index ++){
            diff[index] -= target.pVector.at(index);
    }
    
    Polynomial pDiff(diff,maximum);
    return pDiff;
} //preforms *this - target

Polynomial Polynomial::operator*(const Polynomial& target){
    int size = pVector.size()+ target.pVector.size();
    int* prod = new int[size];
    fill( prod, prod + size, 0 );

    for (int index = 0; index < pVector.size() - 1; index++){
        for (int index2 = 0; index2 < target.pVector.size() - 1; index++){
            prod[index*index2] += pVector.at(index) * target.pVector.at(index2); 
        }
    }
    Polynomial pProd(prod,size);
    return pProd;
} //preforms *this * target

*/
bool Polynomial::operator== (const Polynomial& target)
{
    if (pVector.size() != target.pVector.size())
        return false;
    else {
        for (int index = 0; index < pVector.size(); index++)
        {
            if (pVector[index] != target.pVector[index])
                return false;
        }
        return true;
    }
} //preforms *this == target

Polynomial Polynomial::operator+(const Polynomial& target){
    int maximum = max(pVector.size(), target.pVector.size());
    int* sum = new int[maximum];
    
    for (int index = 0; index < pVector.size(); index ++){
            sum[index] = pVector.at(index);
    }
    for (int index = 0; index < target.pVector.size(); index ++){
            sum[index] += target.pVector.at(index);
    }
    
    Polynomial pSum(sum,maximum);
    delete(sum);
    sum = NULL;
    return pSum;
} //preforms *this + target

Polynomial Polynomial::operator-(const Polynomial& target){
    int maximum = max(pVector.size(), target.pVector.size());
    int* diff = new int[maximum];
    
    for (int index = 0; index < pVector.size(); index ++){
            diff[index] = pVector.at(index);
    }
    for (int index = 0; index < target.pVector.size(); index ++){
            diff[index] -= target.pVector.at(index);
    }
    
    Polynomial pDiff(diff,maximum);
    delete(diff);
    diff = NULL;
    return pDiff;
} //preforms *this - target

Polynomial Polynomial::operator*(const Polynomial& target){
    int size = pVector.size()+ target.pVector.size()-1;
    int* prod = new int[size];
    fill( prod, prod + size, 0 );

    for (int index = 0; index < pVector.size(); index++){
        for (int index2 = 0; index2 < target.pVector.size(); index2++){
            prod[index + index2] += pVector.at(index) * target.pVector.at(index2); 
        }
	}
    Polynomial pProd(prod,size);
    delete(prod);
    prod = NULL;
    return pProd;
} //preforms *this * target

Polynomial Polynomial::derivative(){
    int size = pVector.size() - 1;
    int* div = new int[size];
    fill( div, div + size, 0 );

    for (int index = 0; index < size; index++){
        div[index] = (index + 1) * (pVector.at(index + 1));
    }
    Polynomial pDiv(div,size);
    return pDiv;
} //computes the derivative d/dx of *this

Polynomial::~Polynomial(){

} //destructor the cleans up if needed