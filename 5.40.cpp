#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int compStr1(char*,const char*);
int compStr2(char*, const char*);


int main() {
	setlocale(LC_ALL, "");

	const int size = 10;
	char str1[20] = "mac";
	const char *str2 = "maa";
	char* c = &str1[0];
	
	//copyStr1(str1, str2);
	//copyStr2(str1, str2);
	
	//cout << strcmp(str1, str2) << endl;
	cout<<compStr2(str1, str2)<<endl;
	//cout << str1 << endl;

	return 0;
}

int compStr1 (char* s1, const char* s2) {
	int k1=0,k2 = 0;

	for (; *s1 != '\0' || *s2 != '\0'; k1++,s1++, s2++) {
		//cout << (int) s1%100<<"__"<<(int)s2%100 << endl;
		if ((int)*s1 > (int)*s2)
			return 1;
		if ((int)*s1 < (int)*s2)
			return -1;
		if ((int)*s1 == (int)*s2)
			k2++;
		if (k1 == k2)
			return 0;
		
	}
}

int compStr2(char* s1, const char* s2) {
	int k = 0;
	for (int i=0,j=0; s1[i] != '\0' || s2[j] != '\0'; i++, j++) {
		//cout << (int) s1%100<<"__"<<(int)s2%100 << endl;
		if ((int)s1[i] > (int)s2[j])
			return 1;
		if ((int)s1[i] < (int)s2[j])
			return -1;
		if ((int)*s1 == (int)*s2)
			k++;
		if (k==i && k==j)
			return 0;

	}
}
