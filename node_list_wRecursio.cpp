#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include"List.h"

template<class Nodetype>
struct node {
	Nodetype data;
	node* next;
};


template<class Nodetype>
node<Nodetype>* node_list_fill(node<Nodetype>*, int, int&);

template<class Nodetype>
void list_print(node<Nodetype>*);

template<class Nodetype>
node<Nodetype>* list_print_recur(node<Nodetype>*);

int main() {

	int c = 64;
	node<char>* begin_p = new node<char>;
	node<char>* ptr = begin_p;

	ptr = node_list_fill(ptr, 5, c);
	list_print(begin_p);
	cout << endl;
	list_print_recur(begin_p);
	

	return 0;
}

template<class Nodetype>
node<Nodetype>* node_list_fill(node<Nodetype>* ptr, int n, int& c)
{
	for (int i = 1; i <= n; i++) {
		ptr->data = i + c;

		if (i == n) {
			ptr->next = nullptr;
		}
		else {
			ptr->next = new node<char>;
			ptr = ptr->next;
		}
	}
	c += n;
	return ptr;
}

template<class Nodetype>
void list_print(node<Nodetype>* begin_p)
{
	node<char>* printp = begin_p;
	while (printp != nullptr) {
		cout << printp->data << endl;
		printp = printp->next;
	}
}

template<class Nodetype>
node<Nodetype>* list_print_recur(node<Nodetype>* begin)
{
	node<Nodetype>* p = begin;

	if (p == nullptr) {
		return nullptr;
	}
	else {
		list_print_recur(p->next);
	}
	cout << p->data << endl;

}

