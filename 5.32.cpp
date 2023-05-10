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
	
	char string1[80], string2[80];
	int amount;
	cout << "vvedite 2 stroki" << endl;
	cin >> string1 >> string2;
	cout << "print amount of symbols to compare:" << endl;
	cin >> amount;

	switch (strncmp(string1, string2,amount)) {
		case 0:
			cout << "Strings are equal";
			break;
		case 1:
			cout << "The first string is bigger than the second one";
			break;
		case -1:
			cout << "The second string is bigger than first one";
			break;
	}
	
	
	return 0;
}