
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int creps();
int rolldice(void);


int main() {
	int bankBalance = 1000, wager, res;

	cout << "Sdelayte stavku: " << endl;
	cin >> wager;

	while (wager <= bankBalance) {
		res = creps();
		if (res == 1) {
			bankBalance += wager;
			cout << "Bank: " << bankBalance << endl;
		}
		else
			if (res == 0) {
				bankBalance -= wager;
				cout << "Bank: " << bankBalance << endl;
				if (bankBalance == 0) {
					cout << "Vy obankrotilis'" << endl;
					break;
				}
			}
		cout << "Sdelayte stavku: " << endl;
		cin >> wager;
		while (wager > bankBalance) {
			cout << "U vas net stol'ko deneg! Sdelayte stavku " << endl;
			cin >> wager;
		}

	}

	return 0;
}

int creps() {
	enum Status{ CONTINUE, WON, LOST};
	int sum, myPoint;
	Status gamestatus;
	srand(time(NULL));
	sum = rolldice();

	switch (sum) {
	case 7: case 11:
		gamestatus = WON;
		break;
	case 2: case 3: case 12:
		gamestatus = LOST;
		break;
	default:
		gamestatus = CONTINUE;
		myPoint = sum;
		cout << "Ochki: " << myPoint << endl;
		break;
	}

	while (gamestatus == CONTINUE) {
		sum = rolldice();
		if (sum == myPoint)
			gamestatus = WON;
		else
			if (sum == 7)
				gamestatus = LOST;
	}
	if (gamestatus == WON) {
		cout << "YOU WIN!" << endl;
		return 1;
	}
	else {
		cout << "YOU LOST!" << endl;
		return 0;
	}
}

int rolldice(void) {
	int die1, die2, worksum;
	
	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	worksum = die1 + die2;
	cout << "Brosok igroka " << die1 << " + " << die2 << " = "
		<< worksum << endl;
	return worksum;
}

 



