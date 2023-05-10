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
	
	const char* article[] = { "the","a","only","some","that" },
		* noun[] = { "zlata","nata","sky","river","anton" },
		* rhyme1[] = { "punk" , "dunk" , "clunk" , "funk" , "junk" ,"chunk" },
		* rhyme2[] = { "beaver", "silver" ,"lover" , "earthmover", "river","clover"},
		* verb[] = {"kissed", "jumped", "ran", "freak out", "kicked" },
		* preposition[] = { "to","from","over","under","on" };
	int word,word_rhyme;
	char string[50]="",string_clear[50]="";

	srand(time(NULL));

	for (int sentence = 1; sentence <= 5; sentence++) {
		
		for (int i = 1; i <= 6; i++) {
			word = rand() % 5;
			word_rhyme= rand() % 6;

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
				if(sentence==1 || sentence == 2 || sentence == 5)
					strcat(string, rhyme1[word_rhyme]);
				if(sentence == 3 || sentence == 4)
					strcat(string, rhyme2[word_rhyme]);
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