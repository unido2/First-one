#define _CRT_MAP_ALLOC
#include "HugeInt.h"

int main() {
	using namespace std;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HugeInt n1(1925), n2(6778), n3;
	cout << n1 <<" "<<n2 << endl;
	n3 = n2 + n1;
	cout << " " << endl << endl;
	n3 = n2 + n1;
	cout << "n3= " << n3 << endl;
	
	return 0;
}