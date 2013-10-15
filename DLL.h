/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 3 - Doubly Linked Lists
    October 10, 2013

*****************************************************/
#ifndef MY_STRING_CLASS_H
#define MY_STRING_CLASS_H

#include <string>
#define ItemType std::string

// Class Invariants: //

class DLList {

    struct node
    {
        node* previous;
        node* next;
        ItemType data;

        // Explicit node constructor - manually set pointers
        node(ItemType init, node* prev, node* nex) : data(init), previous(prev), next(nex) {}
        // Implicit node constructor - pass in value
        node(ItemType init) : data(init), previous(NULL), next(NULL) {}

    };

    node* head;
    node* cursor;

    public:


// Main Functions//

// Post: an empty DLList is created
DLList ( void );

// Post: A DLList is destroyed.
~DLList ( void );

// Post: RETVAL(1) == The list is empty
bool IsEmpty ( void ) const;

// Post: RETVAL == Current is after last item in the list or
//      before the first item in the list
bool EndOfList ( void ) const;

// Pre: !IsEmpty()
// Post: The cursor is moved to the first item in the list
void Reset ( void );

// Pre: !IsEmpty() && !EndOfList()
// Post: the cursor is moved to the next item in the list
void Advance ( void );

// Pre: !IsEmpty() && !EndOfList()
// Post: the cursor is moved to the previous item
void Retreat ( void );

// Pre: !IsEmpty() && !EndOfList()
// Post: RETVAL == Item at the cursor
ItemType CurrentItem( void );

// Pre: !IsEmpty()&& !EndOfList()
// Post: Item at the cursor is deleted && the cursor points to the
//      successor of deleted item or IsEmpty() is true if the item
//      deleted was the last item in the list
void Delete( void );

// Pre: None
// Post: If the list was empty then Inserted is the only item in
//      the list. If EndOfList was true then Inserted is the new first
//      item in the list. Otherwise, Inserted is the predecessor of
//      the item that was current when the function was called.
//      Inserted is the new current item.
void InsertBefore ( /*in*/ const ItemType& Inserted );

// Pre: None
// Post: If the list was empty then Inserted is the only item in
//      the list. If EndOfList was true then Inserted is the new last
//      item in the list. Otherwise, Inserted is the successor of the
//      item that was current when the function was called. Inserted
//      is the new current item.
void InsertAfter ( /*in*/ const ItemType& Inserted );

// Post: List is displayed to standard out. This is used for
//      debugging only.
void Display ( void );

};

#endif
