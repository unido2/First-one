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
	

	srand(time(NULL));	
	
	while (k!=1) {
		
		shuffle(deck);
		deal(deck, face, suit);
		null1(deck, face_check, suit_check);
		k++;
	}
	cout << "razdach: " << k << endl;


	return 0;
}

void shuffle(int wDeck[][13]) {

	int row, col;

	for (int card = 1; card <= 52; card++) {
		row = rand() % 4;
		col = rand() % 13;
		while (wDeck[row][col] != 0) {
			row = rand() % 4;
			col = rand() % 13;
		}
		wDeck[row][col] = card;
	}
}

void deal(const int wDeck[][13], const char* wFace[],
	const char* wSuit[]) {

	void hand(int*, int*, const char* [], const char* [], int*);
	void best_hand(int [][2]);

	int high_card;
	int handss[2][2] = { 0 };

	int* fPtr = face_check,
		* SuitPtr = suit_check,
		* high_c = &high_card;

	for (int player = 1; player <= 2; player++) {
		cout << setw(20) << "Карты игрока #" << player << endl;
		for (int card = (player==1?1:(player*5-4)); card <= player*5; card++)
			for (int row = 0; row <= 3; row++)
				for (int col = 0; col <= 12; col++)
					if (wDeck[row][col] == card) {
						*fPtr = col;
						fPtr++;
						*SuitPtr = row;
						SuitPtr++;
						cout << card << ". " << setw(9) << setiosflags(ios::right) <<
							wFace[col] << " масти " << setw(5) <<
							wSuit[row]
							<< endl;	
					}

		hand(face_check, suit_check, wSuit, wFace, high_c);
		
		for (int i = player-1; i < player; i++) 
			for (int j = 0; j < 1; j++) {
				handss[i][j] = hand_com;
				handss[i][j+1] = *high_c;
			}
		hand_com = noun;
		fPtr = face_check;
		SuitPtr = suit_check;

		for (int i = 0; i < 5; i++)
			cout << fPtr[i]+2 << " ";
		cout << endl;

	}
	best_hand(handss);
}

void best_hand(int handss[][2]) {
	

	if (handss[0][0] == handss[1][0]) {
		if (handss[0][1] > handss[1][1])
			cout << "Первая рука сильнее!" << endl;
		else
			cout << "Вторая рука сильнее!" << endl;
	}
	else {
		if (handss[0][0] > handss[1][0])
			cout << "Первая рука сильнее!" << endl;
		else
			cout << "Вторая рука сильнее!" << endl;
	}
}

void hand(int *checkF, int *check_suit, const char * hSuit[],const char* hFace[],int *high_c) {
	
	void sort(int*);
	void max_card(int*, int*);
	void win_comb(int, int*);
	void printHands(const char*[], const char*[], int*, int);

	int k=1, pair=0,suit_hand,suit_i, streetF=0;
	int* su = &suit_hand;

	max_card(face_check, high_c);
	sort(face_check);
	hand_com = high;
	
	//poisk hand
	if (checkF[1] == checkF[0] + 1 && checkF[2] == checkF[1] + 1
		&& checkF[3] == checkF[2] + 1 && checkF[4] == checkF[3] + 1) {
		hand_com = street;
		streetF = checkF[0];
	}


	for (int i = 0; i < 4; i++) {
		k = 1;
		suit_i = 1;
		for (int j = i + 1; j < 5; j++) {
			if (hand_com != street && checkF[i] == checkF[j]) {
				k++;
				if (k == 4) {
					hand_com = kare;
					pair_track[3] = checkF[i];
					*high_c = checkF[i];
				}

				if (k == 3 && hand_com!=kare) {
					//if (pair == 1)
						//hand_com = full_house;
					pair = 0;
					hand_com = set;
					pair_track[2] = checkF[i];
					*high_c = checkF[i];
				}

				if (k == 2) {
					if (hand_com != set && hand_com != kare)
						pair++;
					else
						break;
					if (pair == 1) {
						if (hand_com == set) {
							hand_com = full_house;
							pair_track[0] = checkF[i];
						}
						else {
							hand_com = pare;
							pair_track[0] = checkF[i];
							*high_c = checkF[i];
						}
					}
					if (pair == 2) {
						hand_com = two_pare;
						pair_track[1] = checkF[i];
						if(*high_c<checkF[i])
							*high_c = checkF[i];
					}
				}

			}
			if (check_suit[i] == check_suit[j]) {
				suit_i++;
				if (suit_i == 5) {
					
					if (hand_com == street)
						hand_com = street_flush;
					else 
						hand_com = flushii;
					if (checkF[0] == 8 && checkF[1] == 9
						&& checkF[2] == 10 && checkF[3] == 11
						&& checkF[4] == 12)
						hand_com = flush_royal;
					else
						hand_com = flushii;
					
					suit_hand = check_suit[i];
				}
			}
		}

	}
	
	printHands(hFace,hSuit, su, streetF);
	cout << hand_com << hFace[*high_c] << endl;
}

void max_card(int* face_h_hand, int* high_c) {

	*high_c = face_h_hand[0];
	for (int i = 1; i <= 4; i++)
		if (face_h_hand[i] > *high_c)
			*high_c = face_h_hand[i];

}

void win_comb(int hand_com, int* high_c) {

}

void printHands(const char* hFace[], const char *hSuit[], int *suit_hand, int streetF) {
	
	if (hand_com == two_pare)
		cout << "Две пары " << hFace[pair_track[0]]
		<< " и " << hFace[pair_track[1]] << endl;

	if (hand_com == pare)
		cout << "Пара " << hFace[pair_track[0]] << endl;

	if (hand_com == set) {
		cout << "Сет из " << hFace[pair_track[2]] << endl;
		trip = yes;
	}
	
	if (hand_com == kare) {
		cout << "Каре из " << hFace[pair_track[3]] << endl;
		
	}
	
	if (hand_com==flushii) 
		cout << "Все карты одной масти (флеш): " << hSuit[*suit_hand] << endl;

	if (hand_com == street) 
		cout << "Стрит от " << hFace[streetF]<<" до "<< hFace[streetF+4] << endl;
}

void sort(int* face) {
	void swap(int*, int*);

	for (int i = 1; i < 5; i++)
		for (int j = 0; j < 4; j++)
			if (face[j] > face[j + 1])
				swap(&face[j], &face[j + 1]);
}

void swap(int* el1, int* el2) {		//sort func
	int temp = *el1;
	*el1 = *el2;
	*el2 = temp;
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