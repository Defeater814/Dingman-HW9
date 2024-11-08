// Matthew Dingman
// Professor Qouneh

// Record.h header file

// This file is used to instantiate the Record class defined in the Record.cpp
// file.

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

class Record {
  private:
    string name;
    int number;
  public:
    Record();
    Record(string name, int number);
    string getName();
    int getNumber();
    void setName(string s);
    void setNumber(int n);
    ~Record();
};
