/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 3 - Doubly Linked Lists
    October 10, 2013

*****************************************************/
#include <iostream>
#include "DLL.h"
using namespace std;

void runtests();
void test1();
void test2();

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
    //test1();
    test2();
}
void test2()
{
    DLList d;
    d.InsertAfter(1);
    d.InsertAfter(2);
    d.InsertAfter(3);
    d.Retreat();
    d.Retreat();
    d.Delete();
    d.Display();
    cout<<d.EndOfList();
    cout << "\nTest Completed." << endl;
}
void test1()
{
    DLList d;
    //d.InsertAfter(1);
    d.InsertAfter(2);
    //d.InsertAfter(3);
    d.InsertAfter(4);
    d.InsertAfter(5);
    d.InsertAfter(6);
    d.InsertAfter(7);
    d.Reset();
    d.InsertBefore(1);
    d.Advance();
    d.InsertAfter(3);
    d.Reset();
    while (!d.EndOfList())
    {
        cout << "Cursor at: " << d.CurrentItem() <<".\n";
        d.Advance();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~\n";
    d.InsertAfter(8);
    for (unsigned i = 8; i > 0; i--)
    {
        cout << "Cursor at: " << d.CurrentItem() <<".\n";
        d.Retreat();
    }
    // d.Display();
}
