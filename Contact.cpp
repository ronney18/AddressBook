//Include the Contact header file
#include "Contact.h"

//Setting a default constructor
Contact::Contact() 
{
    
}
/* Setting a constructor to pass the birth date, phone number, address, and the
 * relationship status as a parameter
 */
Contact::Contact(string birth, string number, string address, string relationship) 
{
    //Assign the birth date to the class variable
    birthDate = birth;
    //Assign the phone number to the class variable
    phoneNumber = number;
    //Assign the address to the class variable
    this->address = address;
    //Assign the relationship status to the class variable
    relationshipStatus = relationship;
}
//Setting the date for the person's birth date
void Contact::SetBirthDate(string birth)
{
    //Try to set the date to the class variable 
    try
    {
        //Check for errors on the date format
        Contact::ErrorChecking(birth);
        //Set the date to the class variable
        birthDate = birth;
    }
    //Catching for errors on the date format
    catch(runtime_error& excpt)
    {
        //Display the error to the user
        cout << excpt.what() << endl;
    }
}
//Getting the birth date of the person
string Contact::GetBirthDate()
{
    //Return the birth date to the user
    return birthDate;
}

//Checking for errors on the date format
void Contact::ErrorChecking(string& birth)
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
    stringstream streamDate(birth);
    /*
     * I am referencing these steps to Walter Manter's idea.
     * He help me solve this date format using these steps.
     */
    //Loop through the date string
    for(int i = 0; i < birth.length(); i++)
    {
        //Increment the counter if the current element is a forward slash
        if(birth.at(i) == '/')
        {
            //Increment the counter
            count = count + 1;
        }
    }
    
    //Throw an error if the counter is not equal to 2
    if(count != 2)
    {
        //Throw an error to the user
        throw runtime_error("ERROR: You must include two \"/\" to separate the month, day, and year.");
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
        throw runtime_error("ERROR: There are 12 months in a year.");
    }
    //Checking for the months that has 31 days
    if((month == 1) || (month == 3) || (month == 5) || (month == 7) || 
            (month == 8) || (month == 10) || (month == 12))
    {
        //Throw an error if the day is less than 1 or greater than 31
        if((day < 1) || (day > 31))
        {
            //Throw an error to the user
            throw runtime_error("ERROR: Days must be between 1 and 31.");
        }
    }
    //Checking for the months that has 30 days
    if((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        //Throw an error if the day is less than 1 or greater than 30
        if((day < 1) || (day > 30))
        {
            //Throw an error to the user
            throw runtime_error("ERROR: Days must be between 1 and 30.");
        }
    }
    //Checking for the month of February
    if((month == 2) && ((day < 1) || (day > 29)))
    {
        //Throw an error if the day is less than 1 or greater than 29
        throw runtime_error("Days must be between 1 and 29.");
    }
    
    //Throw an error if the year is after the current year
    if(year > 2020)
    {
        //Throw an error to the user
        throw runtime_error("ERROR: You can't be born after the current year.");
    }
    
    //Clear the date from the string stream
    streamDate.clear();
    //Output the proper format of the date to the user
    streamDate << month << "/" << day << "/" << year << std::endl;
    //Assign the string stream to the date 
    birth = streamDate.str();
}
//Setting the Address for the person
void Contact::SetAddress(string address)
{
    //Set the address to the class variable
    this->address = address;
}
//Getting the address for the person
string Contact::GetAddress()
{
    //Return the address to the user
    return address;
}

//Setting the phone number for the person
void Contact::SetPhoneNumber(string number)
{
    //Set the phone number to the class variable
    phoneNumber = number;
}

//Getting the phone number for the person
string Contact::GetPhoneNumber() const
{
    //Return the phone number to the user
    return phoneNumber;
}
//Setting the relationship status for the person
void Contact::SetRelationshipStatus(string relationship)
{
    //Set the relationship status to the class variable
    relationshipStatus = relationship;
}
//Getting the relationship status for the person
string Contact::GetRelationshipStatus() const
{
    //Return the relationship status to the user
    return relationshipStatus;
}
//Printing the contact information to the user
void Contact::PrintContactInfo()
{
    //Print the person's name
    Person::PrintName();
    //Print the birth date to the screen
    cout << "Birth Date: " << birthDate << endl;
    //Print the address to the screen
    cout << "Address: " << address << endl;
    //Print the phone number to the screen
    cout << "Phone Number: " << phoneNumber << endl;
    //Print the relationship status to the screen
    cout << "Relationship Status: " << relationshipStatus << endl;
    cout << "-----------------------------" << endl;
}