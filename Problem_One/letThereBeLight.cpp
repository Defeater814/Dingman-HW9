// Matthew Dingman
// Professor Qouneh

// letThereBeLight.cpp program

// This program turns the LED on when the pushbutton is being pressed and turns
// the LED off when the button is not being pressed. This program is run on the
// premise that GPIO pin 60 is configured to "gpio" and the direction is set to
// "out", and the GPIO pin 46 is configured to "gpio_input" and the direction is
// set to "in".

// Example Invocation: ./letThereBeLight

#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
#define LED_PATH "/sys/class/gpio/gpio60/value"
#define BUTTON_PATH "/sys/class/gpio/gpio46/value"

int main(int argc, char* argv[]) {
  ofstream LED;             // Opens a file stream for LED value
  ifstream BUTTON;          // Opens a file stream for BUTTON value
  LED.open(LED_PATH);
  BUTTON.open(BUTTON_PATH);
  string status;            // Creates a variable to send the value of button to

  getline(BUTTON, status);  // Reads the button value to the status variable
  if (status == "0") {      // If the button is pressed, turn on the LED
    cout << "Turning on the LED!" << endl;
    LED << 1;
  }
  else {                    // If the button is not pressed, turn off the LED
    cout << "Turning off the LED!" << endl;
    LED << 0;
  }
  LED.close();
  cout << "LED is set!" << endl;
  cout << "End of program" << endl;
}
