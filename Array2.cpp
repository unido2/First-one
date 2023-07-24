#include "Array2.h"


Array2::Array2(int r, int c)
{
    std::cout << "constructor" << std::endl;
    this->row = r;
    this->col = c;

    this->ptr = new int* [this->row];
    for (int i = 0; i < this->row; i++)
        this->ptr[i] = new int[this->col];

    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->col; j++)
            this->ptr[i][j] = 0;
}

Array2::~Array2()
{
    std::cout << "destructor work" << std::endl;
    for (int i = 0; i < this->row; i++) {
        delete[] ptr[i];
       // std::cout << "d" << " ";
    }
    delete[] ptr;
     
}

Array2& Array2::operator()(int r, int c)
{
    std::cout << "operator()" << std::endl;
  
    for (int i = 0; i < this->row; i++) {
        delete[] this->ptr[i];
        //std::cout << "i" << " ";
    }
    delete[] this->ptr;
  
    /*
    wow=new Array2(r,c); 
    *this = *wow;
    */

    
    this->row = r;
    this->col = c;

    this->ptr = new int* [this->row];
    for (int i = 0; i < this->row; i++)
        this->ptr[i] = new int[this->col];

    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->col; j++)
            this->ptr[i][j] = 0;
    
   
     return *this;
}



Array2 Array2::operator+(Array2&)
{
    return Array2();
}


std::ostream& operator<<(std::ostream& out, Array2& a)
{
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++)
            out << a.ptr[i][j] << " ";
        out << std::endl;
    }

    return out;
}
