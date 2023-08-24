#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

using namespace std;

template<class T> void print(T* ar, const int count) {
	for (int i = 0; i < count; i++)
		cout << ar[i] << " ";
	cout << endl;
}

void print(const char **ar, const int s) {
	for (int i = 0; i < s; i++)
		cout <<setw(10) << ar[i] << endl;
	//cout << endl;
}

int main() {

	int a[] = { 10,5,1,9,4 };
	float b[] = { 5.12,5.15,1.13,1.11,1.01 };
	char c[] = { "Haidy" };
	const char* d[3] = { "hey","wow","pow" };

	print(a, 5);
	print(b, 5);
	print(c, 6);
	print(d, 3);
	
	return 0;
}
