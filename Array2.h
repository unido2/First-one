#ifndef Array2
#define ARRAY2_H
#include<iostream>
#include<iomanip>
class Array2 {
	friend std::ostream& operator<<(std::ostream&, Array2&);
public:
	
	Array2(int=5,int=5);
	~Array2();
	Array2& operator()(int,int);
	Array2 operator+(Array2&);
	int& operator=(int);
	int& operator[](int);

private:
	
	Array2* wow;
	int** ptr;
	int row, col;
};
#endif // !Array2
