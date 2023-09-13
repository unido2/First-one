#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"List.h"
using namespace std;


void concat(List<char>&, List<char>&);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<char> a,b;

	for (int i = 0; i < 10; i++) {
		a.insertAtBack((char)(i+65));
		b.insertAtBack((char)(i+97));
	}
	
	concat(a,b);
	return 0;
}

void concat(List<char>& a, List< char>& b)
{
	char a_val;

	while (!b.isEmpty()) {
		b.removeFromFront(a_val);
		a.insertAtBack(a_val);
	}
	
	a.print();
}
