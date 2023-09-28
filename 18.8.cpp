#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<assert.h>
#include<cstring>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int count5 = 0, count2 = 0, count3 = 0;
	int count3line = 0;

start_5_dot:
	cout << '*';
	count5++;
	if (count5 != 5)
		goto start_5_dot;
	else {
		count5 = 0;
		cout << endl;
	}
	if (count3line == 2)
		goto end;

start_2_dot:
	
	cout << '*';

start_3_space:
	if (count3 != 3) {
		count3++;
		cout << ' ';
		goto start_3_space;
	}
	if (count2 != 1) {
		count2++;
		goto start_2_dot;
	}
	else {
		if (count3line != 2) {
			count3line++;
			cout << endl;
			count2 = count3 = 0;
			goto start_2_dot;
		}
		else {
			cout << endl;
			goto start_5_dot;
		}
	}
end:


	return 0;
}

