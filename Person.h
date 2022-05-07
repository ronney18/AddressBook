//Include the Person header class
#ifndef PERSON_H
//Define the Person header class
#define PERSON_H
//Include the input/output stream library
#include <iostream>
//Include the string library
#include <string>
//Using the standard namespace resolution
using namespace std;

class Person 
{
    //Define all the public functions for this class
    public:
        //Setting the first name of the person
        void SetFirstName(string firstName);
        //Getting the first name of the person
        string GetFirstName() const;
        //Setting the last name of the person
        void SetLastName(string lastName);
        //Getting the last name of the person
        string GetLastName() const;
        //Printing the name of the person
        void PrintName();
        
    //Define the protected variables    
    protected:
        //Store the first name to a variable
        string firstName;
        //Store the last name to a variable
        string lastName;
};

#endif

