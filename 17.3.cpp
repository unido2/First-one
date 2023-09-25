#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#define YES 1
#define NO 0
#include"common.h"
#line 3000
//#define TRUE
//#undef TRUE
#define TRUE
//#define ACTIVE
#define CUBE_VOLUME(x) (x)*(x)*(x)

#include<iostream>
#include<iomanip>
#include <assert.h>

using namespace std;

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	auto a="uu";
#if defined(TRUE)
#undef TRUE
#define TRUE 1
#endif // defined(TRUE)


#if defined(ACTIVE)
	#define INACTIVE 0
#else
	#define INACTIVE 1
#endif  

	cout << CUBE_VOLUME(3) << endl;
	cout << INACTIVE<<" "<< endl;


	return 0;
}
