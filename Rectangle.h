
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
	Rectangle(float *,float *);
	~Rectangle();
	void printCoor();
	void draw(char,char,char);
	float recWidth();
	float recHeight();
	float recArea();
	float recPerimeter();

/*
	void setWidth(float);
	void setHeight(float);

	float getWidth() const;
	float getHeight() const;

	void perimeter();
	void area();
	*/
private:
	float *decX, *decY;
	int** field;
	float width, height;
	//float width, height;
	void setDefault();
	bool predSquare();
	void predNumb();
	bool predRec();
	void MaxMinSide();
};
#endif // !RECTANGLE_H
