#ifndef Quadratic_H
#define Quadratic_H

#include <iostream>
#include <string>
#include <cmath>
#include <complex>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class QuadraticF
{
	//standard form attributes
	double a;
	double b;
	double c;

	//factored form attributes
	complex<double> R1;
	complex<double> R2;
	
	//vertex from attributes
	double h;
	double k;

	//Functions to modify member attributes (private as should not be accessible by user)
	void CalcCfromFactor() { c = a * R1.real() * R2.real(); }
	void CalcBfromFactor() { b = -a * (R1.real() + R2.real()); }
	void CalcCfromVert() { c = k + (pow(b, 2) / (4 * a)); }
	void CalcBfromVert() { b = -2 * h * a; }
	void CalcR2fromStand() { R2 = complex<double>(-b / (2 * a)) - sqrt(complex<double>(pow(b, 2) - (4 * a * c))) / (complex<double>(2 * a)); }
	void CalcR1fromStand() { R1 = complex<double>(-b / (2 * a)) + sqrt(complex<double>(pow(b, 2) - (4 * a * c))) / (complex<double>(2 * a)); }
	void CalcKfromStand() { k = c - (pow(b, 2) / (4.0 * a)); }
	void CalcHfromStand();

public:
	//Constructor
	QuadraticF(char f=0 , double t1=0 , double t2=0 , double t3=0 ) ;

	//Methods to display values of functions
	void GetStandard() { cout << "Standard: " << a << ", " << b << ", " << c; }
	void GetFactored();			//GetFactored defined in cpp file as unsuitable for inline declaration.
	void GetVertex() { cout << "Vertex: " << a << ", " << h << ", " << k; }

	//Methods to modify standard form variables
	void ModStandardA(double A);
	void ModStandardB(double B);
	void ModStandardC(double C);

	//Methods to display full functions 
	void DispStandard();
	void DispFactored();
	void DispVertex();
	void DispAll();  
	
	//Operators
	QuadraticF operator+ (const QuadraticF& function) const { return QuadraticF('S', a + function.a, b + function.b, c + function.c); }
	friend QuadraticF operator* (int number, const QuadraticF& function);

};

void GetFunctionsFromFile(vector<QuadraticF>& FuncList, string FileName);


#endif
