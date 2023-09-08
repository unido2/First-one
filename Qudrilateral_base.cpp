#include<iostream>
#include<cmath>
#include<iomanip>
#include "Qudrilateral_base.h"

using namespace std;

Qudrilateral::Qudrilateral(int* x, int* y)
{
	x_co = new int[4];
	y_co = new int[4];

	for (int i = 0; i < 4; i++) {
		x_co[i] = x[i];
		y_co[i] = y[i];
	}

}
Qudrilateral::~Qudrilateral()
{
	delete[] x_co;
	delete[] y_co;
}

void Qudrilateral::ShapeName()
{
	cout << "Qudrilateral:" << endl;
}

void Qudrilateral::printShape()
{
	int** board = new int *[20];
	
	for(int i=0;i<20;i++)
		board[i] = new int[20] {0};
	
		for (int j = 0; j < 4; j++) 
			board[y_co[j]][x_co[j]] = 1;


	for (int i = 0; i < 4; i++)
		cout << "Point " << i + 1 << " [" << x_co[i] << ',' << y_co[i] << "];" << endl;
	for (int i = 0; i < 4; i++)
		cout << "Side " << i + 1 << " = " << getSide(i + 1) << (i != 3 ? ',' : '\n');

	for (int i = 0; i < 20; i++) {
		if (i == 0 || i == 19)
			cout << setw(3)<<(i == 0 ? "(19)" : "(0) ");
		else
			cout <<setw(5);
		for (int j = 0; j < 20; j++) {
			if (board[19-i][j] == 0)
				cout <<"/" << " ";
			else
				cout << "o" << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < 20; i++)
		delete[] board[i];
	delete[] board;

}

int Qudrilateral::getSide(int a) const
{
	if (a >= 1 && a <= 3)
		return (int)sqrt(x_co[a - 1] * x_co[a - 1] + y_co[a] * y_co[a]);
	if (a == 4)
		return (int)sqrt(x_co[a - 1] * x_co[a - 1] + y_co[0] * y_co[0]);
	return 0;
}


bool Qudrilateral::CheckQudri() const
{
	return true;
}
