
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int creps(int[], int);
int rolldice(void);


int main() {
	const int size = 10000;
	int res;
	int ves1=0, ves=0,total_w = 0, total_l = 0;
	int schetW_L[2] = { 0 }, win[22] = { 0 }, lost[22] = { 0 };

	srand(time(NULL));

	for (int i = 1; i <= size; i++) {
		res = creps(schetW_L, 2);

		if (schetW_L[0] < 21 || schetW_L[1] < 21) {
			if (res == 1)
				++win[schetW_L[1]];
			if (res == 0)
				++lost[schetW_L[0]];
		}
		else {
			if (res == 1)
				++win[21];
			if (res == 0)
				++lost[21];
		}

		schetW_L[0] = 0;
		schetW_L[1] = 0;
	}

	for (int j = 1; j < 22; j++)
		cout << setw(1) << "[" << j << "]";
	cout << endl;

	for (int j = 1; j < 22; j++) {
		cout << win[j] << "  ";
		total_w += win[j];
		ves += (win[j] + lost[j]) * j;
		ves1 += win[j] + lost[j];
	}
	cout << endl;

	for (int j = 1; j < 22; j++) {
		cout << lost[j] << "  ";
		total_l += lost[j];
	}
	cout << endl;
	cout << "Veroyatnost' Win:" << (float)total_w / size * 100 << endl
		<< "Veroyatnost' Loose:" << (float)total_l / size * 100 << endl
		<< "Srednyaya prodolzhitelnost': " << ves / ves1 << endl;

	return 0;
}

int creps(int schet[],int size) {
	enum Status{ CONTINUE, WON, LOST};
	int sum, myPoint,k=0;
	Status gamestatus;

	
	sum = rolldice();

	switch (sum) {
	case 7: case 11:
		++schet[1];
		gamestatus = WON;
		break;
	case 2: case 3: case 12:
		++schet[0];
		gamestatus = LOST;
		break;
	default:
		gamestatus = CONTINUE;
		myPoint = sum;
		break;
	}

	while (gamestatus == CONTINUE) {
		sum = rolldice();
		k++;
		if (sum == myPoint) {
			++schet[1]=k+1;
			gamestatus = WON;
		}
		else
			if (sum == 7) {
				++schet[0]=k+1;
				gamestatus = LOST;
			}
	}
	if (gamestatus == WON) {
		return 1;
	}
	else {
		if (gamestatus == LOST)
		return 0;
	}
}

int rolldice(void) {
	int die1, die2, worksum;


	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	worksum = die1 + die2;
	
	return worksum;
}

 



