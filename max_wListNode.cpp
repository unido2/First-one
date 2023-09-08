#define _CRT_MAP_ALLOC
#include<iostream>


using namespace std;

struct node {
	int data;
	node* next;
};

int max(node*, int, int, int*&);


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int whatMax;
	int tempNum=0;
	int* temp=nullptr;
	int count = 0;


	node* beginP = new node;
	node* cur = beginP;

	while (1) {
		cin >> tempNum;
		cur->data = tempNum;

		if (tempNum != -1) {
			cur->next = new node;
			cur = cur->next;
			count++;
		}
		else {
			cur->next = nullptr;
			break;
		}
	}
	
	/*node* p = beginP;
	for (; p->next != nullptr;) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;*/

	whatMax=max(beginP,count,1,temp);
	cout <<"max= "<< whatMax << endl;
	
	delete temp;
	node* delp = beginP;
	for (; delp != nullptr;) {
		node *temp = delp;
		delp = delp->next;
		delete temp;
	}

	return 0;
}

int max(node* beginp,int size,int whatMax,int* &tempp) {

	int* m = new int[size];
	int k = 0;
	tempp = m;

	node* p = beginp;
	while (k<size) {
		m[k++] = p->data;
		p = p->next;
	}
	
	for (int i = 0; i < size; i++)
		for (int i = 0; i < size-1; i++)
			if (m[i] < m[i + 1]) {
				swap(m[i], m[i + 1]);
			}
	
	for (int i = 0; i < size; i++)
		if (i == whatMax-1)
			return m[i];
		else
			continue;
}