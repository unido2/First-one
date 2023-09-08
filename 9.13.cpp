#define _CRT_MAP_ALLOC
#include <iostream>
#include "Qudrilateral_base.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int *x=new int [4] { 0,0,7,7 };
	int *y=new int [5] { 0,5,5,0 };

	Qudrilateral q(x, y);

	q.ShapeName();
	q.printShape();
	

	delete[] x;
	delete[] y;
	return 0;
}