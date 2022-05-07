/*
 * Name: Ronney Sanchez
 * Date: 12/7/16
 * Course: CIS240 C++ Programming Language
 * Program: Address Book
 * Description: This program loads a list of contact from a file and stores the
 * list in an Address Book. The program could find the person by last name, by
 * birth month, by the range of the alphabet between two last names, and by the 
 * full name of the person.
 */

//Include the Address Book header file
#include "AddressBook.h"
//Using the standard namespace resolution

//Include the prototype to print the menu
void PrintMenu();

int main()
{
    //Initialize the character input to a space
    char option = ' ';
    //Initialize the first name to a space
    string firstName = " ";
    //Initialize the last name to a space
    string lastName = " ";
    //Initialize the first last name to a space
    string lastName1 = " ";
    //Initialize the second last name to a space
    string lastName2 = " ";
    //Initialize the month to a space
    string month = " ";
    //Create an Address Book object
    AddressBook myBook;
    //Read the address book from a file
    myBook.ReadFromFile();
    cout << "Welcome to the Address Book!" << endl;
    do
    {
        //Print the menu to the user
        PrintMenu();
        //Prompt the user for an input
        cin >> option;
        //Put the character as lowercase if it is uppercase
        if(isupper(option))
        {
            //Put the character as lowercase
            option = tolower(option);
        }
        //Display an error if the input is invalid
        if((option != 'a') && (option != 's') && (option != 'p') && 
            (option != 'b') && (option != 'm') && (option != 'o') &&
            (option != 'q'))
        {
            //Display the error
            cout << "This is an invalid menu option!" << endl;
        }
    //Validating the input
    }while((option != 'a') && (option != 's') && (option != 'p') && 
            (option != 'b') && (option != 'm') && (option != 'o') &&
            (option != 'q'));
    
    //Continue to loop through the menu until the user enters 'q' to quit
    while(option != 'q')
    {
        //Testing for each input
        switch(option)
        {
            //Sort the address book by last name if the user enters 'a'
            case 'a':
                //Sort the address book by last name
                myBook.SortByLastName();
                break;
            
            //Search by last name if the user enters 's'
            case 's':
                //Prompt the user for the person's last name
                cout << "Enter the person's last name: " << endl;
                cin >> lastName;
                //Display a new line
                cout << endl;
                //Search the address book by the person's last name
                myBook.SearchByLastName(lastName);
                break;
            
            //Print the person's information based on their full name if the user enters 'p'   
            case 'p':
                //Prompt the user for the person's first name
                cout << "Enter the person's first name: " << endl;
                cin >> firstName;
                //Prompt the user for the person's last name
                cout << "Enter the person's last name: " << endl;
                cin >> lastName;
                //Display a new line
                cout << endl;
                //Print the person's information based on their full name
                myBook.PrintPersonInfo(lastName, firstName);
                break;
            
            //Print between two last names if the user enters 'b'
            case 'b':
                //Prompt the user for the first last name
                cout << "Enter the first last name: " << endl;
                cin >> lastName1;
                //Loop through all the characters in the string
                for(int i = 0; i < lastName1.length(); i++)
                {
                    //Checking for any numbers on the string
                    while((lastName1.at(i) == '0') || (lastName1.at(i) == '1') ||
                            (lastName1.at(i) == '2') || (lastName1.at(i) == '3') ||
                            (lastName1.at(i) == '4') || (lastName1.at(i) == '5') ||
                            (lastName1.at(i) == '6') || (lastName1.at(i) == '7') ||
                            (lastName1.at(i) == '8') || (lastName1.at(i) == '9'))
                    {
                    
                        //Display an error if there are any numbers
                        cout << "No numbers on the name!" << endl;
                        //Prompt the user again for the first last name
                        cout << "Enter the first last name: " << endl;
                        cin >> lastName1;
                    }
                }
                //Prompt the user for the second last name
                cout << "Enter the second last name: " << endl;
                cin >> lastName2;
                //Checking for any numbers on the string
                for(int i = 0; i < lastName2.length(); i++)
                {
                    while((lastName2.at(i) == '0') || (lastName2.at(i) == '1') ||
                            (lastName2.at(i) == '2') || (lastName2.at(i) == '3') ||
                            (lastName2.at(i) == '4') || (lastName2.at(i) == '5') ||
                            (lastName2.at(i) == '6') || (lastName2.at(i) == '7') ||
                            (lastName2.at(i) == '8') || (lastName2.at(i) == '9'))
                    {
                        //Display an error if there are any numbers
                        cout << "No numbers on the name!" << endl;
                        //Prompt the user again for the second last name
                        cout << "Enter the second last name: " << endl;
                        cin >> lastName2;
                    }
                }
                //Display a new line
                cout << endl;
                //Print the address book between two last names
                myBook.PrintBetweenTwoLastNames(lastName1, lastName2);
                break;
            
            //Print people's information by the birth month if user enters 'm'   
            case 'm':
                do
                {
                    //Prompt the user for the month
                    cout << "Enter the month (integers between 1 and 12): " << endl;
                    cin >> month;
                    //Display an error if the month is less than 1 or greater than 12
                    if((month != "1") && (month != "2") && (month != "3") &&
                        (month != "4") && (month != "5") && (month != "6") &&
                        (month != "7") && (month != "8") && (month != "9") &&
                        (month != "10") && (month != "11") && (month != "12"))
                    {
                        //Display the error
                        cout << "The month needs to be between 1 and 12." << endl;
                    }
                //Validating the month
                }while((month != "1") && (month != "2") && (month != "3") &&
                        (month != "4") && (month != "5") && (month != "6") &&
                        (month != "7") && (month != "8") && (month != "9") &&
                        (month != "10") && (month != "11") && (month != "12"));
                //Insert a forward slash after the month number
                month.push_back('/');
                //Display a new line
                cout << endl;
                //Print the address book by the birth month
                myBook.PrintByBirthMonth(month);
                break;
            
            //Print the entire address book if the user enters 'o'
            default:
                //Display a new line
                cout << endl;
                //Print the entire address book
                myBook.PrintAddressBook();
                break;
        }
        
        do
        {
            //Print the menu to the user
            PrintMenu();
            //Prompt the user for an input
            cin >> option;
            //Put the character as lowercase if it is uppercase
            if(isupper(option))
            {
                //Put the character as lowercase
                option = tolower(option);
            }
            //Display an error if the input is invalid
            if((option != 'a') && (option != 's') && (option != 'p') && 
            (option != 'b') && (option != 'm') && (option != 'o') &&
            (option != 'q'))
            {
                //Display the error
                cout << "This is an invalid menu option!" << endl;
            }
        //Validating the input
        }while((option != 'a') && (option != 's') && (option != 'p') && 
            (option != 'b') && (option != 'm') && (option != 'o') &&
            (option != 'q'));
    }
    //Program ended
    return 0;
}

void PrintMenu()
{
    //Display the menu to the user
    cout << "a - Sort address book by last name" << endl;
    cout << "s - Search by last name" << endl;
    cout << "p - Print person's information" << endl;
    cout << "b - Print between two last names" << endl;
    cout << "m - Print by birth month" << endl;
    cout << "o - Print Address Book" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: " << endl;
}
