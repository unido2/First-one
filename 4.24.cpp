
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum Status { USED=-1 };
enum Done { NO, YES };

Status cell;
Done konyk;

void print_board(int[][8]);
void kon_hod(int [][8], int [][8],int [], int [], int &, int &,int,Status);
void cell_acces(int ac1[][8], int h[], int v[], Status cell);
void cell_null(int[][8]);
void null(int[][8],int[][8]);
int board_done(int [][8]);

int main() {

	const int size_row = 8, size_column = 8;
	int board[size_row][size_column] = { 0 },
		hor[8] = { 2,1,-1,-2,-2,-1,1,2 },
		ver[8] = { -1,-2,-2,-1,1,2,2,1 },
		acces[8][8] = { {2,3,4,4,4,4,3,2},
						{3,4,6,6,6,6,4,3},
						{4,6,8,8,8,8,6,4},
						{4,6,8,8,8,8,6,4},
						{4,6,8,8,8,8,6,4},
						{4,6,8,8,8,8,6,4},
						{3,4,6,6,6,6,4,3},
						{2,3,4,4,4,4,3,2} },
		acces1[8][8] = { 0 };

	int cur_row, cur_col,d=1, total=0;
	
	for (int h = 0; h < 8; h++) {
		for (int g = 0; g < 8; g++) {
			cur_row = h;
			cur_col = g;
			board[cur_row][cur_col] = 100;
			acces1[cur_row][cur_col] = USED;

			for (int i = 1; i < 64; i++) {
				cell_acces(acces1, hor, ver, cell);
				kon_hod(board, acces1, hor, ver, cur_row, cur_col, i, cell);
				cell_null(acces1);
			}
			total += board_done(board);
			cout << "Round: " << d << endl;
			print_board(board);
			null(board,acces1);
			d++;
		}
		
	}
	cout << "Done: " << total << endl;
	
	return 0;
}



void print_board(int f[][8]) {
	int i=0, j=0;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << setw(3) << f[i][j] << "  ";
			if (f[i][j] == 0) {
				break;
			}
		}
		if (f[i][j] == 0) {
			cout << endl;
			cout << endl <<setw(25)<< "!!! NO !!!!"<<endl;
			break;
		}
		cout << endl;
	}
	cout << endl;
}

void kon_hod(int b[][8],int ac1[][8], int h[],int v[], int &row, int &col,int numb, Status cell) {
	int min=100;
	int cell_min[2] = { 0,0 }; // cell_min[0] - row, 1 - column 
	
	for (int k = 0; k < 8; k++) {
		row += v[k];
		col += h[k];
		if (row >= 0 && row < 8 && col >= 0 && col < 8
			&& ac1[row][col] != USED 
			&&!(b[row][col]>=1 && b[row][col]<=100)
			&& ac1[row][col] < min) {
			min = ac1[row][col];
			cell_min[0] = row;
			cell_min[1] = col;
		}
		row -= v[k];
		col -= h[k];
	}
	
	b[cell_min[0]][cell_min[1]] = numb;
	ac1[cell_min[0]][cell_min[1]] = USED;
	row = cell_min[0];
	col = cell_min[1];


}

void cell_acces(int ac1[][8], int h[], int v[], Status cell) {

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (ac1[i][j] != USED)
				for (int a = 0; a < 8; a++) {
					i += v[a];
					j += h[a];
					if (i >= 0 && i < 8 && j >= 0 && j < 8 && ac1[i][j] != USED)
						ac1[i - v[a]][j - h[a]]++;
					i -= v[a];
					j -= h[a];	
				}

}

void cell_null(int ac1[][8]) {

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (ac1[i][j] != USED)
				ac1[i][j] = 0;
}

void null(int b[][8],int ac1[][8]) {

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			b[i][j] = 0;
			ac1[i][j] = 0;
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
