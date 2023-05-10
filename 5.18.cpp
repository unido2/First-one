#define _CRT_SECURE_NO_WARNINGS
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBSTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void commandExec(int*,int*,int*,int*);
void PrintMem(const int*);

int main() {
	setlocale(LC_ALL, "");

	int memory[100] = {0};
	int number, instruction, command=0, operand,i=0;

	do {
		
		cin >> number;
		if (number == -99999) {
			cout << "Загрузка программы окончена!!" << endl << endl;
			break;
		}
		if(number<1000 || number>9999)
			do {
				cout << "Vvedite norm comandy ili -99999!" << endl;
				cin >> number;
				if (number == -99999)
					break;
			} while (number < 1000 || number>9999);
			if (number == -99999) {
				cout << "Загрузка программы окончена!!" << endl << endl;
				break;
			}
		memory[i] = number;
		
		i++;
	} while (i < 100);

	for (int cell = 0; command!=HALT; cell++) {
		command = memory[cell] / 100;
		operand = memory[cell] % 100;
		commandExec(&cell, &command, &operand, memory);
		//cout << "cell " << cell << endl;

	}
	cout << "i= "<< i << endl;
	
	return 0;
}

void commandExec(int* cell, int* com, int* oper, int* mem) {

	void print_dump(const int*,const int*,const int*, const int*,const int*);

	int static acum=0;
	int num1, num2, res;

	switch (*com) {
		case READ:
			cout << "? ";
			cin >> mem[*oper];
			break;
		case WRITE:
			cout << mem[*oper] << endl;
			break;
		case LOAD:
			acum = mem[*oper];
			break;
		case STORE:
			mem[*oper] = acum;
			break;
		case ADD:
			acum +=mem[*oper];
			break;
		case SUBSTRACT:
			acum -= mem[*oper];
			break;
		case DIVIDE:
			acum = mem[*oper] / acum;
			break;
		case MULTIPLY:
			acum *= mem[*oper];
			break; 
		case BRANCHNEG:
			if (acum < 0)
				*cell=*oper-1;
			break;
		case BRANCH:
				*cell = *oper-1;
			break;
		case BRANCHZERO:
			if(acum==0)
				*cell = *oper - 1;
			break;
		case HALT:
			cout << "SimpleTron stop working" << endl;
			break;
	}
	print_dump(cell, com, oper, &acum, mem);
	//cout << "acum " << acum << endl;
}

void print_dump(const int* cell, const int* com,
	const int* oper, const int* acum, const int* mem) {
	char str[2];

	cout << "REGISTERS" << endl
		<< setw(22) << "accumulator  " << *acum << endl
		<< setw(22) << "instruction Counter  " << *cell << endl
		<< setw(22) << "instruction Register  " << mem[*cell] << endl
		<< setw(22)<<"Operation Code  "<<*com<<endl
		<< setw(22)<<"operand  "<<*oper<<endl;

	cout << "MEMORY" << endl;
	cout << "    ";
	for (int j = 0; j < 10; j++)
		cout << setw(4) << j << "  ";
	cout << endl;

	for (int col = 0; col < 10; col++) {
		cout << setw(2)<<col * 10<<"  ";

		for (int i = col * 10; i < 10 + col * 10; i++)
			cout  <<setw(4)<< mem[i] << "  ";
		cout << endl;
	}
	cin.getline(str,2);
}
