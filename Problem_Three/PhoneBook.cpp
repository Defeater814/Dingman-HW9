// Matthew Dingman
// Professor Qouneh

// Phonebook.cpp definition file

// This file is used to define the PhoneBook class instantiated in the
// PhoneBook.h file. The Record class is used.

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include"PhoneBook.h"
using namespace std;

int PhoneBook::findName(string s){
  for (int i = 0; i < num_records; i++) {
    if (list[i].getName() == s) {
      return i;
    }
  }
  return 20;
}

PhoneBook::PhoneBook() {
}

PhoneBook::PhoneBook(string s) {
  bookName = s;
  num_records = 0;
}

string PhoneBook::getPhoneBookName() {
  return bookName;
}

int PhoneBook::getNumberofRecords() {
  return num_records;
}

void PhoneBook::insert(string name, int number) {
  if (num_records == 10) {
    cout << "PhoneBook is full!" << endl;
  }
  else {
    list[num_records].setName(name);
    list[num_records].setNumber(number);
    num_records++;
    cout << name << " has been added to the Phonebook." << endl;
  }
}

void PhoneBook::displayPhoneBook() {
  for (int i = 0; i < num_records; i++) {
    cout << list[i].getName() << " : " << list[i].getNumber() << endl;
  }
}

void PhoneBook::removeName(string s) {
  int index = findName(s);
  if (index != 20) {
    for (int i = index; i < num_records - 1; i++) {
      list[i] = list[i + 1];
    }
    num_records--;
    cout << "Record removed successfully." << endl;
  }
  else {
    cout << "That name is not in the Phonebook!" << endl;
  }
}

int PhoneBook::getPhoneNumber(string s) {
  int index = findName(s);
  if (index == 20) {
    return -1;
  }
  else {
    return list[index].getNumber();
  }
}

PhoneBook::~PhoneBook(){
}
