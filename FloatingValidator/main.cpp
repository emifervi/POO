/*
*The program takes a floating number as a string and checks if the number provided is in fact a string or not.
*Author: Emilio Fernando Alonso Villa A00959385
*Date: 16 January 2018
*/
#include <iostream>
#include <string>

using namespace std;

/**
  * The function takes the string and checks if the string provided by the user is a floating point or not.
  * Arguments: string with supposed floating point number.
  * Returns: none, but prints the result.
  */

void floatChecker (string fNumber){

    // Variables to be used by the function.
    int dotCounter = 0;
    bool flag = true;

    // The loop goes through every element of the string in a backwards movement.
    for(int i = 0; i < fNumber.length() - 1; i++){

        // Counts the number of points and checks if there is more than one.
        if (fNumber[i] == '.'){
            dotCounter ++;
        }
        if (dotCounter > 1){
            flag = false;
        }

        // Checks that the characters of the string are either numbers or periods.
        if ((fNumber[i] < 48 || fNumber[i] > 57) || fNumber[i] != '.'){
            flag = false;
        }

    }

    // If the boolean is false tells the user it is not a valid number, if its true tells it is a valid number.
    if(!flag){
        cout << "number is not valid\n";
    }
    else{
        cout << "number is valid\n";
    }
}

/**
  * The main function  asks for the a number stores it in a string and calls the checker function.
  * Arguments: none.
  * Returns: 0 to finish the program.
  */
int main()
{
    // Declare variables that are going to be used in the program.
    string number;

    // Asks for a string and receives it storing it in a variable called "number".
    cout << "give a floating point number\n";
    getline(cin, number);

    // Calls void function.
    floatChecker(number);

    return 0;
}
