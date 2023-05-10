#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void revLimeric(char*, char*);

int main() {
	setlocale(LC_ALL, "");

	int i=0;

	char* senPtr,*str;
	char string[50], stringget[50]="", stringclr[50] = "", stringhold[50]="", rev[50]="";
	
	str = stringhold;

	//srand(time(NULL));
	cin.getline(string, 50, '\n');

	senPtr = strtok(string, " ");
	while (senPtr != NULL) {
		i++;
		if (i != 1) {
			strcpy(stringget, senPtr);
			strcat(strcat(stringget," "), stringhold);
			strcpy(stringhold, stringget);
			strcpy(stringget, stringclr);
		}
		else {
			//strcpy(stringget, senPtr);
			strcat(stringhold, senPtr);
		}
		senPtr = strtok(NULL, " ");
	}

	cout << stringhold << endl;

	senPtr = strtok(stringhold, " ");
	while (senPtr != NULL) {
		cout << senPtr << endl;
		senPtr = strtok(NULL, " ");
	}

	return 0;
}