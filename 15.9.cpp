#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"List.h"
using namespace std;


void reverse(List<char>&, List<char>&);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<char> a,b;

	for (int i = 0; i < 10; i++) {
		a.insertAtBack((char)(i + 'q'));
	}

	reverse(a, b);

	b.print();

	return 0;
}

void reverse(List<char>& a, List<char>& b)
{
	char val;
	while (!a.isEmpty()) {
		a.removeFromBack(val);
		b.insertAtBack(val);
	}
}

