#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

using namespace std;

template<class T> void bubbleSort(T*, const int N );

int main() {

	int a[] = { 10,5,1,9,4 };
	float b[] = { 5.12,5.15,1.13,1.11,1.01 };

	bubbleSort(a, 5);
	bubbleSort(b, 5);

	for(int i=0;i<5;i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout <<setprecision(3)<< b[i] << " ";
	
	return 0;
}

template<class T>
void bubbleSort(T* a, const int s) {

	for (int pass = 1; pass < s; pass++)
		for (int j = 0; j < s - 1; j++)
			if (a[j] > a[j + 1]) {
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}
