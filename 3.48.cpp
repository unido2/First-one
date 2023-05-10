// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
float rast(float, float, float, float);

 int main()
 {
	 float x1, x2, y1, y2;
	 
	 cout << "vvedite coordinaty tochki A (x1,y1)= " << endl;
	 cin >> x1 >> y1;
	 cout << "vvedite coordinaty tochki B (x2,y2)= " << endl;
	 cin >> x2 >> y2;
	 cout <<setprecision(3)<<rast(x1, y1, x2, y2) << endl;

	 return 0;
}

 float rast(float x1, float y1, float x2, float y2) {
	 return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
 }

 



