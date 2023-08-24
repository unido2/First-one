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

template<class T> int print(T* ar, const int count, int Low, int High) {
	if (High < count && Low >= 0 && Low<High) {
		for (int i = Low; i <= High; i++)
			cout << ar[i] << " ";
		cout << endl;
		return High-Low+1;
	}
	else
		return 0;
}

int main() {

	int a[] = { 10,5,1,9,4 };
	float b[] = { 5.12,5.15,1.13,1.11,1.01 };
	char c[] = { "Haidy" };

	cout << "number of print el-s: "<<print(a, 5, 0, 4) << endl;
	print(b, 5);
	print(c, 6,2,5);
	
	return 0;
}
