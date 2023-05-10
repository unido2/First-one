
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum Turn { LEFT, RIGHT };
enum Pen { YES, NO };
enum Pos { WALK, STAY };
Pos p_turt;
Turn turt_turn;
Pen turt_write;

void turtle_cmnd(int[][20], Turn, Pen,Pos);
void print_turtle(int[][20],int [],Pos);
void turt_move(int[][20],int [], Turn, Pen, int, int, int);


int main() {

	const int size_row = 20, size_column = 20;
	int floor[size_row][size_column] = {0};

	turtle_cmnd(floor, turt_turn,turt_write,p_turt);
	
	return 0;
}

void turtle_cmnd(int f[][20], Turn turt_turn, Pen turt_write, Pos p_turt) {
	
	int comnd1,comnd2;
	int pos_l = 0, pos_r = 4;
	static int cur[2] = { 10,10 };

	turt_write = NO;

	do {
		cin >> comnd1;
		if (comnd1 == 5)
			cin >> comnd2;
		switch (comnd1) {
		case 1:
			turt_write = NO;
			break;
		case 2:
			turt_write = YES;
			break;
		case 3:
			turt_turn = RIGHT;
			pos_r--;
			if (pos_r < 1)
				pos_r = 4;
			break;
		case 4:
			turt_turn = LEFT;
			pos_l++;
			if (pos_l > 3)
				pos_l = 0;
			break;
		case 5:
			turt_move(f,cur, turt_turn, turt_write,pos_r, pos_l, comnd2);
			break;
		case 6:
			print_turtle(f,cur,p_turt);
			break;
		case 9:
			cout << "THE END" << endl;
			break;
		}
	
	} while ((comnd1) != 9);
}

void turt_move(int mo[][20],int cur[], Turn turt_do,Pen write, int pos_r, int pos_l, int step) {
	static int c_row = 10, c_col = 10;
	int move;

	if (turt_do == LEFT)
		move = pos_l;
	if (turt_do == RIGHT)
		move = pos_r;

	switch (move) {
	case 1:
		if (write == YES)
			for (int i = 0; i < step; i++)
				mo[c_row][c_col + i] = 1;
		c_col += step-1;
		break;		
	case 2:
		if (write == YES)
		for (int i = 0; i < step; i++)
			mo[c_row - i][c_col] = 1;
		c_row -= step-1;
		break;
	case 3:
		if (write == YES)
		for (int i = 0; i < step; i++)
			mo[c_row][c_col - i] = 1;
		c_col -= step-1;
		break;
	default:
		if (write == YES)
		for (int i = 0; i < step; i++)
			mo[c_row + i][c_col] = 1;
		c_row += step-1;
		break;
	}
	cur[0]=c_row;
	cur[1]=c_col;
}

void print_turtle(int f[][20],int cur[], Pos p_turt) {

	cout << cur[0] << ".." << cur[1] << endl;
	for (int i = 0; i < 20; i++)
		cout << i<<" ";
	cout << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == cur[0] && j == cur[1]) 
				cout << "o";
			else {
				if (f[i][j] == 1)
					cout << "*";
				if (f[i][j] == 0)
					cout << "-";
			}
		}
		cout << endl;
	}

}

