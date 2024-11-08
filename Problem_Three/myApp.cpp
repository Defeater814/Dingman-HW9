// Matthew Dingman
// Professor Qouneh

// myApp.cpp application file

// This file creates a phone book using the PhoneBook class and the Record
// class. It presents the user with 5 options, any of which can be selected via
// terminal. The first option adds a name and a number to the phone book, the
// second retrieves a number attached to a name, the third displays the phone
// book, the fourth removes a person from the book, and the fifth quits the
// application. 

// Example invocation: ./myApp

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include"PhoneBook.h"
using namespace std;

int main(int argc, char* argv[]) {
  int select = 0; // Initializes variables for use
  string name; 
  int number;
  int loop = 1;
  PhoneBook book("Phone book"); // Creates the phone book
  while (loop == 1) { // Runs until the fifth option is selected, prompts user for input
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "1. Insert a name and a number." << endl;
    cout << endl;
    cout << "2. Get a number for a person." << endl;
    cout << endl;
    cout << "3. Display phone book." << endl;
    cout << endl;
    cout << "4. Remove a person from the phone book." << endl;
    cout << endl;
    cout << "5. Quit.";
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "Enter a choice: ";
    cin >> select;

    switch (select) { // Navigates through a case switch statement depending on the user's choice
      case 1:
        cout << endl;
        cout << "Enter a name: ";
        cin >> name;
        cout << endl;
        cout << "Enter a number: ";
        cin >> number;
        cout << endl;
        book.insert(name, number);
        break;
      case 2:
        cout << endl;
        cout << "Enter a name: ";
        cin >> name;
        cout << endl;
        if (book.getPhoneNumber(name) == -1) { // if the name doesn't exist, says so
          cout << name << "'s number is not in the phone book!" << endl;
        }
        else { // Prints number if the name exists
          cout << name << "'s number is " << book.getPhoneNumber(name) << endl;
        }
        break;
      case 3:
        cout << endl;
        book.displayPhoneBook();
        break;
      case 4:
        cout << endl;
        cout << "Enter a name";
        cin >> name;
        cout << endl;
        book.removeName(name);
        break;
      case 5:
        cout << "Quitting.." << endl;
        loop = 0;
        break;
      default: // Runs if the user inputs a number that isn't 1 - 5
        cout << "This is not one of the options, try again!" << endl;
        break;
    }
  }
}
