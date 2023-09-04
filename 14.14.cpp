#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string>


using namespace std;


template<class T>
void printType(ofstream&,T,const char*);

int main() {
	ofstream file("data-size.dat", ios::out);

	int a=0;
	file << setiosflags(ios::left)<<setw(20) << "Type of data" << setiosflags(ios::right)
		<< setw(10) << "Size" << resetiosflags(ios::right) << endl;

	printType(file,(char)a,"char");
	printType(file, (unsigned char)a, "unsigned char");
	printType(file, (short int)a, "short int");
	printType(file, (unsigned short int)a, "unsigned short int");
	printType(file, (int)a, "int");
	printType(file, (unsigned int)a, "unsigned int");
	printType(file, (long int)a, "long int");
	printType(file, (unsigned long int)a, "unsigned long int");
	printType(file, (float)a, "float");
	printType(file, (double)a, "double");
	printType(file, (long double)a, "long double");

	return 0;
}

template<class T>
void printType(ofstream& f, T size, const char* c)
{
	f << setiosflags(ios::left) << setw(20) << c << setiosflags(ios::right)
		<< setw(10) << sizeof(size) << resetiosflags(ios::right) << endl;
}
