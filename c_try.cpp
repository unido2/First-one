#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"TArray.h"

using namespace std;




int main() {

	setlocale(LC_ALL, "ru");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Array<const char*, 5> r;
	Array<int**, 2> ptri;
	for(int i=0;i<2;i++)
		ptri[i] = new int*[5];
	for (int i = 0; i < 5; i++)
		ptri[0][i] = new int[4];

	for (int i = 0; i < 4; i++)
		ptri[0][0][i] = i + 2;

	for (int i = 0; i < 4; i++) {
		//cout << ptri[0][i] << " ";
		cout << ptri[0][0][i] << " ";
	}

	
	//cout << t[4] << " " << r[4] << endl;

	return 0;
}
