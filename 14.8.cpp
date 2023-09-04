#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>

using namespace std;

void outputLine(int, char*, float);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ifstream inClientFile("clients.dat", ios::in);

	if (!inClientFile) {
		cerr << "File can't be open!" << endl;
		exit(1);
	}
	cout << "1 - bal=0" << endl <<
		"2 - bal<0" << endl <<
		"3 - bal>0" << endl <<
		"4 - end of list" << "? ";
	int request;
	cin >> request;

	while (request != 4) {

		int account;
		char name[10];
		float balance;

		inClientFile >> account >> name >> balance;
		switch (request) {
		case 1:
			cout << "bal=0" << endl;
			while (!inClientFile.eof()) {
				if (balance == 0)
					outputLine(account, name, balance);
				inClientFile >> account >> name >> balance;
			}
			break;
		case 2:
			cout << "bal<0" << endl;
			while (!inClientFile.eof()) {
				if (balance < 0)
					outputLine(account, name, balance);
				inClientFile >> account >> name >> balance;
			}
			break;
		case 3:
			cout << "bal>0" << endl;
			while (!inClientFile.eof()) {
				if (balance > 0)
					outputLine(account, name, balance);
				inClientFile >> account >> name >> balance;
			}
			break;
		}
		inClientFile.clear();
		inClientFile.seekg(0);
		cout << endl << "? ";
		cin >> request;
	}
	cout << "the end of list" << endl;


	return 0;
}

void outputLine(int acc, char* name, float bal) {
	cout << setiosflags(ios::left) << setw(10) << acc <<
		setw(13) << name << setw(7) << setprecision(2) <<
		setiosflags(ios::showpoint | ios::right | ios::fixed) 
		<< bal << resetiosflags(ios::right)<< endl;
}
