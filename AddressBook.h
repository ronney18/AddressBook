//Include the Address Book header file
#ifndef ADDRESSBOOK_H
//Define the Address Book header file
#define ADDRESSBOOK_H

//Include the Contact header file
#include "Contact.h"
//Include the vector library
#include <vector>
//Include the file stream library
#include <fstream>
//Include the C string library
#include <cstring>

class AddressBook 
{
    //Define all the public functions for this class
    public:
        //Setting a default constructor
        AddressBook();
        //Reading the Address Book from a file
        void ReadFromFile();
        //Setting up a string tokenizer
        void StringToken(string line, const char* arrow);
        //Sorting the Address Book by last name
        void SortByLastName();
        //Searching through the address book by last name
        void SearchByLastName(string lastName);
        //Printing the address book by birth month
        void PrintByBirthMonth(string month);
        //Printing the Address Book between two last names
        void PrintBetweenTwoLastNames(string last1, string last2);
        //Printing the person's information from the address book
        void PrintPersonInfo(string lastName, string firstName);
        //Printing the entire address book
        void PrintAddressBook();
    
    //Define all the private variables for this class
    private:
        //Store the array of contacts to a class variable
        vector<Contact> list;
};

#endif

