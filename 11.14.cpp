#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;

class PhoneNumber {
	friend ostream& operator<<(ostream&, PhoneNumber&);
	friend istream& operator>>(istream&, PhoneNumber&);
private:
	char areaCode[4];
	char exchange[4];
	char ilne[5];
};

ostream& operator<<(ostream& out, PhoneNumber& num) {
	out << "(" << num.areaCode << ") "
		<< num.exchange << "-" << num.ilne;
	if (cin.fail())
		out << "FAIL";
	return out;
}
istream& operator>>(istream& in, PhoneNumber& num) {
	char* tmp_num = new char[15];

	in.getline(tmp_num, 15);
	
	if (in.gcount() != 15)
		cin.clear(2);

	if (tmp_num[0] != '(' || tmp_num[4] != ')'
		|| tmp_num[5] != ' ' || tmp_num[9] != '-') {
		cin.clear(2);
	}

	if ((tmp_num[1] == '1' || tmp_num[1] == '0') ||
		(tmp_num[6] == '1' || tmp_num[6] == '0') ||
		(tmp_num[2] != '1' && tmp_num[2] != '0')) {
		cin.clear(2);
	}


	if (!cin.fail()) {
		strncpy(num.areaCode, &tmp_num[1], 3);
		strncpy(num.exchange, &tmp_num[6], 3);
		strncpy(num.ilne, &tmp_num[10], 4);
		num.areaCode[3] = '\0';
		num.exchange[3] = '\0';
		num.ilne[4] = '\0';
	}
	else
		cout << "FAIL" << endl;
	
	delete[] tmp_num;
	return in;
}

//(800) 555-1234

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PhoneNumber* p = new PhoneNumber[5];
	int i = 0;
	while (cin >> *p) {
	
		cout <<"phone: "<< *p << endl;
		cout << p << endl;
		//p++;
	}
	delete[] p;

	return 0;
}