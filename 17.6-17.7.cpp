#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define MINIMUM2(x,y) (x<y?x:y)
#define MINIMUM3(x,y,z) (MINIMUM2(x,y)<z?MINIMUM2(x,y):z)
#include<iostream>
#include<iomanip>
#include <assert.h>

using namespace std;

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int x, y, z;
	cin >> x >> y>>z;
	cout << MINIMUM3(x, y,z) << endl;

	return 0;
}
