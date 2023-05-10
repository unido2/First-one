#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void quicksort(int *, int const);
void print(int const *, int const *);

int main() {
	setlocale(LC_ALL, "");
	
	const int size = 10;
	int sorti[size] = { 37,2,6,4,89,8,10,12,68,45 };

	print(sorti, &size);
	quicksort(sorti, size);
	cout << "YAAYAA!!" << endl;
	print(sorti, &size);

	return 0;
}

void quicksort(int *massiv, int const  si) {
	int partition(int*, int*);
	
	int  searchy=si;

	if (si > 0) {
		
		searchy = partition(massiv, &searchy);
		quicksort(massiv, searchy);
		quicksort(&massiv[searchy+1], si-1 - searchy);
		
	}
	

}

int partition(int* s, int * size) {
	
	int hold, curI = 0,
		border = *size, rSort = 0, lSort = 0;


	for (;;) {

		for (int i = *size - 1; i > curI; i--) //proverka sprava
			if (s[curI] < s[i])
				rSort++;
	
		for (int j = 0; j < curI; j++) //proverka sprava
			if (s[curI] > s[j])
				lSort++;


		if ((rSort + lSort) == *size - 1) {
			//cout << "Mesto chisla " << s[curI] << " opredeleno"
			//	<< " ego poziciya: " << curI << endl;
			break;
		}
		else {
			rSort = 0;
			lSort = 0;
		}

		for (int i = border - 1; i > curI; i--) //perestanovka sprava
			if (s[i] < s[curI]) {
				hold = s[i];
				s[i] = s[curI];
				s[curI] = hold;
				border = curI;
				curI = i;
				//cout << "border1 " << border << endl;
				break;
			}


		for (int j = border+1; j < curI; j++) // perestanovka sleva
			if (s[j] > s[curI]) {
				hold = s[j];
				s[j] = s[curI];
				s[curI] = hold;
				border = curI;
				curI = j;
				//cout << "border2 " << border << endl;
				break;
			}

	}
	//print(s, size);
	return curI;
}

void print(int const* massi, int const *sizee) {
	
	for (int i=0; i<*sizee; i++)
		cout << massi[i] << "  ";
	cout<<endl;
}