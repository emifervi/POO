/*
 * The program receives a string and creates an acronym based on the first letter of each word.
 * Author: Emilio Fernando Alonso Villa A00959385.
 * Date: 16 January 2018.
 */

#include <iostream>
#include <string>
using namespace std;

/**
  * The function takes the string provided by the user, searches the first letter of each word
  * and passes it to an auxiliary string in uppercase format.
  * Arguments: string containing the user sentence.
  * Returns: none, but prints the acronym.
  */
void Acronym(string userSentence){

    // Auxiliary string to store uppercase letters.
    string acro = "";

    // Goes through every element of the string searching for spaces and storing letters.
    for(int i = 0; i < userSentence.length() - 1; i++){

        // Stores the first letter.
        if(i == 0){
            acro += toupper(userSentence[i]);
        }

        // Stores every letter after a space.
        else{
            if (userSentence[i] == ' '){
            acro += toupper(userSentence[i + 1]);
            }
        }
    }

  // Prints the acronym.
  cout << acro;
}

/**
  * The main function, asks the user for a sentence and stores it in a string, then calls the Acronym function.
  * Arguments: none.
  * Returns: zero value to finish program.
  */
int main(){

    // Declare variable to store the user sentence.
    string mySentence;

    // Ask for sentence and stores it.
    cout << "Give me a sentence to create an acronym.\n";
    getline(cin, mySentence);

    // Calls the Acronym function.
    Acronym(mySentence);

    return 0;
}
