#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {

	float dX[4] = { 3,3,6,6 }, dY[4] = { 3,10,10,3 };
	Rectangle* rec1 = new Rectangle(dX, dY);

	rec1->printCoor();
	rec1->draw('+','$','z');
	cout << "H= " << rec1->recHeight() << " W= " << rec1->recWidth() <<
		" Area=" << rec1->recArea() << " Perim= " << rec1->recPerimeter() << endl;
	delete rec1;


	return 0;
}