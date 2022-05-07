//Include the Address Book header file
#include "AddressBook.h"

//Setting a default constructor
AddressBook::AddressBook()
{
    
}

//Reading the address book from a file
/*
 * I worked with Juan and Stephen to create this function.
 */
void AddressBook::ReadFromFile()
{
    //Initialize the limit to 0
    int limit = 0;
    //Declare a line of text
    string line;
    //Store the text file as an input file
    ifstream inFile("Addresses.txt");
    
    try
    {
        //Throw an error if the file is not open
        if(!inFile.is_open())
        {
            //Throw the error
            throw runtime_error("Cannot open file!");
        }
        //Getting a line of text until the delimitor is reached
        while((getline(inFile, line)) && (limit <= 100))
        {
            //Call the string tokenizer function to pass the text with the delimitor
            StringToken(line, "=>");
            //Increment the limit by 1
            limit = limit + 1;
        }
    }
    //Catching an error if an error existed
    catch(runtime_error& excpt)
    {
        //Display the error to the user
        cout << excpt.what() << endl;
    }
}

//Setting up a string tokenizer
/*
 * I worked with Juan and Stephen to create this function.
 */
void AddressBook::StringToken(string line, const char* arrow)
{
    //Create a contact object
    Contact contact;
    //Initialize the size to the size of the line of text plus the null terminating character
    int size = line.size() + 1;
    //Declare an array of character with the size of the line of text
    char p[size];
    //Declare a character pointer
    char* word;
    //Initialize the index to 0
    int index = 0;
    //Copy the line of text and store it to the character array
    strcpy(p, line.c_str());
    //Assign the token to the word pointer
    word = strtok(p, arrow);
    
    while(word != NULL)
    {
        //Set the last name to the contact object if the index is 0
        if(index == 0)
        {
            //Set the last name to the contact object
            contact.SetLastName(word);
            //Increment the index by 1
            index = index + 1;
        }
        //Set the first name to the contact object if the index is 1
        else if(index == 1)
        {
            //Set the first name to the contact object
            contact.SetFirstName(word);
            //Increment the index by 1
            index = index + 1;
        }
        //Set the birth date to the contact object if the index is 2
        else if(index == 2)
        {
            //Set the birth date to the contact object
            contact.SetBirthDate(word);
            //Increment the index by 1
            index = index + 1;
        }
        //Set the address to the contact object if the index is 3
        else if(index == 3)
        {
            //Set the address to the contact object
            contact.SetAddress(word);
            //Increment the index by 1
            index = index + 1;
        }
        //Set the phone number to the contact object if the index is 4
        else if(index == 4)
        {
            //Set the phone number to the contact object
            contact.SetPhoneNumber(word);
            //Increment the index by 1
            index = index + 1;
        }
        //Set the relationship status to the contact object if the index is 5
        else
        {
            //Set the relationship status to the contact object
            contact.SetRelationshipStatus(word);
            //Add the contact object to the vector
            list.push_back(contact);
        }
        //Move the word pointer to the next line in the file
        word = strtok(NULL, arrow);
    }
}
//Sorting the Address Book by last name
void AddressBook::SortByLastName()
{
    //Create a contact object
    Contact temp;
    //Loop through the contact vector using a nested loop
    for(int i = 0; i < list.size(); i++)
    {
        for(int x = 0; x < list.size(); x++)
        {
            //Bubble sort the contact objects if they are out of order
            if(list.at(x).GetLastName() > list.at(i).GetLastName())
            {
                //Store the next contact to temp
                temp = list.at(x);
                //Assign the current contact to the next contact
                list.at(x) = list.at(i);
                //Assign temp to the current contact
                list.at(i) = temp;
            }
        }
    }
    //Display a message to the user that the address book is already sorted
    cout << "Address book already sorted!!" << endl << endl;
}

//Searching through the Address Book by last name
void AddressBook::SearchByLastName(string lastName)
{
    //Put the first character of the name as uppercase if it is lowercase
    if(islower(lastName.at(0)))
    {
        //Put the first character of the name as uppercase
        lastName.at(0) = toupper(lastName.at(0));
    }
    //Initialize the counter to 0
    int count = 0;
    cout << "SEARCHING BY LAST NAME" << endl;
    //Loop through the contact vector
    for(int i = 0; i < list.size(); i++)
    {
        //Print the contact information if the last name matches
        if(list.at(i).GetLastName() == lastName)
        {
            //Print the contact information
            list.at(i).PrintContactInfo();
        }
        //Increment the counter by 1 if the last name is not found
        else
        {
            //Increment the counter by 1
            count = count + 1;
        }
    }
    //Display an error if the last name is not found
    if(count == list.size())
    {
        //Display the error
        cout << "Sorry! This last name is not found." << endl;
    }
}

