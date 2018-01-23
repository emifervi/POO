/*
 * The program opens 2 file inputs, receives strings from each one and when they are different it prints them out in the console.
 * Author: Emilio Fernando Alonso Villa A00959385.
 * Date: January 23rd, 2018.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Declare global variables of input files.
ifstream inFileOne, inFileTwo;

/**
  * The function reads the lines of the files and compares them, then they are different, it prints them in the console window.
  * Arguments: none.
  * Returns: none, but prints in console.
  */
void StringCompare(){

    // Declare string variable to store strings from the files.
    string fileOneLine, fileTwoLine;

    // Compare strings sequentially between files, if they are different, they get printed to the console.
    while(getline(inFileOne, fileOneLine) && getline(inFileTwo, fileTwoLine)){
        if ( fileOneLine != fileTwoLine){
            cout << "File One: " << fileOneLine << endl;
            cout << "File Two: " << fileTwoLine << endl;
        }
    }
}

/**
  * THe main function,
  * Arguments: none.
  * Returns: zero value to end program.
  */
int main(){

    // Open files and assign them to variables.
    inFileOne.open("ArchUno.txt");
    inFileTwo.open("ArchDos.txt");

    // Call a function that compares strings.
    StringCompare();

    // Closes files.
    inFileOne.close();
    inFileTwo.close();

    return 0;
}
