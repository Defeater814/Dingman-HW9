// Matthew Dingman
// Professor Qouneh

// myGpioApp.cpp application

// This application uses the myGpio.cpp and myGpio.h files to utilize the MYGPIO
// class. For testing, the application sets the LED object at GPIO pin 60 and
// the BUTTON object at GPIO pin 46. It sets their directions as input and
// output respectively, then prints the direction. The LED is then turned on,
// waits 3 seconds, then turns the LED off. The values of the BUTTON and the LED
// are printed as these actions are done.

// Example invocation: ./myGpioApp

#include<unistd.h>
#include<iostream>
#include<string>
using namespace std;
#include"myGpio.h"

int main(int argc, char* argv[]) {
  // GPIO60 is P9.12
  // GPIO46 is P8.16
  MYGPIO LED(60);     // Creates LED and BUTTON gpio objects with their respective pins
  MYGPIO BUTTON(46);

  LED.setDirection(OUTPUT);     // Sets the direction of LED as OUTPUT
  BUTTON.setDirection(INPUT);   // Sets the direction of BUTTON as INPUT

  cout << "The direction of the LED is: " << (LED.getDirection() == INPUT ? "in": "out") << endl;        // Prints the direction of the previously-set LED and BUTTON
  cout << "The direction of the BUTTON is: " << (BUTTON.getDirection() == INPUT ? "in" : "out") << endl;
  cout << endl;

  LED.setValue(HIGH);   // Turns the LED on, then prints the value of the LED using the getValue() function
  cout << "The value of the LED is: " << (LED.getValue() == 0 ? "LOW" : "HIGH") << endl;
  sleep(3);             // Waits 3 seconds
  LED.setValue(LOW);    // Turns the LED off, then prints the value of the LED using the getValue() function
  cout << "The value of the LED is: " << (LED.getValue() == 0 ? "LOW" : "HIGH") << endl;
  cout << endl;
  cout << "The value of the BUTTON is: " << (BUTTON.getValue() == 0 ? "HIGH" : "LOW") << endl;    // Prints the value of the button using the getValue() function
}
