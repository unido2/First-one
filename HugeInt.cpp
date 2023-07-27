#include<string.h>
#include "HugeInt.h"


HugeInt::HugeInt(long val)
{
    for (int i = 0; i < 30; i++)
        integer[i] = 0;
    for (int i = 29; val != 0 && i >= 0; i--) {
        integer[i] = val % 10;
        val /= 10;
    }

}

HugeInt::HugeInt(const char* string)
{
    int i, j;

    for (int i = 0; i < 30; i++)
        integer[i] = 0;
    for (i = 30 - std::strlen(string), j = 0; i <= 29; i++, j++)
        integer[i] = string[j] - '0';
}

HugeInt HugeInt::operator+(HugeInt& op2)
{
    HugeInt temp;
    int carry = 0;

    for (int i = 29; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;

        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
            carry = 0;
    }
    return temp;
}


std::ostream& operator<<(std::ostream& output, HugeInt& num)
{
    int i;
    for (i = 0; (num.integer[i] == 0) && (i <= 29); i++)
        ;
    if (i == 30)
        output << 0;
    else
        for (; i <= 29; i++)
            output << num.integer[i];
    return output;
}