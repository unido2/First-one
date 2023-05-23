#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void makeLaby(int [][12]);
void printLaby(int const [][12]);
void labWalk(int [][12],int*,int*);
int checkStep(int lab[][12], int* row, int* col, int*, int*);
void step(int lab[][12], int* row, int* col, int*, int*);

int main() {
	setlocale(LC_ALL, "");

	const int s=12;
	int a = 4, b = 11;
	int Laby[12][12] = { 0 };

	srand(time(NULL));

	makeLaby(Laby);
	labWalk(Laby, &a, &b);
	
	return 0;
}

void labWalk(int lab[][12],int*row,int*col) 
{

	int direc[4] = { 0 }; //0-up,1-left,2-down,3-right
	int num = 0;
	char p[2];

	if (lab[*row][*col] != -1) {
		lab[*row][*col] = -1;
		printLaby(lab);
	}

	if (*row == 2 && *col == 0) 
	{
		cout << "you win!!" << endl;
		printLaby(lab);
	}

	else 
	{
		if (*col < 12 && *col >= 0 && *row < 12 && *row >= 0) {

			checkStep(lab, row, col, direc, &num);
			
			if (num != 0) {
				step(lab, row, col, direc, &num);
				
				cin.getline(p,2);
				printLaby(lab);
				labWalk(lab, row, col);
			}
			else
			{
				*row = 4;
				*col = 11;
				makeLaby(lab);
				labWalk(lab, row, col);
			}

		}
	}
}

int checkStep(int lab[][12], int* row, int* col, int *d, int *num)
{
	
	if (lab[*row - 1][*col] ==1)
		d[0]=1;
	if (lab[*row+1][*col] ==1)
		d[2]=1;
	if (lab[*row][*col-1] == 1)
		d[1]=1;
	if (lab[*row][*col + 1] == 1)
		d[3]=1;

	for (int i = 0; i < 4; i++) {
		cout << d[i] << "  ";
		if (d[i] != 0)
			*num = *num + 1;
	}
	cout << "num= " << *num << endl;
	
	return *num;
}

void step(int lab[][12], int* row, int* col, int* dir, int *numd)
{
	int d_choo, k,
		cho[3] = { 5,5,5 };

	for (int j = 0, i=0; j < 4; j++)
		if (dir[j] == 1) {
			cho[i] = j;
			i++;

		}

	for (int i=0;i<3;i++)
		cout << cho[i] << "  ";
	cout << endl;



	switch (*numd) {
	case 1:
		d_choo = cho[0];
		break;
	case 2:
		k = 1 + rand() % 2;
		d_choo = cho[k-1];
		break;
	case 3:
		k = 1 + rand() % 3;
		d_choo = cho[k-1];
		break;
	}


	switch (d_choo) {
	case 0:
		*row=*row-1;
		lab[*row][*col] = -1;
		break;
	case 1:
		*col=*col-1;
		lab[*row][*col] = -1;
		break;
	case 2:
		*row=*row+1;
		lab[*row][*col] = -1;
		break;
	case 3:
		*col=*col+1;
		lab[*row][*col] = -1;
		break;
	}

}

void makeLaby(int lby[][12])
{

	void randExitEntr(int*, int*);
	void labyFill(int[][12], int*, int*);

	//create outside walls
	int entr = 4, exi = 2;
	int lnum[10] = { 4,246789,1249,5679,123579,3579,13579,9,
					12345789,7 };

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++)
				lby[i][j] = 1;
	}
	// create enter and exit
	//randExitEntr(&exi, &entr); //func create randon enter and exit 
	lby[entr][11] = 1;
	lby[exi][0] = 1;

	// create inside walls
		for (int i = 1; i < 11; i++)
			labyFill(lby,&i, &lnum[i-1]);
}

void randExitEntr(int* ex, int* entr)
{
	*ex = 1 + rand() % 10;
	*entr = 1 + rand() % 10;
}

void labyFill(int lab[][12], int* ii, int *num) {
	int k = 0;
	int  n[10] = { 0 };
	do {
		n[k] = *num % 10;
		*num = *num / 10;
		k++;
	} while (*num != 0);

	for (int i = 0; i < k; i++) {
		lab[*ii][n[i]] = 0;
	}
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
				if (l[i][j] == -1)
					cout << "x";
				if (j >= 0 && j < 12 - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
