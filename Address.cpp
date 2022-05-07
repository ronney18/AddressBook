//Include the Address header file
#include "Address.h"

//Setting the Address default constructor
Address::Address() 
{
 
}

/* 
 * Setting a constructor to pass the street address, city, state, and
 * the ZIP code as a parameter.
 */
Address::Address(string street, string city, string state, string zipCode) 
{
    //Set the street address to the class variable
    streetAddress = street;
    //Set the city to the class variable
    this->city = city;
    //Set the state to the class variable
    this->state = state;
    //Set the ZIP code to the class variable
    ZIP = zipCode;
}

//Setting the street address for the person
void Address::SetStreetAddress(string street)
{
    //Set the street address to the class variable
    streetAddress = street;
}

//Getting the street address for the person
string Address::GetStreetAddress() const
{
    //Return the street address to the user
    return streetAddress;
}

//Setting the city for the person
void Address::SetCity(string city)
{
    //Set the city to the class variable
    this->city = city;
}

//Getting the city for the person
string Address::GetCity() const
{
    //Return the city to the user
    return city;
}

//Setting the state for the person
void Address::SetState(string state)
{
    //Set the state to the class variable
    this->state = state;
}

//Getting the state for the person
string Address::GetState() const
{
    //Return the state to the user
    return state;
}

//Setting the ZIP code for the person
void Address::SetZIP(string zipCode)
{
    //Set the zip code to the class variable
    ZIP = zipCode;
}

//Getting the ZIP code for the person
string Address::GetZIP() const
{
    //Return the ZIP code to the user
    return ZIP;
}