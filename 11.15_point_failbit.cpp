#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

using namespace std;

class Point {
	friend ostream& operator<<(ostream&, Point&);
	friend istream& operator>>(istream&, Point&);
private:
	char xCoordinate[7];
	char yCoordinate[7];
};
ostream& operator<<(ostream& out, Point& num) {

	if (!cin.fail()) {
		out << "Point [" << num.xCoordinate <<
			", " << num.yCoordinate << "]";
	}
	else {
		cin.clear(0);
		out << "Error in creating Point";
	}
	return out;
}

istream& operator>>(istream& in, Point& num) {
	char tX[7]={ 0 }, tY[7]={ 0 };

	cout.put('X').put(':').put(' ');
	in.getline(tX, 7);
	if (in.gcount() != 7 || tX[3] != '.') {
		cin.clear(2);
	}
	if (!cin.fail()) {
		for (int i = 0; i < in.gcount() - 1; i++) {
			if (i != 3 && (tX[i] < '0' || tX[i] > '9')) {
				cin.clear(2);
				break;
			}
		}
	}

	if (!cin.fail()) {
		cout.put('Y').put(':').put(' ');
		in.getline(tY, 7);
		if (in.gcount() != 7 || tY[3] != '.') {
			cin.clear(2);
		}
	}

	if (!cin.fail()) {
		for (int i = 0; i < in.gcount()-1; i++) {
			if (i!=3 && (tY[i] < '0' || tY[i] > '9')) {
				cin.clear(2);
				break;
			}
		}
	}

	if (!cin.fail()) {
		strcpy(num.xCoordinate, tX);
		strcpy(num.yCoordinate, tY);
	}
	
	return in;
}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Point *p=new Point[3];

	for (;;p++) {
		cin >> *p;
		cout << *p << endl;
		cout << p << endl;
	}


	return 0;
}