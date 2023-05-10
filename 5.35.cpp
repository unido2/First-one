#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void printLatinWord(char* word);

int main() {
	setlocale(LC_ALL, "");

	int word,word_rhyme;
	char* senPtr;
	char string[50]="man this is tough shiit", string_clear[50] = "";

	//srand(time(NULL));
	cout << string << endl;
	senPtr = strtok(string, " ");
	while (senPtr != NULL) {
		printLatinWord(senPtr);
		senPtr = strtok(NULL, " ");
	}
	cout << endl;
	return 0;
}

void printLatinWord(char* word) {
	char letterF = word[0],
		stringNon[2]="",
		stringLat[20] = "",
		stringClear[20] = "";


	for (int i = 1; word[i] != '\0'; i++) {
		stringNon[0] = word[i];
		strcat(stringLat, stringNon);
	
	}

	stringNon[0] = word[0];
	strcat(stringLat, stringNon);
	strcat(stringLat, "ay");

	cout << stringLat << " ";
	strcpy(stringLat, stringClear);

}