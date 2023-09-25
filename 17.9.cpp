#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define PRINTARRAY(m,size) for(int i=0;i<size;i++)\
cout<<m[i]<<' '; cout<<endl
#include<iostream>
#include<iomanip>
#include <assert.h>

using namespace std;

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	char str[] = "HEy, how pow";
	int a[5] = { 0,1,2,3,4 };

	PRINTARRAY(a, 5);

	return 0;
}
