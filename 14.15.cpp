#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct clientData {
	int accNum;
	char lastNmae[15];
	char firstName[10];
	float balance;
};

int enterChoice(void);
void printOnScreen(fstream&);
void textFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, clientData);


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	fstream inOutFile("credit.dat", ios::in | ios::out);

	if (!inOutFile) {
		cerr << "File can't be open!" << endl;
		exit(1);
	}
	
	int choise;
	while ((choise = enterChoice()) != 5) {
		switch (choise) {
		case 0:
			printOnScreen(inOutFile);
			break;
		case 1:
			textFile(inOutFile);
			break;
		case 2:
			updateRecord(inOutFile);
			break;
		case 3:
			newRecord(inOutFile);
			break;
		case 4:
			deleteRecord(inOutFile);
			break;
		deafault:
			cerr << "Incorrect choise" << endl;
			break;
		}
		inOutFile.clear();
	}

	return 0;
}

int enterChoice(void)
{
	cout << endl << "Choose:" << endl
		<< "0 - show existed accounts on the screen" << endl
		<< "1 - create a new text formatted file \"print.txt\" for printing" << endl
		<< "2 - edit account" << endl
		<< "3 - add account" << endl
		<< "4 - delete account" << endl
		<< "5 - end of work" << endl;
	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void printOnScreen(fstream& printOriginalFile)
{
	cout << setiosflags(ios::left) << setw(10) << "Account"
		<< setw(16) << "Lastname" << setw(11) << "Firstname"
		<< setiosflags(ios::right) << setw(10) << "Balance"
		<< resetiosflags(ios::right) << endl;
	clientData client;
	printOriginalFile.seekg(0);
	printOriginalFile.read((char*)&client, sizeof(client));

	while (!printOriginalFile.eof()) {
		if (client.accNum != 0)
			outputLine(cout, client);
		printOriginalFile.read((char*)&client, sizeof(client));
	}
}

void textFile(fstream& readFromFile)
{
	ofstream outPrintFile("print.txt", ios::out);

	if (!outPrintFile) {
		cerr << "File can't be open!" << endl;
		exit(1);
	}
	outPrintFile << setiosflags(ios::left) << setw(10) << "Account"
		<< setw(16) << "Lastname" << setw(11) << "Firstname"
		<< setiosflags(ios::right) << setw(10) << "Balance" 
		<<resetiosflags(ios::right)<< endl;
	
	readFromFile.seekg(0);

	clientData client;
	readFromFile.read((char*)&client, sizeof(clientData));

	while (!readFromFile.eof()) {
		if (client.accNum != 0)
			outputLine(outPrintFile, client);
		readFromFile.read((char*)&client, sizeof(clientData));
	}
}

void updateRecord(fstream& updateFile)
{
	int account;

	do {
		cout<<"Enter account number to edit (1-100): ";
		cin >> account;
	} while (account < 1 || account>100);

	updateFile.seekg((account - 1) * sizeof(clientData));

	clientData client;
	updateFile.read((char*)&client, sizeof(client));

	if (client.accNum != 0) {
		outputLine(cout, client);
		cout << endl << "Enter expense(-) or income(+): ";

		float transaction;
		cin >> transaction;
		client.balance += transaction;
		outputLine(cout, client);
		updateFile.seekp((account - 1) * sizeof(client));
		updateFile.write((char*)&client, sizeof(client));
	}
	else
		cerr << "Account # " << account << " doesn't exist yet" << endl;
}

void newRecord(fstream& insertInFile)
{
	cout<<"Enter account number to create it (1-100): ";

	int account;
	cin >> account;
	insertInFile.seekg((account - 1) * sizeof(clientData));

	clientData client;
	insertInFile.read((char*)&client, sizeof(client));

	if (client.accNum == 0) {
		cout << "Enter lastname, firstname, balance" << endl << "? ";
		cin >> client.lastNmae >> client.firstName >> client.balance;
		client.accNum = account;
		insertInFile.seekp((account - 1) * sizeof(clientData));
		insertInFile.write((char*)&client, sizeof(client));
	}
	else
		cerr << "Account # " << account << " already exist." << endl;
}

void deleteRecord(fstream& deleteFromFile)
{
	cout << "Enter account number to delete it (1-100): ";

	int account;
	cin >> account;

	deleteFromFile.seekg((account - 1) * sizeof(clientData));

	clientData client;
	deleteFromFile.read((char*)&client, sizeof(client));

	if (client.accNum != 0) {
		clientData blankClient = { 0,"","",0.0 };

		deleteFromFile.seekp((account - 1) * sizeof(clientData));
		deleteFromFile.write((char*)&blankClient, sizeof(client));
		cout << "Account # " << account << " deleted" << endl;
	}
	else
		cerr << "Account #" << account << " is empty" << endl;

}

void outputLine(ostream& output, clientData c) {
	output << setiosflags(ios::left)<<setw(10) << c.accNum 
		<< setw(16) << c.lastNmae
		<< setw(11) << c.firstName
		<< setw(10) <<setiosflags(ios::fixed | ios::right)
		<< setprecision(2) << c.balance 
		<<resetiosflags(ios::right)<< endl;
}