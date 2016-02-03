/*-- DList.cpp-----------------------------------------------------------
 
 This file implements List member functions.
 -------------------------------------------------------------------------*/

#include <cassert>
#include <new>
using namespace std;

#include "DList.h"

//--- Definition of class constructor
List::List(int maxSize)
: mySize(0), myCapacity(maxSize)
{
    myArray = new ElementType[maxSize];  // program will abort if
    // allocation fails
}

//--- Definition of class destructor
List::~List()
{
    delete [] myArray;
}

//--- Definition of copy constructor
List::List(const List & origList)
: mySize(origList.mySize), myCapacity(origList.myCapacity)
{
    //--- Get new array for copy
    myArray = new ElementType[myCapacity];  // program will abort if
    // allocation fails
    
    //--- Copy origList's elements into this new array
    for(int i = 0; i < mySize; i++)
        myArray[i] = origList.myArray[i];
    
}

//--- Definition of assignment operator
const List & List::operator=(const List & rightHandSide)
{
    if (this != &rightHandSide)  // check that not self-assignment
    {
        //-- Allocate a new array if necessary
        if (myCapacity != rightHandSide.myCapacity)
        {
            delete[] myArray;
            myCapacity = rightHandSide.myCapacity;
            myArray = new ElementType[myCapacity];  // program will abort if
            // allocation fails
            
        }
        //--- Copy rightHandSide's list elements into this new array
        mySize = rightHandSide.mySize;
        for(int i = 0; i < mySize; i++)
            myArray[i] = rightHandSide.myArray[i];
    }
    return *this;
}

//--- Definition of empty()
bool List::empty() const
{
    return mySize == 0;
}

//--- Definition of display()
void List::display(ostream & out) const
{
    for (int i = 0; i < mySize; i++)
        out << myArray[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList)
{
    aList.display(out);
    return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
  //  assert( mySize < myCapacity );   // check if there is room for item
    
    if(mySize == myCapacity)
        setCapacity(myCapacity *2);
    
    assert( pos >= 0 && pos <= mySize ); // is insert position legal?
    
    // First shift array elements right to make room for item
    
    for(int i = mySize; i > pos; i--)
        myArray[i] = myArray[i - 1];
    
    // Now insert item at position pos and increase list size
    myArray[pos] = item;
    mySize++;
}

//--- Definition of erase()
void List::erase(int pos)
{
    assert( !empty() );
    assert( pos >= 0 && pos < mySize ); // is delete position legal?
    
    // Shift array elements left to close the gap
    for(int i = pos; i < mySize; i++)
        myArray[i] = myArray[i + 1];
    
    // Decrease list size
    mySize--;
}

/*Update the capacity of the list
 ----------------------------------------------------------------------
 Change the capacity of the list
 
 Precondition:  None.
 Postcondition: The list's current capacity is changed to newCapacity
 (but not less than the number of items already in the list).
 -----------------------------------------------------------------------*/
void List::setCapacity( int newCapacity){
    if (newCapacity < this->mySize){
        newCapacity = this->mySize;
    }
    if (newCapacity==this->myCapacity) {
        return;
    }
    
    ElementType * myNewArray = new ElementType[newCapacity];
    
    for (int i = 0; i < mySize; i++){
        myNewArray= myArray;
    }
    delete [] myArray;
    this->myArray = myNewArray;
    this->myCapacity = newCapacity;
}

int List::getSize( ) const{
    int size = this->mySize;
       return size;
}
/*----------------------------------------------------------------------
 Return the size of the list
 
 Precondition:  None.
 Postcondition: The return value is the number of elements in the list
 (the list size).
 -----------------------------------------------------------------------*/

int List::getCapacity( ) const{
    
    return this->myCapacity;
}
/*----------------------------------------------------------------------
 Return the capacity of the list
 
 Precondition:  None.
 Postcondition: The return value is the maximum number of elements that the list can hold
 (the list capacity).
 -----------------------------------------------------------------------*/