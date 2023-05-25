#include <iostream>

#ifndef Complex_h
#define Complex_h

class Complex {

public:
	Complex(double=0.0, double = 0.0,double = 0.0, double = 0.0);
	void setComplex();
	void sumComplex();
	void subsComolex();
	void print();

private:
	double MemNUm[2][2];
	double a, b,i; //1st copmlex number
	double aSum=0, bSum=0, aSub=0, bSub=0;
};

#endif // !Complex_h
