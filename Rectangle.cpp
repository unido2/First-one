#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(float* X, float* Y) {

	// pole dlya otrisovki
	field = new int* [25];
	for (int i = 0; i < 25; i++)
		field[i] = new int[25];

	//zanulyaem
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			field[i][j] = 0;

	// coordinaty
	decX = new float[4];
	decY = new float[4];
	for (int i = 0; i < 4; i++) {
		decX[i] = X[i];
		decY[i] = Y[i];
	}

	predNumb();
	if (predRec()) {
		MaxMinSide();
		predSquare();
	}
	else {
		cout << "Figura ne yavlyaetsya pryamougol'nikom" << endl;
	}


}

//proverka na pryamougol'nik
bool Rectangle::predRec() {

	if (decX[0] == decX[1] && decX[2] == decX[3]
		&& decY[1] == decY[2] && decY[0] == decY[3])
		return true;
	else
		return false;
}

//proverka na kvadrat
bool Rectangle::predSquare() {

	if ((decY[1]-decY[0])==(decX[2]-decX[1]))
		return true;
	else
		return false;
}

//proverka coordinat
void Rectangle::predNumb() {
	for (int i = 0; i < 4; i++) {
		if (decX[i] < 0 || decX[i] > 20) {
			decX[i] = 0;
		}
		if (decY[i] < 0 || decY[i] > 20) {
			decY[i] = 0;
		}
	}
}

//destructor
Rectangle::~Rectangle() {
	cout << "destructor work!" << endl;
	delete[] decX;
	delete[] decY;
	for (int i = 0; i < 25; i++)
		delete[] field[i];
	delete[] field;

	
}

//pechat' coordinat
void Rectangle::printCoor() {
	for (int i = 0; i < 4; i++)
		cout << (char)(65+i)<<"(" << decX[i]<<";"<<decY[i]<<")" << " ";
	cout << endl;
}

// shirina
float Rectangle::recWidth() {
	if (predRec()) {
		return width;
	}
	else
		return 0.0f;
}

// vysota
float Rectangle::recHeight() {
	if (predRec()) {
		return height;
	}
	else
		return 0.0f;
}

//ploshchad'
float Rectangle::recArea()
{
	if (predRec()) {
		if (predSquare()) {
			return width * width;
		}
		return width * height;
	}
	else
		return 0.0f;
}

//perimetr
float Rectangle::recPerimeter()
{
	if (predRec()) {
		if (predSquare()) {
			return 4 * width;
		}
		return (width + height)*2;
	}
	else
		return 0.0f;
}

//opredelenie vysoty i shiriny
void Rectangle::MaxMinSide() {
	width = abs(decY[0] - decY[1]);
	height = abs(decX[0] - decX[3]);

	if (height > width) {
		float tmp = height;
		height = width;
		width = tmp;
	}
}

//risuem figuru
void Rectangle::draw(char f, char per, char area) {

	if (predRec()) {

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				field[25 - (int)decY[i]][(int)decX[j] - 1] = -1;//4 coreners
			}


		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {


				if (field[i][j] == -1) {
					j++;
					for (; field[i][j] != -1; j++)
						field[i][j] = -1;	//border

					if (i == (25 - (int)decY[3]) && j == ((int)decX[3] - 1)) {
						i = 25;
						break;
					}
					else {
						i++;
						j = 0;
					}
				}
				else {
					if (i != 0 && field[i - 1][j] == -1) {
						field[i][j] = -1;
						j++;
						for (;; j++) {

							if (j == (int)decX[3] - 1) {
								field[i][j] = -1;
								break;
							}
							else
								field[i][j] = -2;
						}
					}
				}

			}

			//cout << endl;
		}


		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (field[i][j] == -1)
					cout << per << " ";
				else
					if (field[i][j] == -2)
						cout << area << " ";
					else
						cout << f << " ";
			}
			cout << endl;
		}
	}
	else
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				if (field[i][j] == 0)
					cout << f << " ";
			}
			cout << endl;
		}

}

/*
void Rectangle::setWidth(float w) {
	width = (w >= 0.0 && w <= 20.0) ? w : 0;
}

void Rectangle::setHeight(float h) {
	height = (h >= 0.0 && h <= 20.0) ? h : 0;
}

float Rectangle::getWidth() const { return width; }

float Rectangle::getHeight() const { return height; }


void Rectangle::perimeter() {
	cout << fixed << setprecision(2)<< "perimeter= " << (width == height ? (height * 4) : (height + width) * 2) << endl;
}

void Rectangle::area() {
	cout <<fixed<<setprecision(2)<< "area= " << (width == height ? (height * height) : (height * width)) << endl;
}
*/