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

	cin >> string1 >> string2;
	switch (strcmp(string1, string2)) {
		case 0:
			cout << "Stroki ravni";
			break;
		case 1:
			cout << "Pervaya stroka dlinnee vtoroy";
			break;
		case -1:
			cout << "Vtoraya stroka dlinnee pervoy";
			break;
	}
	
	//cout << "result: " << mistery(string1, string2) << endl;

	return 0;
}

