#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main() {
	setlocale(LC_ALL, "");

	int word,word_rhyme,i=0, numb;

	char* senPtr, *tempPtr;
	char string[50];
	

	//srand(time(NULL));
	cin.getline(string, 50, '\n');

	senPtr = strtok(string, " ");
	while (senPtr != NULL) {
		i++;

		cout << senPtr << endl;

		senPtr = strtok(NULL, " ");
	}


	return 0;
}
