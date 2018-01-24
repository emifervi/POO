/*
 * The program asks the user for a file name to be open and the amount of lines they want to copy from the file (the last 'n' lines, provided by the user).
 * then the program calculates the amount of lines the file has, and at last scans the file looking for the lines asked by the user, then it copies them in
 * an output file.
 * Author: Emilio Fernando Alonso Villa A00959385.
 * Date: January 23rd, 2018.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
  * The function receive the name of the input file and scans it while it can assign lines to a variable and keeps a counter for that.
  * Arguments: the file name given by the FileCopy function.
  * Returns: the amount of lines the input file has.
  */
int LineCount (string inputFile){

    // Declares variable and assigns a file to open.
    ifstream readFile;
    readFile.open(inputFile.c_str());

    // Variable to store lines and to keep count.
    string sLine;
    int iLines = 0;

    // Scans file, while possible to assign lines to a string variable it keeps counting.
    while(getline(readFile, sLine)){
        iLines ++;
    }

    // Close file.gi
    readFile.close();

    // Returns counter with the amount of lines that the input file has.
    return iLines;
}


/**
  * The function receives the name of the file to open and the number of lines to copy, calls the line count function
  * to know how many lines the file has, then scans the file until some point and copies the lines when a certain condition is met.
  * Arguments: the file name passed from the main function, and the number of lines to copy also passed from main function.
  * Returns: none, but writes in the output file.
  */
void FileCopy(string fileName, int lines){

    // Variables to be used (input and output files, total files, a counter, string to receive lines from input file and the amount of lines to copy.
    ifstream readFile;
    ofstream outFile;
    int totalLines = LineCount(fileName), iCount = 0;
    int iCopy = totalLines - lines;
    string fileLine;

    // Assign the variables to the files and open the respective files.
    readFile.open(fileName.c_str());
    outFile.open("archSal.txt");

    // If the number of files given by the user is bigger than the total number of lines, it calls an error.
    if (lines > totalLines){
        cout << "Error, unable to make the copy.\n";
    }

    // Scans the file while it is possible to assign strings to a variable.
    while(getline(readFile, fileLine)){

        // Counts the number of lines scanned, when met it arrives to the lines to copy it starts
        // passing them to the output file.
        iCount ++;
        if (iCount > iCopy){
            outFile << fileLine << endl;
        }
    }

    // Closes the opened files.
    outFile.close();
    readFile.close();
}

/**
  * Main function asks the user for the name of the file and the number of lines to copy.
  * Arguments: none.
  * Returns: zero value to end program.
  */

int main(){

    // Declare variables to store name of the file to open and the number of lines to copy.
    string inFileName;
    int iLines;

    // Ask for the names and number of lines and store them.
    cout << "What is the name of the file you are looking for?\n";
    getline(cin, inFileName);

    cout << "How many lines do you want to copy ?\n";
    cin >> iLines;

    // Call the file copy function.
    FileCopy(inFileName, iLines);

    return 0;
}
