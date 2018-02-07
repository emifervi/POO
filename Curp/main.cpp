#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <cmath>
using namespace std;
#include "Citizen.h"

ifstream inpFile;
ofstream outFile;
Citizen person;
/*
 * The word counter function, takes a string and counts how many words does the string has.
 * Arguments: a string by the function that calls it.
 * Returns: an integer with the number of words a string has.
 */

int wordCounter (string sWord){
    int numWords = 1;

    for(int i = 0; i < sWord.length() - 1; i++){
        if (sWord[i] == ' '){
            numWords++;
        }
    }

    return numWords;
}

string reverseString(string s){

    string reverseS = "";

    for (int i = s.length() - 1; i >= 0; i--){
        reverseS += s[i];
    }

    return reverseS;
}
/*
 * The Pass Name function scans through the names given by the main function to separated them into
 * first name, second name, last name and mothers name in object form.
 * Arguments: string name provided by the main function.
 * Returns: none.
 */
void passName(string sName, int index, Citizen arrPeople[]){

    // Variables to be used in the function
    string lName = "", fName = "", mName = "", secName = "";
    int space = 0, appear, names;

    // Looks for the first Space in the Loop.
    for (int i = 0; sName[i] != ' '; i++){
        space++;
    }

    // Call for word counter to know how many names the person has
    names = wordCounter(sName);

    // Gets the last name of the person.
    for(int i = 0; i < space; i++){
        lName += sName[i];
    }

    arrPeople[index].setLastName(lName);

    // Case of one last name and one name.
    if (names == 2){
        for(int i = space + 1; i < sName.length(); i++){
            fName += sName[i];
        }
        arrPeople[index].setFirstName(fName);
    }

    // Rest of the cases
    else{
        appear = 0;

        // Scans to find the persons mothers name from the first blank to the next.
        for (int i = space + 1; sName[i] != ' '; i++){
            appear ++;
        }

        mName = sName.substr(space + 1, appear);
        arrPeople[index].setMothersName(mName);

        // In the case of three names, it scans for the first name, from the second space until the end.
        if (names == 3){
            appear += space + 1;
            space = 0;

            for(int i = appear + 1; i < sName.length(); i++){
                space++;
            }

            fName = sName.substr(appear + 1, space);
            arrPeople[index].setFirstName(fName);
        }

        // In the case of four names.
        if (names == 4){
            appear += space + 1;
            space = 0;

            // Scans for the first name from the last space stored until the next.
            for(int i = appear + 1; sName[i] != ' '; i++){
                space ++;
            }

            fName = sName.substr(appear + 1, space);
            arrPeople[index].setFirstName(fName);

            // Finally scans for the second name from the last space until the end.
            for (int i = appear + space + 2; i < sName.length(); i++){
                secName += sName[i];
            }

            arrPeople[index].setSecondName(secName);
        }
    }
}

/*
 * The function receives a string from main function which contains the date of birth,
 * then it scans through the string from different points to get the day, month and year of birth.
 * Arguments: a string passed from main function.
 * Returns: none.
 */
void passDate(string d, int index, Citizen arrPeople[]){

    // Variables to be used by the loops and to store the date, year and month;
    string year = "", month = "", day = "";

    // Scan from the end until space to get the year and copy it in another string.
    for (int i = d.length() - 1; d[i] != ' '; i--){
        year += d[i];
    }

    // Pass year as an attribute.
    arrPeople[index].setYear(reverseString(year));

    // Scan from the 6th place until the space to get the month and copy it in another string.
    for (int i = 6; d[i] != ' '; i++){
        month += d[i];
    }

    // Pass month as an attribute.
    arrPeople[index].setMonth(month);

    // Scan from the start until a space to get day and copy it in another string;
    for (int i = 0; d[i] != ' '; i++){
        day += d[i];
    }

    // Pass day as an attribute.
    arrPeople[index].setDay(day);
}

/*
 * The main function, opens the file and receives value for the variables to be passed to other functions.
 * Arguments: none.
 * Returns: zero value to end program.
 */
int main(){
    srand(time(NULL));
    // Variables to scan the file and pass arguments to a function.
    int appearance, i, position, lenght, iSize = 0, fileLine = 0;
    string fileName, info, name = "", date = "", gender = "", state = "", security = "";

    cout << "Type in the name of the file you will open:\n";
    getline(cin, fileName);

    // Open file to be used in the main program
    inpFile.open(fileName.c_str());
    outFile.open("CURP.txt");

    while(getline(inpFile, info)){
        iSize ++;
    }

    inpFile.close();

    Citizen arrPerson[iSize];

    inpFile.open("Ejemplo.txt");
    // Scan every line of the file and pass the string to variable "info"
    while(getline(inpFile, info)){
        i = 0;
        appearance = 0;

        // Scans through line fed by file and adds the characters until it finds the first comma.
        while(info[i] != ',' && appearance < 1){

            name += info[i];

            if (info[i] == ','){
                appearance++;
            }

            i++;
        }

        position = i;
        // Scans from two places after the comma found before until the next comma to get gender.
        for (int j = i + 2; info[j] != ','; j++){
            position++;
            gender += info[j];
        }

        // Pass gender string as gender attribute.
        arrPerson[fileLine].setGender(gender);

        appearance = 0;
        lenght = 0;
        for (int j = info.length() - 1; appearance < 6; j--){
            if (info[j] == ' '){
                appearance++;
            }
                lenght++;
        }

        // Scans through four spaces after the position obtained from the gender until it counts at least to spaces
        // to get to where the birth State is, then it copies into the state variable.
        if (info.substr(position + 13, 2) == "el"){
            for (int j = position + 16; j < info.length() - lenght; j++){
                state += info[j];
            }
        }
        else{
            for (int j = position + 13; j < info.length() - lenght; j++){
                state += info[j];
            }
        }
        // Pass state as state attribute.
        arrPerson[fileLine].setState(state);
        appearance = 1;

        // Scans through the line from the end to find the date of birth counting spaces.
        for (int i = info.length() - 1; appearance < 5 || info[i] != ' '; i--){
            if (info[i] == ' '){
                appearance ++;
            }

            date += info[i];
        }

        date = reverseString(date);

        // Calls the PassName function and resets the name string that is passed to the function.
        passName(name, fileLine, arrPerson);
        passDate(date, fileLine, arrPerson);

        // Call functional class methods
        arrPerson[fileLine].fourInitials();
        arrPerson[fileLine].dateDigits();
        arrPerson[fileLine].genderChar();
        arrPerson[fileLine].stateInitials();
        arrPerson[fileLine].lastConsonants();

        // Generate random numbers based on the year the person was born and pass them as attributes.
        if (stoi(arrPerson[fileLine].getYear()) <= 1999){

            arrPerson[fileLine].setPenDigit(itos(rand() % 10));
        }

        else if (stoi(arrPerson[fileLine].getYear()) > 1999){
            security += char((rand() % 26) + 'A');
            arrPerson[fileLine].setPenDigit(security);
        }
        arrPerson[fileLine].setLastDigit(itos(rand() % 10));
        arrPerson[fileLine].securityNum();
        arrPerson[fileLine].genLastDigit();

        // Call the method to get the curp modified by the previous methods.
        outFile << arrPerson[fileLine].getCurp() << endl;

        // Reset variables.
        date = "";
        name = "";
        gender = "";
        state = "";
        security = "";
        fileLine++;
    }

    inpFile.close();
    outFile.close();

    return 0;
}
