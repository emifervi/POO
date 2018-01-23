/*
 * The program allows the user to create a student registry with name and age of each student, student by student.
 * Afterwards it asks the user if they want to register another student or if they want to search for an age.
 * If age is selected then the program will tell the user how many students above the provided age exist in the registry,
 * Author: Emilio Fernando Alonso Villa A00959385.
 * Date: January 19th, 2018.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;


// Declare global variables.
ofstream outFile;
ifstream inFile;
string studentName;
int studentAge, searchAge, iCount;
char cOption;
bool fileCreated = false;

/**
  * The Function asks the user for the name of the student, and his/her age then stores it in variable that are passed to the output file to store
  * then it asks the user if he/she wants to register another student.
  * Arguments: None.
  * Returns: None.
  */
void StudentRegistry(){

    // Assign file to an output file variable and opens it.
    outFile.open("Students.txt");

    do{
        // Gets name and age from the user and store them in variables passed to the file
        cout << "\n+ What is the student's name?\n";
        getline(cin, studentName);

        cout << "+ How old is he she? ";
        cin >> studentAge;

        outFile << studentAge << " " << studentName << endl;

        // Asks the user if they want to register more students, if they do repeat the process if not, it shows the menu again.
        cout << "\n+ Do you want to register another ?\n";
        cin >> cOption;
        cin.ignore();

        }while(cOption != 'n');

    cout << endl;

    // Close file and registers that the file has been created.
    outFile.close();
    fileCreated = true;
}

/**
  * The Function asks the user for an age to search for students that are older than the provided age, it opens the registry file and looks through all the ages
  * if they are older the system prints the name and the age of the student and counts how many of them are older than the given age.
  * Arguments: None.
  * Returns: None.
  */
void AgeSearch(){

    // Checks if file was created or not.

    iCount = 0;
    inFile.open("Students.txt");

    if(inFile.is_open()){
        // Asks for age to look for
        cout << "\n + Which age are you looking for?\n";
        cin >> searchAge;
        cout << endl;

        // Scans file looking for the names and ages of the students.
        while (inFile >> studentAge){

            // Gets the age and name and stores them in variables.
            getline(inFile, studentName);

            // Counts the number of students and prints the name and their age.
            if (studentAge > searchAge){
                cout << "+ " << studentName << " is " << studentAge << endl;
                iCount ++;
            }
        }

        // Prints the amount of students that are older than the given age.
        cout << "+ " <<  iCount << " students are older than " << searchAge << endl << endl;
        inFile.close();
    }

    // Tells user if file was not created, if it wasn't it displays menu again.
    else{
        cout << "+ Error the file has not been created yet, use option 1 first.\n";
    }
}

/**
  * The main function, displays menu, asks for user option.
  * Arguments: none.
  * Returns: zero value to end program.
  */
int main(){

    // Declare variables to be used.
    int menuOption;
    bool usingProgram = true;

    // Runs menu until user asks program to finish.
    do{
        // Presents menu and asks user to pick a choice.
        cout << "1.- Register a Student.\n" << "2.- Search for students older than...\n" << "3.- End program.\n";
        cout << "\nUser choice: ";
        cin >> menuOption;
        cin.ignore();

        switch(menuOption){
            // Calls the StudentRegistry function, when finishing clears screen and presents menu again.
            case 1:
                StudentRegistry();
                system("cls");
                break;

            case 2:
                // Calls the AgeSearch function, when finishing displays results, waits for the user to input any key and then clears screen and display menu
                AgeSearch();
                system("pause");
                system("cls");
                break;

            case 3:
                // The user decides to end program, change bool to false and breaks the loop.
                usingProgram = false;
                break;

            default:
                // If user gives another option, it tells the user it is not valid.
                cout << "ERROR: invalid input, please try again\n";
        }

    } while (usingProgram);

    return 0;
}
