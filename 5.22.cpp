#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int mystery2(const char*);

int main() {
	setlocale(LC_ALL, "");

	char string[80];
	cout << "VVedite dve stoki:" << endl;
	cin >> string;
	cout << mystery2(string) << endl;
	
	return 0;
}

int mystery2(const char* s) {
	int x;

	for (x=0; *s != '\0'; s++)
		++x;
	return x;
}