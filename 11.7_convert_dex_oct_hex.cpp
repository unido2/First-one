#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;


int convertHexOctToDec(char* str) {

	int strToInt(char*);
	int hexToInt(char*);

	char temp[3];

	strncpy(temp, str, 2);
	temp[2] = '\0';
	//cout << temp << endl;

	if (temp[0] == '0' && (temp[1] == 'x' || temp[1] == 'X')) {// hex
		int length = strlen(&str[2]);
		int hex_numb = 0;
		int temp;
		
		for (int i = 2; str[i]!='\0'; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				temp = (str[i] - '0') * (int)pow(16, (length +1) - i);
			}
			else {
				temp = hexToInt(&str[i]) * (int)pow(16, (length + 1) - i);
			}
			hex_numb += temp;
		}
		return hex_numb;
	}
	else
		if (temp[0] == '0') {// oct
			int length = strlen(&str[1]);
			int oct_numb = 0;
			int temp_oct;

			for (int i = 1; str[i] != '\0'; i++) {
				if (str[i]== '8' || str[i] == '9') {
					return 0;
				}
				else {

					temp_oct = (str[i] - '0') * (int)pow(8, length - i);
					
				}
				oct_numb += temp_oct;
			}
			return oct_numb;
		}
		else// dec
			return strToInt(str);

}

int strToInt(char* s) {
	int length=strlen(s);
	int numb = 0;

	for (int i = 0; i <= length; i++) {
		int temp;
		temp = (s[i] - '0') * (int)pow(10, (length-1) - i);
		numb += temp;
	}
	return numb;
}

int hexToInt(char* s) {

	switch (*s) {
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	}
}

int main() {
	char n[4] = "546";
	char numb[10];
	int h=0;

	cin >> numb;
	h = convertHexOctToDec(numb);
	cout <<setiosflags(ios::showbase | ios::uppercase)
		 << "dec: "<<h<<"  oct: "<<oct<<h
		 <<"  hex: "<<hex<<h << endl;

	return 0;
}