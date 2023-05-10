
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum Done { NO, YES };

Done konyk;

void print_board(int[][8]);
int kon_hod(int [][8],int [], int [], int &, int &,int);
void null(int[][8]);
int board_done(int [][8]);

int main() {

	const int size_row = 8, size_column = 8;
	int board[size_row][size_column] = { 0 },
		hor[8] = { 2,1,-1,-2,-2,-1,1,2 },
		ver[8] = { -1,-2,-2,-1,1,2,2,1 },
		number[65];

	int cur_row = 0, cur_col = 0, d, total = 0,end,k=0;

	srand(time(NULL));
	
	
	do {
		null(board);
		k++;
		cur_row = 0;
		cur_col = 0;
		board[cur_row][cur_col] = 100;

		for (int i = 1; i < 64; i++) {
			end = kon_hod(board, hor, ver, cur_row, cur_col, i);
			if (end == 1) {
				cout << "END na hode: " << i - 1 << endl;
				break;
			}
		}
		d=board_done(board);
		//print_board(board);
	} while (d != 1);

	print_board(board);
	cout << "Done on: " << k << endl;
	
	return 0;
}



void print_board(int f[][8]) {
	int i=0, j=0;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << setw(3) << f[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int kon_hod(int b[][8], int h[],int v[], int &row, int &col,int numb) {
	
	int rand_cell[2][9] = {0}; // cell[0] - row, 1 - column 
	int rand_move = 0, r_num, end=0;
	
	for (int k = 0; k < 8; k++) {
		row += v[k];
		col += h[k];
		if (row >= 0 && row < 8 && col >= 0 && col < 8
			&&!(b[row][col]>=1 && b[row][col]<=100)) {
			rand_move++;
			rand_cell[0][rand_move] = row;
			rand_cell[1][rand_move] = col;
		}
		row -= v[k];
		col -= h[k];
	}
	if (rand_move == 0) {
		end = 1;
	}
	else {
		r_num = 1 + rand() % rand_move;
		b[rand_cell[0][r_num]][rand_cell[1][r_num]] = numb;
		row = rand_cell[0][r_num];
		col = rand_cell[1][r_num];
	}
	return end;
}

void null(int b[][8]) {

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			b[i][j] = 0;
		}
}

int board_done(int b[][8]) {
	int i = 0, j = 0, done=1;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			if (b[i][j] == 0) {
				break;
			}
		if (b[i][j] == 0) {
			done = 0;
			break;
		}
	}

	return done;
}
