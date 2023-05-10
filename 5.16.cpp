#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum Status { no, yes };
Status  trip;
enum Combinations{noun=0,high,pare,two_pare,set,street,flushii,full_house,
				 kare,street_flush,flush_royal};
Combinations hand_com;

void numbering(int [][13]);
void printD(int [][13]);

void shuffle(int[][13]);
void deal(const int[][13], const char* [], const char* []);
void null1(int [][13], int*,int*);

int deck[4][13] = { 0 };
int face_check[5] = { 0 };
int suit_check[5] = { 0 };
int pair_track[4] = { 0 };

int main() {
	setlocale(LC_ALL, "");

	const char* suit[4] = { "Чирвы","Бубны","Трефы","Пики" };
	const char* face[13] = { "Двойка","Тройка","Четверка","Пятерка"
					,"Шестерка","Семерка","Восьмерка",
					"Девятка","Десятка","Валет","Дама","Король","Туз" };
	
	int k = 0;
	

	//srand(time(NULL));	
	
	numbering(deck);
	printD(deck);
	while (k < 4) {
		shuffle(deck);
		k++;
	}
	printD(deck);
	deal(deck, face, suit);
		
	//null1(deck, face_check, suit_check);

	cout << "razdach: " << k << endl;


	return 0;
}

void numbering(int deckk[][13]) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++) {
			if (i == 0)
				deckk[i][j] = (j + 1);
			if (i == 1)
				deckk[i][j] = (13 + j + 1);
			if (i == 2)
				deckk[i][j] = (26 + j + 1);
			if (i == 3)
				deckk[i][j] = (39 + j + 1);
		}
}

void printD(int deckk[][13]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++)
			cout << setw(3)<< deckk[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void shuffle(int wDeck[][13]) {

	int row, col, r_row, r_col,hold;

	for (int row = 0; row < 4; row++) {

		for (int col = 0; col < 13; col++) {
			r_row = rand() % 4;
			r_col = rand() % 13;
				hold = wDeck[row][col];
				wDeck[row][col] = wDeck[r_row][r_col];
				wDeck[r_row][r_col] = hold;
			
;		}

	}
}

void deal(const int wDeck[][13], const char* wFace[],
	const char* wSuit[]) {

	int* fPtr = face_check,
		* SuitPtr = suit_check;

	for (int card = 1; card <= 52; card++) {
		for (int row = 0; row <= 3; row++) {
			cout << row<<"--";
			for (int col = 0; col <= 12; col++) {
				cout << col << ".";
				if (wDeck[row][col] == card) {
					cout << card << ". " << setw(9) << setiosflags(ios::right) <<
						wFace[col] << " масти " << setw(5) <<
						wSuit[row]
						<< endl;
					row = 3;
					col = 12;
				}
			}
			cout << endl;
		}
	}
}

void null1(int table[][13], int *hand_f,int*hand_s) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			table[i][j] = 0;

	for (int i = 0; i < 5; i++) {
		hand_f[i] = 0;
		hand_s[i] = 0;
	}
}