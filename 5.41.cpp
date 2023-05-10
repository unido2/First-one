#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int lenStr1(char*);
int lenStr2(char*);


int main() {
	setlocale(LC_ALL, "");

	const int size = 10;
	char str1[20] = "12345678";
	const char *str2 = "maa";
	char* c = &str1[0];
	
	//copyStr1(str1, str2);
	//copyStr2(str1, str2);
	cout << "LOLo" << endl;

	

	return 0;
}

int lenStr1 (char* s1) {

	for (int k=1;; k++,s1++) {
		if(*s1 == '\0')
			return k-1;
	}
}

int lenStr2(char* s1) {

	for (int k = 0;; k++) {
		if (s1[k] == '\0')
			return k;
	}
}