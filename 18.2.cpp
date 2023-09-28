#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include <assert.h>
#include <stdarg.h>

using namespace std;

double average(int, ...);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	double a[3] = { 5,6,10 };
	
	cout << setiosflags(ios::fixed) << setprecision(2) <<
		average(2,a[0],a[1],a[2]) << endl;

	return 0;
}

double average(int i, ...)
{
	double total = 0;
	int j;
	va_list ap;

	va_start(ap, i);

	for (j = 1; j <= i; j++)
		total += va_arg(ap, double);

	return total/i;
}
