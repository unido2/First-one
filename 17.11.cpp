#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include <assert.h>

using namespace std;

inline double sphereVol(int r) { return ((double)4 / 3) * 3.14159 * (r) * (r) * (r); }
void sumArray(int*, int);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int a[5] = { 1,1,2,3,4 };

	sumArray(a, 5);

	cout << setiosflags(ios::left) << setw(strlen("radius") + 4)
		<< "Radius" << "Sphere volume"
		<< resetiosflags(ios::left) << endl;

	for (int i = 1; i <= 10; i++) {
		cout << setw(strlen("Radius")) << i
			<< setw(10 - strlen("radius") + strlen("Sphere volume")) << setiosflags(ios::right)
			<< sphereVol(i) << endl;
	}

	return 0;
}

void sumArray(int* m, int s)
{
	int total = 0; 
	for (int i = 0; i < s; i++)\
		total += m[i]; 
	cout << total << endl;
}
