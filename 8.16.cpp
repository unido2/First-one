#include "HugeInt.h"

int main() {
	using namespace std;

	HugeInt n1(10000000), n2("2001"), n3;

	n3 = n2 + n1;
	cout << "n3= " << n3 << endl;

	return 0;
}