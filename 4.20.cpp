
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int search(int[], int,int);
void print_seat(int[],int);


int main() {
	const int size = 10;
	int salon[size] = { 0 };
	int a, b;

	do {
		cout << "Vvedite 1 dlya 'kuryag'" << endl
			 << "Vvedite 2 dlya 'nekur'" << endl;
		cin >> a;
		b=search(salon, size, a);
		print_seat(salon, size);

	} while (salon[9] == 0 || salon[4] ==0);
	
	return 0;
}

int search(int seat[], int size, int choise) {
	static int k = 0;
	char ans;

	if (choise == 1) {
		for (int i = 0; i < 5; i++) {
			if (seat[i] == 0) {
				seat[i] = 1;
				break;
			}
		}
		if (seat[4] == 1 && seat[9] == 0) {
			cout << "Ustroit li vas nekuryashchiy salon? y/n" << endl;
			cin >> ans;
			if (ans == 'y')
				choise == 2;
			else
				cout << "Sleduyshiy polet budet cherz 3 chasa" << endl;
		}
		if (seat[9] == 1 && seat[4] == 1)
			cout << endl << "MEST Net! Sleduyshiy polet budet cherz 3 chasa"
				 << endl << endl;
		
	}
	if (choise == 2) {
		for (int i = 5; i < 10; i++) {
			if (seat[i] == 0) {
				seat[i] = 1;
				k++;
				break;
			}
		}
		if (seat[9] == 1 && seat[4] == 1)
			cout << endl << "MEST Net! Sleduyshiy polet budet cherz 3 chasa"
			<< endl << endl;
	}
	return 0;

}

void print_seat(int seat[],int size) {
	for (int i = 0; i < 5; i++)
		cout << seat[i] << "  ";
	cout << "| ";
	for (int i = 5; i < size; i++)
		cout << seat[i] << "  ";
	cout << endl;
}


 



