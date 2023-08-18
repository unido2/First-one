#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"TArray.h"

using namespace std;


template<class T> int isEqualTo(T*a, T*b) {
	if (*a == *b)
		return 1;
	return 0;
}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Array<float, 20> a1, a2;
	Array<char, 10> c1;

	for (int i = 0; i < a1.getSize(); i++) {
		a1[i] = (float)i + 1;
	}
	

	for (int i = 0; i < c1.getSize(); i++) {
		c1[i] = i + 65;
	}

	cout << a1<<endl<<c1 << endl;

	cout << (a1 != a2) << endl;
	
	return 0;
}
