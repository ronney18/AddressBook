//Include the Contact header class
#ifndef CONTACT_H
//Define the Contact header class
#define CONTACT_H

//Include the Date header file
#include "Date.h"
//Include the Address header file
#include "Address.h"
//Include the Person header file
#include "Person.h"

//This class is derived from the Person class
class Contact:public Person
{
    //Define all the public functions for this class
    public:
        //Setting a default constructor
        Contact();
        //Setting a constructor to pass parameters
        Contact(string birth, string number, string address, string relationship);
        //Setting the birth date for the person
        void SetBirthDate(string birth);
        //Getting the birth date for the person
        string GetBirthDate();
        //Checking for errors on the date format
        void ErrorChecking(std::string& birth);
        //Setting the address for the person
        void SetAddress(string address);
        //Getting the address for the person
        string GetAddress();
        //Setting the phone number for the person
        void SetPhoneNumber(string number);
        //Getting the phone number for the person
        string GetPhoneNumber() const;
        //Setting the relationship status for the person
        void SetRelationshipStatus(string relationship);
        //Getting the relationship status for the person
        string GetRelationshipStatus() const;
        //Printing the contact info to the user
        void PrintContactInfo();
    //Define all the private variables for this class
    private:
        //Storing the birth date to a variable
        string birthDate;
        //Storing the address to a variable
        string address;
        //Storing the phone number to a variable
        string phoneNumber;
        //Storing the relationship status to a variable
        string relationshipStatus;

};

#endif