//Printing the address book by the birth month
void AddressBook::PrintByBirthMonth(string month)
{
    //Initialize the counter to 0
    int count = 0;
    cout << "PRINTING ADDRESS BOOK BY BIRTH MONTH" << endl;
    //Loop through the contact vector
    for(int i = 0; i < list.size(); i++)
    {
        //Initialize p to the first instance of the month followed by the forward slash
        int p = list.at(i).GetBirthDate().find(month);
        //Print the contact information if the instance of the month is found
        if((list.at(i).GetBirthDate().find(month) != string::npos) && 
                (list.at(i).GetBirthDate().find("/") > p))
        {
            //Print the contact information
            list.at(i).PrintContactInfo();
        }
        //Increment the counter by 1 if the month is not found
        else
        {
            //Increment the counter by 1
            count = count + 1;
        }
    }
    //Display an error if the birth month is not found
    if(count == list.size())
    {
        //Display the error
        cout << "Sorry! No results found." << endl;
    }
}

//Printing the Address Book between two last names
void AddressBook::PrintBetweenTwoLastNames(string last1, string last2)
{
    //Put the first character of the first last name as uppercase if it is lowercase
    if(islower(last1.at(0)))
    {
        //Put the first character of the first last name as uppercase
        last1.at(0) = toupper(last1.at(0));
    }
    //Put the first character of the second last name as uppercase if it is lowercase
    if(islower(last2.at(0)))
    {
        //Put the first character of the second last name as uppercase
        last2.at(0) = toupper(last2.at(0));
    }
    //Testing if the first last name comes after the second last name
    if(last2 <= last1)
    {
        //Assign the second last name to temp
        string temp = last2;
        //Assign the second last name to the first last name
        last2 = last1;
        //Assign temp to the second last name
        last1 = temp;
    }
    cout << "PRINTING ADDRESS BOOK BETWEEN TWO LAST NAMES" << endl;
    //Loop through the contact vector
    for(int i = 0; i < list.size(); i++)
    {
        //Print the contact information if the last name is within the range of the alphabet between the two last names
        if((list.at(i).GetLastName() >= last1) && (list.at(i).GetLastName() <= last2))
        {
            //Print the contact information
            list.at(i).PrintContactInfo();
        }
    }
}

//Printing the person's information
void AddressBook::PrintPersonInfo(string lastName, string firstName)
{
    //Put the first character of the last name as uppercase if it is lowercase
    if(islower(lastName.at(0)))
    {
        //Put the first character of the last name as uppercase
        lastName.at(0) = toupper(lastName.at(0));
    }
    //Put the first character of the first name as uppercase if it is lowercase
    if(islower(firstName.at(0)))
    {
        //Put the first character of the first name as uppercase
        firstName.at(0) = toupper(firstName.at(0));
    }
    //Initialize the counter to 0
    int count = 0;
    cout << "Searching for " << firstName << " " << lastName << "..." << endl;
    //Loop through the contact vector
    for(int i = 0; i < list.size(); i++)
    {
        //Print the contact information if both first and last name matches
        if((list.at(i).GetLastName() == lastName) && (list.at(i).GetFirstName() == firstName))
        {
            //Print the contact information
            list.at(i).PrintContactInfo();
        }
        //Increment the counter by 1 if both first and last name does not match
        else
        {
            //Increment the counter by 1
            count = count + 1;
        }
    }
    
    //Display an error if there are no matches for the full name
    if(count == list.size())
    {
        //Display the error
        cout << "Sorry! No results found." << endl;
    }
}

//Printing the entire address book
void AddressBook::PrintAddressBook()
{
    cout << "ADDRESS BOOK" << endl;
    //Loop through the contact vector
    for(int i = 0; i < list.size(); i++)
    {
        //Print the entire address book to the user
        list.at(i).PrintContactInfo();
    }
}
