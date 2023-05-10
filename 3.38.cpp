
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int flip(void);

int main()
{
	int n,q,k=0,orel=0;
	char otvet;

	srand(time(NULL));
	q = flip();

	for (int i = 1; i>=0 ; i++) {
		k++;
		cin >> n;
		if (n == q) {
			q = flip();
			if (k < 10) {
				k = 0;
				cout << "You are lucky!" << endl;
			}
			if (k == 10) {
				k = 0;
				cout << " You know the secret!" << endl;
			}
			if (k > 10) {
				k = 0;
				cout << "Vy dolgny razvivat'sya" << endl;
			}
			cout << "Vi ugadali! Hotite sigrat' esche! (y or n)?" << endl;
			cin >> otvet;
			if (otvet == 'y')
				continue;
			else
				break;
		}
		if (n < q) {
			cout << "Slishkom malo! try again!" << endl;
			continue;
		}
		if (n > q) {
			cout << "Slishkim mnogo! try again!" << endl;
			continue;
		}

	}


	return 0;
}

int flip(void) {
	return 1 + rand() % 1000;;
}

 



