#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159
#define SPHERE_VOL(r) ((double)4/3)*PI*(r)*(r)*(r) 
#define NDEBUG

#include<iostream>
#include<iomanip>
#include <assert.h>

//#define DEBUG

using namespace std;


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << setiosflags(ios::left) << setw(strlen("radius")+4)
		<< "Radius" <<  "Sphere volume"
		<< resetiosflags(ios::left) << endl;

	for (int i = 1; i <= 10; i++) {
		cout << setw(strlen("Radius")) << i
			<< setw(10 - strlen("radius") + strlen("Sphere volume")) << setiosflags(ios::right)
			<< SPHERE_VOL(i) << endl;
	}

	return 0;
}
