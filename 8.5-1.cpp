#include<iostream>
#include "String1.h"

int main() {
	using namespace std;

	String s1("giperboll "),s2("UUUuuuuuuuuu"), s3("i"),s4("yyy");
	s1 += s2+=s3+=s4;
	cout << s1[1] << " " << s1[2] << endl;
	cout <<"MAX ili min= "<< s1['n'] << endl;;
	cout << strcmp("a", "b") << endl;
	//cout << "--"<<s2 << endl;
	//cout << s1[1] << endl;

	return 0;
}