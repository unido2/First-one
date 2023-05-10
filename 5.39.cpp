#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void copyStr1(char*,const char*,int*);
void copyStr2(char*, const char*);
void addStr1(char*, const char*);
void addStr2(char*, const char*);


int main() {
	setlocale(LC_ALL, "");

	const int size = 10;
	char str1[20] = "uka-";
	const char *str2 = "mat123";
	char* c = &str1[0];
	int oo;
	
	//copyStr1(str1, str2);
	//copyStr2(str1, str2);
	//cout << sizeof(char) << endl;

	copyStr1(str1, str2,&oo);
	cout << str1 << endl;


	return 0;
}

void copyStr1 (char* s1, const char* s2,int*n) {
	for (; *s2!='\0'; s1++, s2++) {
		*s1 = *s2;
	}
}

void copyStr2(char* s1, const char* s2) {
	for (int i=0; (s1[i] = s2[i]) != '\0'; i++)
		;
}

void addStr1(char* s1, const char* s2) {
	for (; *s2 != '\0'; s1++) {
		if (*s1 == '\0')
			for (; (*s1 = *s2) != '\0'; s1++, s2++)
				;
	}
}

void addStr2(char* s1, const char* s2) {
	for (int i=0;; i++) {
		if (s1[i] == '\0')
			for (int j=0; (s1[i] = s2[j]) != '\0';j++,i++)
				;
		if (s1[i] == '\0')
			break;
	}
}