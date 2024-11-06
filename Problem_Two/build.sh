# Matthew Dingman
# Professor Qouneh

# build.sh build file

# This file creates a build file for the myGpioApp.cpp file, which uses the
# myGpio.h and myGpio.cpp files to use the MYGPIO class.

echo -e "Configuring GPIO60 as 'gpio'..\n"

echo $(config-pin p9.12 gpio)

echo -e "\nConfiguration of GPIO60 complete!\n"

echo -e "Configuring GPIO46 as 'gpio_pu'..\n"

echo $(config-pin p8.16 gpio_pu)

echo -e "\nConfiguration of GPIO46 complete!\n"

echo -e "Creating build file..\n"

g++ -g myGpioApp.cpp myGpio.cpp -o myGpioApp

echo -e "Build file created!"
