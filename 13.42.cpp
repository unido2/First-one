#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


using namespace std;

void a() {
	cout << "a" << endl;
	throw 1;
}

void b() {
	cout << "b" << endl;
	try {
		a();
	}
	catch (int a) {
		cout << "catch in b= " << a << endl;
	}
	throw 1.2;
}

void c() {
	cout << "c" << endl;
	try {
		b();
	}
	catch (int a) {
		cout << "catch in c= " << a << endl;
	}
}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	try {
		c();
	}
	catch (double b) {
		cout << "catch in main= " << b << endl;
	}


	return 0;
}
