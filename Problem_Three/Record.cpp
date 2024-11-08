// Matthew Dingman
// Professor Qouneh

// PhoneBook.cpp definition file

// This file is used to define the Record class that is instantiated in the
// Record.h file.

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include"Record.h"
using namespace std;

Record::Record() {
}

Record::Record(string name, int number) {
  setName(name);
  setNumber(number);
}

string Record::getName() {
  return name;
}

int Record::getNumber() {
  return number;
}

void Record::setName(string s) {
  name = s;
}

void Record::setNumber(int n) {
  number = n;
}

Record::~Record() {
}


  
