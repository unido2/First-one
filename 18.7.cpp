#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<assert.h>
#include<cstring>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	
	ifstream in(argv[1], ios::in);

	if (!in) {
		cerr<<"ERROR" << endl;
		exit(1);
	}

	in.seekg(0, ios::end);
	int count = in.tellg();

	in.seekg(0);

	char* ptr = new char[count];
	in >> ptr;

	ofstream out(argv[2], ios::out);
	if (!out) {
		cerr << "ERROR" << endl;
		exit(1);
	}

	for (int i = count-1; i >= 0; i--) {
		out << ptr[i];
	}

	delete[]ptr;
	
	return 0;
}

