/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 3 - Double Linked Lists
    October 10, 2013

*****************************************************/
#include <iostream>
#include "DDL.h"
using namespace std;

void runtests();
void test1();

int main()
{
    {
        cout << "Running Tests.\n";
        runtests();
    }
    return 0;
}

void runtests()
{
    test1();
}

void test1()
{
    DLList d;
    //d.InsertAfter(1);
    d.InsertAfter(2);
    d.InsertAfter(3);
    d.InsertAfter(4);
    d.InsertAfter(5);
    d.InsertAfter(6);
    d.InsertAfter(7);
    d.Reset();
    d.InsertBefore(1);
    d.Display();
}
