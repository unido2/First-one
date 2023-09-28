#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define PI 3.1415f
#include<iostream>
#include<iomanip>
#include <assert.h>
#include<signal.h>
//#include <stdarg.h>

using namespace std;

void signal_handler(int);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	signal(SIGINT, signal_handler);
	srand(time(NULL));

	for (int i = 1; i < 101; i++) {
		int x = 1 + rand() % 50;
		if (x == 25)
			raise(SIGINT);

		cout << setw(4) << i;
		if (i % 10 == 0)
			cout << endl;
	}

	return 0;
}

void signal_handler(int signalValue)
{
	cout << endl << "Incoming signal (" << signalValue <<
		")." << endl <<
		"Do you want to continue? (1 - yes, 2 - no)?  ";
	int response;
	cin >> response;

	while (response != 1 && response != 2) {
		cout<<"(1 - yes, 2 - no)?  ";
		cin >> response;
	}
	if (response == 1)
		signal(SIGINT, signal_handler);
	else
		exit(EXIT_SUCCESS);
}
