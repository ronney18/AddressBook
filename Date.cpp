//Include the Date header file
#include "Date.h"

//Setting a default constructor
Date::Date()
{
    
}

//Setting a constructor to pass a date as a parameter
Date::Date(std::string date)
{
    //Set the date to the class variable
    this->date = date;
}

//Setting the date for the person's birth date
void Date::SetDate(std::string date)
{
    //Try to set the date to the class variable 
    try
    {
        //Check for errors on the date format
        Date::ErrorChecking(date);
        //Set the date to the class variable
        this->date = date;
    }
    //Catching for errors on the date format
    catch(std::runtime_error& excpt)
    {
        //Display the error to the user
        std::cout << excpt.what() << std::endl;
    }
}
//Getting the date for the person's birth date
std::string Date::GetDate() const
{
    //Return the date to the user
    return date;
}

//Checking for errors on the date format
void Date::ErrorChecking(std::string& date)
{
    //Initialize the month to 1
    int month = 1;
    //Initialize the day to 1
    int day = 1;
    //Initialize the year to 1965
    int year = 1965;
    //Initialize the counter to 0
    int count = 0;
    
    //Declare a string stream to pass the date in the parameter
    std::stringstream streamDate(date);
    /*
     * I am referencing these steps to Walter Manter's idea.
     * He help me solve this date format using these steps.
     */
    //Loop through the date string
    for(int i = 0; i < date.length(); i++)
    {
        //Increment the counter if the current element is a forward slash
        if(date.at(i) == '/')
        {
            //Increment the counter
            count = count + 1;
        }
    }
    
    //Throw an error if the counter is not equal to 2
    if(count != 2)
    {
        //Throw an error to the user
        throw std::runtime_error("ERROR: You must include two \"/\" to separate the month, day, and year.");
    }
    
    //Read in the month as an integer
    streamDate >> month;
    //Read 256 characters and ignore the forward slash
    streamDate.ignore(256, '/');
    //Read in the day as an integer
    streamDate >> day;
    //Read 256 characters and ignore the forward slash
    streamDate.ignore(256, '/');
    //Read in the year as an integer
    streamDate >> year;
    //Throw an error if the month is less than 1 or greater than 12
    if((month < 1) || (month > 12))
    {
        //Throw an error to the user
        throw std::runtime_error("ERROR: There are 12 months in a year.");
    }
    //Checking for the months that has 31 days
    if((month == 1) || (month == 3) || (month == 5) || (month == 7) || 
            (month == 8) || (month == 10) || (month == 12))
    {
        //Throw an error if the day is less than 1 or greater than 31
        if((day < 1) || (day > 31))
        {
            //Throw an error to the user
            throw std::runtime_error("ERROR: Days must be between 1 and 31.");
        }
    }
    //Checking for the months that has 30 days
    if((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        //Throw an error if the day is less than 1 or greater than 30
        if((day < 1) || (day > 30))
        {
            //Throw an error to the user
            throw std::runtime_error("ERROR: Days must be between 1 and 30.");
        }
    }
    //Checking for the month of February
    if((month == 2) && ((day < 1) || (day > 29)))
    {
        //Throw an error if the day is less than 1 or greater than 29
        throw std::runtime_error("Days must be between 1 and 29.");
    }
    
    //Throw an error if the year is after the current year
    if(year > 2016)
    {
        //Throw an error to the user
        throw std::runtime_error("ERROR: You can't be born after the current year.");
    }
    
    //Clear the date from the string stream
    streamDate.clear();
    //Output the proper format of the date to the user
    streamDate << month << "/" << day << "/" << year << std::endl;
    //Assign the string stream to the date 
    date = streamDate.str();
}