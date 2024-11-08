# Matthew Dingman
# Professor Qouneh

# build.sh build file

# This file is used to create a build file for the myApp.cpp file using the
# Record.cpp file and the PhoneBook.cpp file.

echo "Creating a build file.."

g++ -g myApp.cpp PhoneBook.cpp Record.cpp -o myApp

echo "Build file successfully created!"
