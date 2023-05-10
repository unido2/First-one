#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int mistery(const char *, const char*);


int main() {
	setlocale(LC_ALL, "");
	
	char string1[80], string2[80];

	cin >> string1 >> string2;

	cout << "result: " << mistery(string1, string2) << endl;

	return 0;
}

int mistery(const char* s1, const char* s2) {

	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
		if (*s1 != *s2)
			return 0;
	return 1;
}
