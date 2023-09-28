#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<assert.h>
#include<cstring>

using namespace std;

int main(int argc, char* argv[]) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int n;
	cin >> n;

	int *ptr=(int*)calloc(n,sizeof(int));

	if (ptr == NULL) {
		free(ptr);
		exit(1);
	}
	for (int i = 0; i < n; i++)
		cin >> ptr[i];

	for (int i = 0; i < n; i++)
		cout<< ptr[i]<< ' ';
	cout << endl;

	int size = (n - 3) * sizeof(int);
	int* new_ptr = (int*)realloc(&ptr[0], size);

	if (new_ptr == NULL) {
		free(ptr);
		exit(1);
	}
	for (int i = 0; i < n-3; i++)
		cout << new_ptr[i] << ' ';
	cout << endl;

	free(new_ptr);


	return 0;
}

