#include"Array.h"

int main() {
	using namespace std;

	Array a1(10), a2(10);
	for (int i = 0; i < a1.getSize(); i++) {
		a1[i] = 10 - i;
		a2[i] = 1;
	}
	Array a3(a2);
	
	a3 + a1;
	cout << a1 << endl;
	a1 = a2;
	a2[0] = 10;
	cout << a2<< endl;
	//a1 = a2;
	//cout << a1 << a2;

	return 0;
}