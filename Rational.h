#include <iostream>

#ifndef Rational_h
#define Rational_h

class Rational {

public:
	Rational(int=0,int=0,int=0,int=0);
	void setRational(int,int,int,int);
	void sumRational();
	void subRational();
	void print();

private:
	enum number { null, fraction };
	number n1, n2;
	void setDefault(int);
	void EvkliedNum(int*, int*);
	int m[2][2];
	int c1=0, c2=0;
};

#endif // !Rational_h
