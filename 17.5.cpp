#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define SUM(x,y) std::cout<<"sum of "<<x\
<<" and "<<y<<" is "<<(x)+(y)<<std::endl 
//#define NDEBUG

#include<iostream>
#include<iomanip>
#include <assert.h>


//using namespace std;


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	SUM(3, 10);

	return 0;
}
