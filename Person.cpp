//Include the Person header file
#include "Person.h"

//Setting the person's first name
void Person::SetFirstName(string firstName)
{
    //Assign the first name to the class variable
    this->firstName = firstName;
}

//Getting the person's first name
string Person::GetFirstName() const
{
    //Return the first name to the user
    return firstName;
}

//Setting the person's last name
void Person::SetLastName(string lastName)
{
    //Assign the last name to the class variable
    this->lastName = lastName;
}

//Getting the person's last name
string Person::GetLastName() const
{
    //Return the last name to the user
    return lastName;
}

//Printing the person's name to the user
void Person::PrintName()
{
    //Output the person's full name to the screen
    cout << "Last Name: " << lastName << endl; 
    cout << "First Name: " << firstName << endl;
}
