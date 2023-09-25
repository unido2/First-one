#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define PRINT(str) cout<<(str)<<endl
#include<iostream>
#include<iomanip>
#include <assert.h>

using namespace std;

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	char str[] = "HEy, how pow";

	PRINT(str);

	return 0;
}
