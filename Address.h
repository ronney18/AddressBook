//Include the Address header file
#ifndef ADDRESS_H
//Define the Address header file
#define ADDRESS_H

//Include the input/output stream library
#include <iostream>
//Include the string library
#include <string>
//Using the standard namespace resolution
using namespace std;

class Address 
{
    //Define all the public functions for this class
    public:
        //Setting a default constructor
        Address();
        /* 
         * Setting a constructor to pass the street address, city, state, and
         * the ZIP code as a parameter.
         */
        Address(string street, string city, string state, string zipCode);
        //Setting the street address for the person
        void SetStreetAddress(string street);
        //Getting the street address for the person
        string GetStreetAddress() const;
        //Setting the city for the person
        void SetCity(string city);
        //Getting the city for the person
        string GetCity() const;
        //Setting the state for the person
        void SetState(string state);
        //Getting the state for the person
        string GetState() const;
        //Setting the ZIP code for the person
        void SetZIP(string zipCode);
        //Getting the ZIP code for the person
        string GetZIP() const;
        
    //Define all the private variables for this class
    private:
        //Store the street address to a variable
        string streetAddress;
        //Store the city to a variable
        string city;
        //Store the state to a variable
        string state;
        //Store the ZIP code to a variable
        string ZIP;
};

#endif

