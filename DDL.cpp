/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 3 - Double Linked Lists
    October 10, 2013

*****************************************************/
#include <iostream>
#include "DDL.h"

using namespace std;
// Main Functions//

// Post: an empty DLList is created

DLList::DLList ( void )
{
    this->head = NULL;
    this->cursor = NULL;
}

// Post: A DLList is destroyed.
DLList::~DLList ( void )
{
}

// Post: RETVAL1 == The list is empty
bool DLList::IsEmpty ( void ) const
{
    return (this->cursor == NULL);
}

// Post: RETVAL == Current is after last item in the list or
//      before the first item in the list
bool DLList::EndOfList ( void ) const
{
    return (this->cursor->next == NULL);
}

// Pre: !IsEmpty()
// Post: The cursor is moved to the first item in the list
void DLList::Reset ( void )
{
    this->cursor = this->head;
}

// Pre: !IsEmpty() && !EndOfList()
// Post: the cursor is moved to the next item in the list
void DLList::Advance ( void )
{

}

// Pre: !IsEmpty() && !EndOfList()
// Post: the cursor is moved to the previous item
void DLList::Retreat ( void )
{

}

// Pre: !IsEmpty() && !EndOfList()
// Post: RETVAL == Item at the cursor
int DLList::CurrentItem( void )
{
    if (!IsEmpty() && !EndOfList()) return this->cursor->data;
    else throw -1;
}

// Pre: !IsEmpty()&& !EndOfList()
// Post: Item at the cursor is deleted && the cursor points to the
//      successor of deleted item or IsEmpty() is true if the item
//      deleted was the last item in the list
void DLList::Delete( void )
{

}

// Pre: None
// Post: If the list was empty then Inserted is the only item in
//      the list. If EndOfList was true then Inserted is the new first
//      item in the list. Otherwise, Inserted is the predecessor of
//      the item that was current when the function was called.
//      Inserted is the new current item.
void DLList::InsertBefore ( /*in*/ const int& Inserted )
{
    node* n = new node;
    n->data = Inserted;

    if ( IsEmpty() )
    {
        n->previous = NULL;
        n->next = NULL;
        this->head = n;
    }
    else if ( EndOfList() )
    {
        n->previous = this->cursor->previous;
        n->next = this->cursor;
        this->cursor->previous = n;
        this->head = n;
    }
    else
    {
        n->previous = this->cursor->previous;
        n->next = this->cursor;
        this->cursor->previous = n;
        if (cursor == head) this->head = n;
    }
    this->cursor = n;
}

// Pre: None
// Post: If the list was empty then Inserted is the only item in
//      the list. If EndOfList was true then Inserted is the new last
//      item in the list. Otherwise, Inserted is the successor of the
//      item that was current when the function was called. Inserted
//      is the new current item.
void DLList::InsertAfter ( /*in*/ const int& Inserted )
{
    node* n = new node;
    n->data = Inserted;

    if ( IsEmpty() )
    {
        n->previous = NULL;
        n->next = NULL;
        this->head = n;
    }
    else if ( EndOfList() )
    {
        n->previous = this->cursor;
        n->next = NULL;
        this->cursor->next = n;
    }
    else
    {
        n->previous = this->cursor;
        n->next = this->cursor->next;
        this->cursor->next = n;
    }
    this->cursor = n;
}

// Post: List is displayed to standard out. This is used for
//      debugging only.
void DLList::Display ( void ) const
{
    node* temp_cursor = this->head;
    while(temp_cursor != NULL)
    {
        cout << "Data: '" << temp_cursor->data << "'.\n";
        temp_cursor = temp_cursor->next;
    }
}
