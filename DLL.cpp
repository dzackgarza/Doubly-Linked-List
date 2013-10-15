/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 3 - Doubly Linked Lists
    October 10, 2013

*****************************************************/
#include <string>
#include <iostream>
#include "DLL.h"

using namespace std;
// Main Functions//

// Post: an empty DLList is created
DLList::DLList ( void ) : head(NULL), cursor(NULL) {}

// Post: A DLList is destroyed.
DLList::~DLList ( void )
{
    Reset();
    while(cursor != NULL) Delete();
}

// Post: RETVAL1 == The list is empty
bool DLList::IsEmpty ( void ) const { return (!head && !cursor ); }

// Post: RETVAL == Current is after last item in the list or
//      before the first item in the list
bool DLList::EndOfList ( void ) const
{
    return (cursor == NULL);
}

// Pre: !IsEmpty()
// Post: The cursor is moved to the first item in the list
void DLList::Reset ( void )
{
    cursor = head;
}

// Pre: !IsEmpty() && !EndOfList()
// Post: the cursor is moved to the next item in the list
void DLList::Advance ( void )
{
    if (!IsEmpty() && !EndOfList()) cursor = cursor->next;
}

// Pre: !IsEmpty() && !EndOfList()
// Post: the cursor is moved to the previous item
void DLList::Retreat ( void )
{
    if (!IsEmpty() && !EndOfList()) cursor = cursor->previous;
}

// Pre: !IsEmpty() && !EndOfList()
// Post: RETVAL == Item at the cursor
ItemType DLList::CurrentItem( void )
{
    if (!IsEmpty() && !EndOfList()) return cursor->data;
}

// Pre: !IsEmpty()&& !EndOfList()
// Post: Item at the cursor is deleted && the cursor points to the
//      successor of deleted item or IsEmpty() is true if the item
//      deleted was the last item in the list
void DLList::Delete( void )
{
    if (IsEmpty() || EndOfList()) return;

    node* temp = cursor->next;
    if (cursor == head)
        head = cursor->next;
    if (cursor->next != NULL)
        cursor->next->previous = cursor->previous;
    if (cursor->previous != NULL)
        cursor->previous->next = cursor->next;
    delete cursor;
    cursor = temp;
}

// Pre: None
// Post: If the list was empty then Inserted is the only item in
//      the list. If EndOfList was true then Inserted is the new first
//      item in the list. Otherwise, Inserted is the predecessor of
//      the item that was current when the function was called.
//      Inserted is the new current item.
void DLList::InsertBefore ( /*in*/ const ItemType& Inserted)
{
    node* n = new node(Inserted);

    if (IsEmpty()) head = n;
    else if (EndOfList())
    {
        n->next = head;
        head->previous = n;
        head = n;
    }
    else
    {
        n->previous = cursor->previous;
        n->next = cursor;
        if (cursor->previous != NULL) cursor->previous->next = n;
        cursor->previous = n;
        if (cursor == head) head = n;
    }
    cursor = n;
}

// Pre: None
// Post: If the list was empty then Inserted is the only item in
//      the list. If EndOfList was true then Inserted is the new last
//      item in the list. Otherwise, Inserted is the successor of the
//      item that was current when the function was called. Inserted
//      is the new current item.
void DLList::InsertAfter ( /*in*/ const ItemType& Inserted )
{
    node* n = new node(Inserted);

    if (IsEmpty()) head = n;
    else if (EndOfList())
    {
        Reset();
        while (cursor->next != NULL) Advance();
        n->previous = cursor;
        cursor->next = n;
    }
    else
    {
        n->previous = cursor;
        n->next = cursor->next;
        if (cursor->next != NULL) cursor->next->previous = n;
        cursor->next = n;
    }
    cursor = n;
}

// Post: List is displayed to standard out. This is used for
//      debugging only.
void DLList::Display ( void )
{
    node* temp_cursor = cursor;
    Reset();
    while(cursor != NULL)
    {
        cout << "Data: '" << CurrentItem() << "'.\n";
        Advance();
    }
    cursor = temp_cursor;
}
