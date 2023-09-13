#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"List.h"
using namespace std;


List<char>* merge(List<char>&, List<char>&, List<char>&);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<char> a,b,c,*ptr=nullptr;

	for (int i = 0; i < 10; i++) {
		a.insertAtBack((char)(i+65));
		b.insertAtBack((char)(i+97));
	}
	
	ptr = merge(a, b, c);

	ptr->print();

	return 0;
}

List<char>* merge(List<char>& a, List< char>& b, List<char>& c)
{
	List<char>* p = &c;
	char a_val;

	while (!a.isEmpty()) {
		a.removeFromFront(a_val);
		c.insertAtBack(a_val);
	}
	while (!b.isEmpty()) {
		b.removeFromFront(a_val);
		c.insertAtBack(a_val);
	}
	
	return p;
}
