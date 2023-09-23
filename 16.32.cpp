#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<iomanip>
//#include<ctype.h>
//#include<stdlib.h>

using namespace std;


int isDigit(int);
int isAlpha(int);
int isAlnum(int);
int isXDigit(int);
int isLower(int);
int isUpper(int);
int toLower(int);
int toUpper(int);
int isSpace(int);
int isCntrl(int);
int isPunct(int);
int isPrint(int);
int isGraph(int);


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char f = 127;

	if (isGraph(f))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}

int isDigit(int c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int isAlpha(int c)
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int isAlnum(int c)
{
	if (isAlpha(c) || isDigit(c))
		return 1;
	return 0;
}

int isXDigit(int c)
{
	if (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F' 
		|| isDigit(c))
		return 1;
	return 0;
}

int isLower(int c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

int isUpper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;

}

int toLower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c+('a'-'A');
	return c;
}

int toUpper(int c)
{
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');
	return c;
}

int isSpace(int c)
{
	if (c == '\n' || c == ' ' ||
		c == '\f' || c == '\r' || c == '\t' || c == '\v')
		return 1;
	return 0;
}

int isCntrl(int c)
{
	if (c >= 0 && c <= 32 || c==127)
		return 1;
	return 0;
}

int isPunct(int c)
{
	if (!isAlnum(c) && !isCntrl(c))
		return 1;
	return 0;
}

int isPrint(int c)
{
	if (c >= 32 && c <= 126)
		return 1;
	return 0;
}

int isGraph(int c)
{
	if (c >= 33 && c <= 126)
		return 1;
	return 0;
}
