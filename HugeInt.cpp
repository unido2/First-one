#include<string.h>
#include "HugeInt.h"



HugeInt::HugeInt(long long val):count(0)
{
    long long temp_val = val;
    if (val == 0)
        count = 1;
    else
        while (temp_val != 0) {
            temp_val /= 10;
            count++;
        }
   // std::cout << count << '\n';

    begin_p = new Node;
    Node* ptr = begin_p;
    ptr->prev = nullptr;

    for (int i= 1; i <= count; i++) {
        Node* temp_p = ptr;
        ptr->number = val / pow(10, (count - i));
        val %= (int)pow(10, (count - i));
        if (i != count) {
            ptr->next = new Node;
            ptr = ptr->next;
            ptr->prev = temp_p;
        }
        else {
            ptr->next = nullptr;
        }

    }
    end_p = ptr;

   // std::cout << end_p->number << " " << end_p->next << " ";
}


HugeInt::HugeInt(const char* string)
{
    char* a = new char[strlen(string)+1];


    count = std::strlen(string);
    begin_p = new Node;
    Node *ptr = begin_p;

    for (int j = 0; j < count; j++) {
        ptr->number = string[j] - '0';
        ptr->next = new Node;
        ptr = ptr->next;
    }
    ptr->number = NULL;
    ptr->next = nullptr;


}

HugeInt::~HugeInt()
{
    /*
    std::cout << "Des work" << std::endl;
  
    Node* p = begin_p;
    Node* temp;
  
    while (p!= nullptr) {
        temp = p;
        p = p->next;
        delete temp;
    }
   */
}

HugeInt& HugeInt::operator+(HugeInt& op2)
{
  
    HugeInt tempI;
    short carry = 0, num = 0;;

    
    Node* p = tempI.end_p, * p1 = end_p, * p2 = op2.end_p;
    p->prev = p;

    for (; p->prev!= nullptr; p1 = p1->prev, p2 = p2->prev) {
        
        Node* temp = p;
        p->number = p1->number + p2->number + carry;
        if (p->number > 9) {
            p->number %= 10;
            carry = 1;
        }
        else
            carry = 0;

       // std::cout << p->number << " " << '\n';

        if (p1->prev != nullptr) {
            p->prev = new Node;
            p = p->prev;
            p->next = temp;
        }
        else {
            p->prev = nullptr;
        }

    }
    tempI.begin_p = p;

    return tempI;
    
}


std::ostream& operator<<(std::ostream& output, HugeInt& num)
{
    
    Node* ptr = num.end_p;
    /*
    for (; ptr!=nullptr; ptr = ptr->prev) {
        output << ptr->number << " ";  
    }
    */
   // std::cout << '\t';
    
    ptr= num.begin_p;
    for (; ptr != nullptr; ptr = ptr->next) {
        output << ptr->number<<" ";
    }
    
    
    
    return output;
}