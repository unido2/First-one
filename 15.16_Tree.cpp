#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"Tree.h"

using namespace std;


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Tree<int> intTree;
	int intVal;
	cout << "enter 10 integers: " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> intVal;
		intTree.insertNode(intVal);
	}
	cout << endl << "Obhod v shirinu" << endl;
	intTree.preOrderTraversal();

	cout << endl << "Posledovatel'niy obhod" << endl;
	intTree.inOrderTraversal();

	cout << endl << "Obratniy obhod" << endl;
	intTree.postOrderTraversal();


	return 0;
}
