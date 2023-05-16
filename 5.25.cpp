#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void makeLaby(int [][12], const int *size);
void printLaby(int const [][12]);

int main() {
	setlocale(LC_ALL, "");

	const int s=12;
	int Laby[12][12] = { 0 };

	srand(time(NULL));

	//makeLaby(Laby, &s);
	printLaby(Laby);
	
	return 0;
}

void makeLaby(int lby[][12], const int* size) 
{

	void randExitEntr(int*, int*);
	//create Labyrynt:
	int entr, exi;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < *size-1; j++)
				lby[i][j] = 1;
	}
	cout << "HEH" << endl;
	randExitEntr(&exi, &entr);
	lby[entr][11] = 1;
	lby[exi][0] = 1;
	
}
void randExitEntr(int* ex, int* entr)
{
	*ex = 1 + rand() % 10;
	*entr = 1 + rand() % 10;
}

void printLaby(int const l[][12]) 
{

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				if (l[i][j] == 1)
					cout << ".";
				else
					if(l[i][j]==0)
					cout << "#";
				if (j >= 0 && j < 12 - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
