// Matthew Dingman
// Professor Qouneh

// PhoneBook.h header file

// This file is used to instantiate the PhoneBook class defined in the
// PhoneBook.cpp file. The Record class is used.

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include"Record.h"
using namespace std;
const int MAXSIZE = 10;

class PhoneBook {
  private:
    Record list[MAXSIZE];
    string bookName;
    int num_records;
    int findName(string s);
  public:
    PhoneBook();
    PhoneBook(string s);
    string getPhoneBookName();
    int getNumberofRecords();
    void insert(string name, int number);
    void displayPhoneBook();
    void removeName(string s);
    int getPhoneNumber(string s);
    ~PhoneBook();
};
