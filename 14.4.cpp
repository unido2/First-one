#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	ofstream outClientfile("clients.dat", ios::app);

	if (!outClientfile) {
		cerr << "File can't be open" << endl;
		exit(1);
	}

	int account;
	char name[10];
	float balance;

	while (cin >> account >> name >> balance) {
		outClientfile << account << ' ' << name 
			<< ' ' << balance << endl;
		cout << "? ";
	}
	outClientfile.close();

	return 0;
}
