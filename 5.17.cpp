#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



void printHill(int * hill, int* zaya_c, int* che_c);
void lets_walk(int*, int*);

enum Dvig_che { Bistro_r = 3, Skolz_l = 6, Medleno_r = 1 };
enum Turn_che { Left_c, Right_c };
enum Dvig_zaya { Son = 0, Big_jump_r = 9, Heavy_slide_l = 12, Little_jump_r = 1, easy_slide_l = 2 };
enum Turn_zaya { Noun, Left, Right };

Dvig_che che_step;
Turn_che che_turn;
Dvig_zaya zay_step;
Turn_zaya zay_turn;

int main() {
	setlocale(LC_ALL, "");

	char str[1];
	int hill[90] = { 0 };
	int k = 1,z_step,c_step,m;
	int zaya_c = 1,
		che_c = 1;
	

	srand(time(NULL));

	while (k>0) {
		
		if(k==1)
			printHill(hill, &zaya_c, &che_c);
		lets_walk(&zaya_c, &che_c);
		printHill(hill, &zaya_c, &che_c);
		

		if (zaya_c >= 70 && che_c >= 70) {
			cout << "Nichya!" << endl;
			break;
		}
		if(zaya_c>=70){
			cout << "zaya WINN!" << endl;
			break;
		}
		if (che_c >= 70) {
			cout << "Cherepaha WINN!" << endl;
			break;
		}
		k++;
		cin.getline(str, 1);
	}
	

	return 0;
}

void lets_walk(int* zay_c, int* che_c) {
	void che_rand_step();
	void zaya_rand_step();

	zaya_rand_step();
	che_rand_step();

	//cout << "zay_turn " <<zay_turn << " zay_step " << zay_step << endl;

	//proverka pervogo hoda
	if (*zay_c == 1 && zay_turn == Left) {
		do {
			zaya_rand_step();
		} while (zay_turn != Right);
	}

	if (*che_c== 1 && che_turn == Left_c) {
		do {
			che_rand_step();
		} while (che_turn != Right_c);
	}
	//cout << "zay_turn(-) " << zay_turn << " zay_step(-) " << zay_step << endl;

	//zaya walk
	if (zay_turn == Noun)
		cout << "Зая спит" << endl;

	if (zay_turn == Left) {
		*zay_c =*zay_c - zay_step;

		if (*zay_c < 1) {
			*zay_c = *zay_c + zay_step;
			do {
				zaya_rand_step();
			} while (zay_turn != Right);
		}
		else
			cout << "Зая влево на " << zay_step << " клеток" << endl;
	}

	if (zay_turn == Right) {
		*zay_c = *zay_c + zay_step;
		cout << "Зая вправо на " << zay_step << " клеток" << endl;
	}
			
	//che walk
			if (che_turn == Left_c) {
				*che_c = *che_c - che_step;

				if (*che_c < 1) {
					*che_c = *che_c + che_step;
					do {
						che_rand_step();
					} while (che_turn != Right_c);
				}
				else
					cout << "Черепах влево на " << che_step << " клеток" << endl;
				
			}
			if (che_turn == Right_c) {
				*che_c = *che_c + che_step;
				cout << "Черепах вправо на " << che_step << " клеток" << endl;
			}
				
			cout << "Зая на: " << *zay_c << endl
			   	 << "Черепаха на: " << *che_c << endl;
}


void che_rand_step() {

		int rand_i = 1 + rand() % 10;

		//cherepah vybor dvigeniya
		if (rand_i >= 1 && rand_i <= 5) {
			che_step = Bistro_r;
			che_turn = Right_c;
		}
		if (rand_i == 6 || rand_i == 7) {
			che_step = Skolz_l;
			che_turn = Left_c;
		}
		if (rand_i >= 8 && rand_i <= 10) {
			che_step = Medleno_r;
			che_turn = Right_c;
		}
	}

void zaya_rand_step() {

		int rand_i = 1 + rand() % 10;

		//zayac vybor dvigeniya
		if (rand_i == 1 || rand_i == 2) {
			zay_step = Son;
			zay_turn = Noun;
		}
		if (rand_i == 3 || rand_i == 4) {
			zay_step = Big_jump_r;
			zay_turn = Right;
		}
		if (rand_i == 5) {
			zay_step = Heavy_slide_l;
			zay_turn = Left;
		}
		if (rand_i >= 6 && rand_i <= 8) {
			zay_step = Little_jump_r;
			zay_turn = Right;
		}
		if (rand_i == 9 || rand_i == 10) {
			zay_step = easy_slide_l;
			zay_turn = Left;
		}
	}

void printHill(int *hill, int *zaya_c, int *che_c) {
	cout << endl;
	cout << setw(35) << "---REeeal RACE---" << endl;

	for (int i = 1; i <= 70; i++) {
		if (i == 1)
			cout <<setw(2)<< 1;
		if (i!=1 || i!=35 || i!=70 )
			cout <<setw(2)<< ".";
		if (i == 35)
			cout << 35;
		if (i == 70)
			cout << 70;

	}
	cout << endl;

	for (int i = 1; i <= 70; i++) {

		if (hill[i] == 0)
			cout <<setw(2)<< " ";

		if (i == *zaya_c && i == *che_c && i != 1)
			cout << "Ох!!!";
		else {
			if (i == *zaya_c)
				cout << "З";
			if (i == *che_c)
				cout << "Ч";
		}

	}
		cout << endl<<endl;
	

}

