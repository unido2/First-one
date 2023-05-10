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
	
	const char* article[] = { "the","a","one","some","any" },
		* noun[] = { "itchy cat","sweety girl","sofa","town","serious boy" },
		* verb[] = {"kissed", "jumped", "ran", "freak out", "kicked" },
		* preposition[] = { "to","from","over","under","on" };
	int word;
	char string[50]="",string_clear[50]="";

	srand(time(NULL));

	for (int sentence = 1; sentence <= 20; sentence++) {
		
		for (int i = 1; i <= 6; i++) {
			word = rand() % 5;

			switch (i) {
			case 1:
				strcat(string, article[word]);
				break;
			case 2:
				strcat(string, noun[word]);
				break;
			case 3:
				strcat(string, verb[word]);
				break;
			case 4:
				strcat(string, preposition[word]);
				break;
			case 5:
				strcat(string, article[word]);
				break;
			case 6:
				strcat(string, noun[word]);
				break;
			}
			if (i != 6)
				strcat(string, " ");
		}

		string[0] = toupper(string[0]);
		strcat(string, ".");
		cout << string << endl;
		strcpy(string, string_clear);
	}

	return 0;
}