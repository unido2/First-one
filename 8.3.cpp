#include <windows.h>
#include<iostream>
#include <debugapi.h>
#include<crtdbg.h>

using namespace std;

class PhoneNumber {
public:
	friend ostream& operator<<(ostream&, const PhoneNumber&);
	friend istream& operator>>(istream&, PhoneNumber&);

	char areaCode[4];
	char exchange[4];
	char line[5];
};

ostream& operator<<(ostream& out, const PhoneNumber& number) {

	out << "(" << number.areaCode << ") " << number.exchange <<
		"-" << number.line;
	return out;
}

istream &operator>>(istream& in, PhoneNumber& number) {

	in.ignore().getline(number.areaCode, 4,')').ignore().
		getline(number.exchange, 4,'-').getline(number.line, 5);
	return in;
}


int main() {
	_CrtMemState sOld,sNew,sDiff;
	_CrtMemCheckpoint(&sOld);

	int end;
	PhoneNumber** ph = new PhoneNumber*[1000];
	for (int i = 0; i < 1000; i++)
		ph[i] = new PhoneNumber;

	
	for (int i = 0; i < 5; i++)
		cin >> *ph[i];

	for (int i = 0; i < 5; i++) {
		cout << "number is: " << *ph[i] << endl;
		cout << ph[i]->areaCode << " " << ph[i]->exchange << " " << ph[i]->line << endl;
	}

	for (int i = 0; i < 1000; i++)
		delete ph[i];
	delete[] ph;


	_CrtMemCheckpoint(&sNew);
	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}

	return 0;
}