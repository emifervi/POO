/*
 * The program reads a text file with students from multiple groups, then checks to which group corresponds each student
 * by checking the last character of each line.
 * Author: Emilio Fernando Alonso Villa A00959385.
 * Date: January 22nd, 2018
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declare file variables as global.
ifstream inFile;
ofstream grupo1, grupo2, grupo3;

/**
  * The function reads each line of the file and sorts the students by comparing the last char of the line with the number of group.
  * Arguments: none.
  * Returns: none.
  */
void Sorter(){
    // Variable to store each line of the file.
    string studentInfo;

    while (!inFile.eof()){

        // Reads each line of the file.
        getline(inFile, studentInfo);

        // If the last character of the line is equal to each number, the student is sorted to his/her respective group.
        if (studentInfo[studentInfo.length() - 1] == '1'){

            // Deletes the last char to eliminate the group number.
            studentInfo.erase(studentInfo.length() - 2);
            grupo1 << studentInfo << endl;
        }
        if (studentInfo[studentInfo.length() - 1] == '2'){

            // Deletes the last char to eliminate the group number.
            studentInfo.erase(studentInfo.length() - 2);
            grupo2 << studentInfo << endl;
        }
        if (studentInfo[studentInfo.length() - 1] == '3'){

            // Deletes the last char to eliminate the group number.
            studentInfo.erase(studentInfo.length() - 2);
            grupo3 << studentInfo << endl;
        }
    }
}

/**
  * The main function, opens the files, writes the tile of each file, calls the Sorter function.
  * Arguments: none.
  * Returns: zero value to end program.
  */
int main(){

    // Open input file and assign variable to it.
    inFile.open("SemanaI.txt");

    // Open output files, assign variables and write the title on each file.
    grupo1.open("Grupo1.txt");
    grupo1 << "**** Grupo 1 ****" << endl;

    grupo2.open("Grupo2.txt");
    grupo2 << "**** Grupo 2 ****" << endl;

    grupo3.open("Grupo3.txt");
    grupo3 << "**** Grupo 3 ****" << endl;

    // Calls Sorter function.
    Sorter();

    // Closes files before finishing the program.
    inFile.close();
    grupo1.close();
    grupo2.close();
    grupo3.close();

    return 0;
}
