//
//  main.cpp
//  List Implementation
//  Poject #3
//  Data Structures
//  Created by Aaron on 2/2/16.
//
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
using namespace std;
#include "DList.h"

// PROTOTYPES:
void print_menu( );
// Postcondition: A menu of choices has been printed.

int get_number( );
// Postcondition: The user has been prompted to enter an integer number. The
// number has been read, echoed to the screen, and returned by the function.

int main( )
{
    List test;     // A List to perform tests on
    char choice;   // Command entered by the user
    
    std::cout << "I have initialized an empty list of integers." << std::endl;
    
    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice;
        choice = toupper(choice);
        int newNumbers = 0;
        int position = 0;
        int newCapacity = 0;
        switch (choice)
        {
            case 'A':

                cout<< "\nHow many new number to add?";
                cin >>newNumbers;
                for (int i =0;i < newNumbers;i++){
                    position = test.getSize();
                    test.insert(rand() %1000, position);
                }
                break;
            case 'C':
                cout<<"\nEnter the new capacity as a number of integers:";
                cin>> newCapacity;
                test.setCapacity(newCapacity);
                cout<<"New capacity is "<< test.getCapacity();
                break;
            case 'E':
                cout<<"\nResults of empty(): ";
                cout<<test.empty();
                break;
            case 'P':
                cout<<"\nPrinting List: ";
                test.display(cout);
                break;
            case 'I':
                cout<< "\nWhich position to insert?";
                cin>>position;
                cout<<"\nInserting random value into position "<<position<<endl;
                test.insert(rand() %1000, position);
                break;
            case 'R':
                cout<< "\nWhich position to erase?";
                cin>>position;
                test.erase(position);
                break;
            case 'Q': cout << "Test program ended." << endl;
                exit(0);
                break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    
    return EXIT_SUCCESS;
}

void print_menu( )
{
    std::cout << std::endl;
    std::cout << "The following choices are available: " << endl;
    cout << " A   Add a number of random integers to end of list" << endl;
    cout << " C   Change the capacity of the list using the setCapacity function" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Remove a number with the erase( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}


int get_number( )
// Library facilities used: iostream
{
    int result;
    
    cout << "Please enter an integer number for the list: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}


