#include <iostream>
#include "Rational.h"
#include <math.h>


Rational::Rational(int a1,int a2,int b1,int b2) {
	setRational(a1, a2, b1, b2);
}


void Rational::setRational(int a1,int a2,int b1, int b2) {
	int div;

	if (a2 == 0) {
		n1 = null;
		setDefault(1);
	}
	else {
		if (a1 != 0) {
			n1 = fraction;
			EvkliedNum(&a1, &a2);
			m[0][0] = a1;
			m[0][1] = a2;
		}
		else {
			n1 = null;
			setDefault(1);
		}
	}

	if (b2 == 0) {
		n2 = null;
		setDefault(2);
	}
	else{
		if (b1 != 0) {
			n2 = fraction;
			EvkliedNum(&b1, &b2);
	
			m[1][0] = b1;
			m[1][1] = b2;
		}
		else {
			n2 = null;
			setDefault(2);
		}
	}
}

void Rational::sumRational() {


	if(n1==null || n2==null)
		if (n1 == null) {
			c1 = m[1][0];
			c2 = m[1][1];
		}
		else {
			c1 = m[0][0];
			c2 = m[0][1];
		}
	else {
		if (m[0][1] != m[1][1]) {
			c1 = m[1][1] * m[0][0] + m[0][1] * m[1][0];
			c2 = m[0][1] * m[1][1];
			EvkliedNum(&c1, &c2);
		}
		else {
			c1 = m[0][0] + m[1][0];
			c2 = m[0][1];
			EvkliedNum(&c1, &c2);
		}
	}
}

void Rational::print() {
	std::cout << "a= "<< m[0][0] << "/" << m[0][1] << '\n';
	std::cout <<"b= "<< m[1][0] << "/" << m[1][1] << '\n';
	std::cout << "c= " << c1 << "/" << c2 << '\n';

	setDefault(3);
}


//private func-s
void Rational::EvkliedNum(int *numer, int *denom) {
	int k = 1,
		a = *numer,
		b = *denom;

	do {
		k = a % b;
		if (k == 1) {
			break;
		}
		a = b;
		b = k;
	
	} while (k != 0);
	
	if (k == 0) {
		*numer /= a;
		*denom /= a;
	}
}

void Rational::setDefault(int opt) {
	switch (opt) {
	case 1:
		for (int i = 0; i < 2; i++)
			m[0][i] = 0;
		break;
	case 2:
		for (int i = 0; i < 2; i++)
			m[1][i] = 0;
		break;
	case 3:
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				m[i][j] = 0;
		break;
	}
	c1 = 0;
	c2 = 0;
}

