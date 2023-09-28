#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define PI 3.1415f
#include<iostream>
#include<iomanip>
#include <assert.h>
#include<signal.h>
#include <stdarg.h>
#include<cstring>

using namespace std;

void sort(int, int*,int(*)(int,int));
void print(int*,int);
void fillAr(int*,int);
int ascending(const int, const int);
int descending(const int, const int);


int main(int argc, char* argv[]) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int a[6]{0};

	if (!strcmp(argv[1], "-a")) {
		cout << "array is sorted in ascending order" << endl;
		sort(6, a, ascending);
	}
	else {
		if (!strcmp(argv[1], "-d")) {
			cout << "array is sorted in descending order" << endl;
			sort(6, a, descending);
		}
		else
		{
			cout << "array is not sorted" << endl;
			fillAr(a, 6);
			print(a, 6);
		}
	}
	return 0;
}

void sort(int size, int* a, int(*compare)(int,int))
{
	void swap(int*, int*);

	fillAr(a, size);
	//print(a,size);

	for (int pass = 1; pass < size; pass++)
		for (int count = 0; count < size - 1; count++)
			if ((*compare)(a[count], a[count + 1]))
				swap(&a[count], &a[count + 1]);
	print(a, size);
}
void swap(int* el1, int* el2) {
	int temp;
	temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}


void print(int *a,int size)
{
	for (int i = 0; i < size; i++) {
		cout << a[i]<<' ';
	}
	cout << endl;
}

void fillAr(int* a,int size)
{
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
}

int ascending(const int a, const int b)
{
	return a>b;
}

int descending(const int a, const int b)
{
	return a<b;
}
