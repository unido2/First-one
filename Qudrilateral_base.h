#ifndef QUDRILATEREAL_H
#define QUDRILATERAL_H

class Qudrilateral {
public:
	Qudrilateral(int* x, int* y);
	~Qudrilateral();
	virtual void ShapeName();
	virtual void printShape();
protected:
	int getSide(int) const;
private:
	int* x_co, * y_co;
	bool CheckQudri() const;
};

#endif // !QUDRILATEREAL_H
