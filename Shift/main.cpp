// The program allows the user to fill in an array and then it lets the user either see his/her array or shift it to the right.
// Author: Emilio Fernando Alonso Villa A00959385.
// Date: 9 January 2018.

#include <iostream>
using namespace std;

// Declare global variables to be used.
int iSize, iX, iAux;
char cOption;
int Menu(int arrMenu[]);

// Pre-declare functions.
void ShiftRight(int cloneData[]);
void PrintArray(int printData[]);

// Menu for the multiple options of the user.
// Arguments: array with the data given by the user.
// Returns: returns 0 to end program in case of choosing the case 'e'.
int Menu(int arrMenu[]){

    cout << "Do you want to print (p) or shift (s) or end program (e) your array?\n";
    cin >> cOption;

    switch(cOption)
    {
        case 'p' | 'P':
            PrintArray(arrMenu);
            break;

        case 's' | 'S':
            ShiftRight(arrMenu);
            break;

        case 'e' | 'E':
            return 0;

        default:
            cout << "Error, invalid input.\n";

    }
}

// Allows user to fill in the array.
// Arguments: Array with the data given by the user.
// Return: no return, is void function.
void FillData(int fillData[]){

    cout << "Fill the array.\n";

    // lets the user fill the array.
    for (iX = 0; iX < iSize; iX++){
        cin >> fillData[iX];
    }
}

// Shifts array data to the right, then calls menu for the user.
// Arguments: Array with the data given by the user.
// Return: no return, is void function.
void ShiftRight(int cloneData[]){

    // Variable to store a value that will be lost in the loop.
    iAux = cloneData[iSize - 1];

    // Shifts the array to the right and assigns the stored value to the first element of the array.
    for (iX = iSize; iX >= 0; iX--){
        cloneData[iX + 1] = cloneData[iX];
        if (iX == 0){
            cloneData[iX] = iAux;
        }
    }

    // Calls menu to let user take a decision of what to do.
    Menu(cloneData);
}

// Prints the data in the array.
// Arguments: Array with the data given by the user.
// Return: no return, is void function.
void PrintArray(int printData[]){

    for (iX = 0; iX < iSize; iX++){
        cout << printData[iX] << " ";
    }
}

int main(){
    // lets the user select a size for the array.
    do{
        cout << "What's the size of your array ? (max of 12)\n";
        cin >> iSize;
    }while(iSize <= 0 || iSize > 12);

    int arrData[iSize];

    FillData(arrData);
    Menu(arrData);

    return 0;
}
