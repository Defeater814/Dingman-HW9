// Matthew Dingman
// Professor Qouneh

// myGpio.cpp definition file

// This definition file is used to define all of the objects in the MYGPIO class
// for the myGpio.h file.

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"myGpio.h"

MYGPIO::MYGPIO(int number) {
  path = "/sys/class/gpio/gpio" + to_string(number) + "/";
}

int MYGPIO::write(string path, string filename, string value) {
  ofstream file;
  file.open(path + filename);
  if (file.is_open()) {
    file << value;
    file.close();
    return 0;
  }
  cout << "There was an error writing" << endl;
  return 1;
}

int MYGPIO::write(string path, string filename, int value) {
  return write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename) {
  ifstream file;
  string line;
  file.open(path + filename);
  if (file.is_open()) {
    file >> line;
  }
  return line;
}

int MYGPIO::getNumber() {
  return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir) {
  if (dir == OUTPUT) {
    write(path, "direction", "out");
  }
  else {
    write(path, "direction", "in");
  }
}

GPIO_DIRECTION MYGPIO::getDirection() {
  string temp = read(path, "direction");
  return temp == "in" ? INPUT : OUTPUT;
}

int MYGPIO::setValue(GPIO_VALUE val) {
  write(path, "value", val);
  return 0;
}

GPIO_VALUE MYGPIO::getValue() {
  string temp = read(path, "value");
  return temp == "1" ? HIGH : LOW;
}

void MYGPIO::toggleOutput() {
  if (getDirection() == INPUT) {
    setDirection(OUTPUT);
  }
  else {
    setDirection(INPUT);
  }
}

MYGPIO::~MYGPIO() {
}
