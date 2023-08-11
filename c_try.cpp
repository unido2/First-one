#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"String.h"

using namespace std;

template<class T> int isEqualTo(T*a, T*b) {
	if (*a == *b)
		return 1;
	return 0;
}

int main() {

	String str1("hey"),str2("hoy");
	
	int a[2]={ 2,2 };
	char b[3]={ "bb" };

	cout << isEqualTo(&a[0], &a[1]) << endl;
	cout << isEqualTo(&b[0], &b[1]) << endl;
	cout << isEqualTo(&str1,&str2) << endl;
	
	
	return 0;
}
