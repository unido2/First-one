#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"List.h"

using namespace std;



int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<float> a;
	List<int> b;
	float aver;
	int value,sum=0,count=0;
	
	srand(time(NULL));

	for (int i = 0; i < 25; i++) {
		value = 1 + rand() % 100;
		b.insertAtBack(value);
		sum += value;
		count++;
	}
	aver = (float)sum / (count);
	b.print();

	cout << "sum= " << sum << 
		endl <<setiosflags(ios::fixed | ios::showpoint)<<
		setprecision(2)<<"aver= " << aver << endl;


	return 0;
}


