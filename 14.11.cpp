#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string>


using namespace std;

struct person {
	char lastName[15];
	char firstName[15];
	char age[3];
};

void print(fstream&);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	fstream file("nameage.dat", ios::out| ios::in);

	person blank_person = {"unassigned","","0" };
	person pers;
	
	/*
	for (int i = 1; i <= 100; i++)
		file.write((char*)&blank_person, sizeof(person));
	
	file.seekp(0);
	for (int i = 0; i < 3; i++) {
		cin >> pers.lastName >> pers.firstName >> pers.age;
		file.write((char*)&pers, sizeof(pers));
	}
	*/

	print(file);

	int number=0;
	while (1) {
		cout << "vvedite nomer zapisi(1 - 100) dlya edit: ";
		cin >> number;
		if (number == -1)
			break;
		file.seekg(sizeof(pers) * (number - 1));
		file.read((char*)&pers, sizeof(pers));

		if (strcmp(pers.lastName, "unassigned")) {
			cin >> pers.lastName >> pers.firstName >> pers.age;
			file.seekp(sizeof(pers) * (number - 1));
			file.write((char*)&pers, sizeof(pers));
		}
		else
			cout << "net svedeniy" << endl;
	}
	print(file);
	cout << file.rdstate() << endl;

	while (1) {
		cout << "vvedite nomer zapisi(1 - 100) dlya udaleniya: ";
		cin >> number;
		if (number == -1)
			break;
		file.seekg(sizeof(pers) * (number - 1));
		file.read((char*)&pers, sizeof(pers));
		
		if (strcmp(pers.lastName, "unassigned")!=0) {
			file.seekp(sizeof(pers) * (number - 1));
			file.write((char*)&blank_person, sizeof(pers));
		}
		else
			cout << "net svedeniy" << endl;
	}

	print(file);

	return 0;
}

void print(fstream& f)
{
	f.clear();
	f.seekg(0);
	person p;
	int count = 1;

	f.read((char*)&p, sizeof(p));
	while (!f.eof()) {
		if (strcmp(p.lastName, "unassigned")) {
			cout <<count++<<' '<< p.lastName << ' ' << p.firstName << ' ' << p.age << endl;
		}
		f.read((char*)&p, sizeof(p));
	}
	cout << endl;
	f.clear();
}
