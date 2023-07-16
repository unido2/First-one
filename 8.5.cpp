#include<iostream>
#include "String.h"

int main() {
	using namespace std;

	String s1("giperboll "),s2("LOL"), s3(s1);

	//cin >> s3;
	s1 += s2 += " bams";
	cout << "s1: " << s1 << endl;
	cout << s2(0,1) << endl;;

	String* s4 = new String("YA destructor s4");

	cout << "s4: " << *s4 << endl;

	s1[0] = 'U';
	(*s4)[1] = 'O';
	delete s4;

	return 0;
}