#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"Stack.h"

using namespace std;

//live on time, emit no evil

int palin(char*, Stack<char>&);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Stack<char> str;
	char st[]="Live On tIme, emit no evil";
	char* pstr=st;

	for (; *pstr != '\0'; pstr++) {
		if (*pstr >= 'A' && *pstr <= 'Z')
			*pstr = (char)(*pstr + 32);
		if (*pstr >= 'a' && *pstr <= 'z')
			str.push(*pstr);
	}
	cout << st << endl << endl;
	if (palin(st, str))
		cout << "^This line is a palindrom^" << endl << endl;
	else
		cout << "^This line is not a palindrom^" << endl << endl;

	return 0;
}

int palin(char* p, Stack<char>& str)
{
	char val;

	for (; *p != '\0'; p++) {
		if (*p >= 'a' && *p <= 'z')
		{
			str.pop(val);
			if (*p != val) {
				return 0;
			}
			//cout << val << ' ' << *p << endl;
		}
	}
	return 1;
}
