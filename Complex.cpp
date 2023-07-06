#include <iostream>
#include "Complex.h"
#include <math.h>


Complex::Complex(double a1,double b1, double a2, double b2) {
	MemNUm[0][0] = a1;
	MemNUm[0][1] = b1;
	MemNUm[1][0] = a2;
	MemNUm[1][1] = b2;
}

void Complex::setComplex() {
	int count = 0;

	do {
		count++;

		if (count == 1) {
			std::cout << "vvedite z1=a1+b1i: " << std::endl << "a1= ";
			std::cin >> MemNUm[0][0];
			std::cout << "b1= ";
			std::cin >> MemNUm[0][1];
			std::cout << std::endl;
		}
		else {
			std::cout << "vvedite z2=a2+b2i: " << std::endl << "a2= ";
			std::cin >> MemNUm[1][0];
			std::cout << "b2= ";
			std::cin >> MemNUm[1][1];
			std::cout << std::endl;
		}
	} while (count != 2);
}

void Complex::sumComplex() {
	aSum = MemNUm[0][0] + MemNUm[1][0];
	bSum = MemNUm[1][1]+ MemNUm[0][1];
}

void Complex::subsComolex() {
	aSub = MemNUm[0][0] - MemNUm[1][0];
	bSub = MemNUm[1][1] - MemNUm[0][1];
}

void Complex::print() {
	std::cout << "Summa compleksnix chisel z = " << aSum <<
		(bSum<0?" - ":" + ") << abs(bSum) << "i" << std::endl;
	std::cout << "Raznica compleksnix chisel z = " << aSub <<
		(bSub < 0 ? " + " : " - ") << abs(bSub) << "i" << std::endl;
}