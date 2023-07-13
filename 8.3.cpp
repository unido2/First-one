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

	PhoneNumber** ph = new PhoneNumber*[1000];
	for (int i = 0; i < 1000; i++)
		ph[i] = new PhoneNumber;

	

	cin >> *ph[1];

	cout << "number is: " << *ph[1] << endl;
	cout << ph[1]->areaCode << " " << ph[1]->exchange << " " << ph[1]->line << endl;
	
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