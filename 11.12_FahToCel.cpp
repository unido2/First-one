#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;


int main(){

	float Cel;
	char str[50];
	char s[3];

	for (int fah = 0; fah <= 212; fah++) {

		Cel = 5.0 / 9.0 * (fah - 32);
		cout << resetiosflags(ios::showpos)<< setw(3)<<fah << " *F" 
			<< setw(10)<< setiosflags(ios::fixed | ios::showpos)
			<< setprecision(3) << Cel << setw(3) << "*C" << endl;
			
	}


	return 0;
}