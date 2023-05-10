#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void mystery1(char*, const char*);

int main() {
	setlocale(LC_ALL, "");

	char string1[80], string2[80];
	cout << "VVedite dve stoki:" << endl;
	cin >> string1 >> string2;
	mystery1(string1, string2);
	cout << string1 << endl;
	
	return 0;
}

void mystery1(char* s1, const char* s2) {
	while (*s1 != '\0')
		++s1;

	for (; *s1 = *s2; s1++, s2++)
		;
}