//Include the Date header file
#ifndef DATE_H
//Define the Date header file
#define DATE_H

//Include the input/output stream library
#include <iostream>
//Include the string library
#include <string>
//Include the string stream library
#include <sstream>
//Include the standard error exception library
#include <stdexcept>
//Using the standard namespace resolution
using namespace std;

class Date 
{
    //Define all the public functions for this class
    public:
        //Setting a default constructor
        Date();
        //Setting a constructor to pass a date as a parameter
        Date(string date);
        //Setting the date from the person's birth date
        void SetDate(string date);
        //Getting the date from the person's birth date
        string GetDate() const;
        //Checking for errors on the date format
        void ErrorChecking(string& date);
     
    //Define all the private variables for this class    
    private:
        //Storing the date to a class variable
        string date;
};

#endif

