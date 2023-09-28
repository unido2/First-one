#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define PI 3.1415f
#include<iostream>
#include<iomanip>
#include <assert.h>
#include<signal.h>
#include <stdarg.h>

using namespace std;

void product(int, ...);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int a[]{ 5,2,3,4,5 };

	product(4, a[0], a[1],a[2],a[3]);

	return 0;
}

void product(int si, ...)
{
	int product = 1;
	va_list list;

	va_start(list, si);

	for (int j = 1; j <= si; j++) {
		product *= va_arg(list, int);
	}
	va_end(list);

	cout << product << endl;
}
