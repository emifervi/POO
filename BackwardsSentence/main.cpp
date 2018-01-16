/*
 * The program takes a sentence stores it as a string and prints the words of the sentence form last to first.
 * Author: Emilio Fernando Alonso Villa A00959385.
 * Date: 16 January 2018.
 */

#include <iostream>
#include <string>

using namespace std;

/**
  * The function takes the string provided by the user, and copies it in a auxiliary string from last word to first word.
  * Arguments: the string provided by the user.
  * Returns: none, but prints the string in backwards form.
  */
void backWriting(string userPhrase){

    // Declare variables to be used.
    int letterCounter = 1;
    string phraseCopy = "";

    // Checks in backwards motion every element of the string.
    for(int i = userPhrase.length() - 1; i >= 0; i--){

        // Counts every character that is not a space.
        if (userPhrase[i] != ' '){
            letterCounter ++;
        }

        // When it gets to a space character it copies that a substring to the auxiliary string containing the amount of character previously counted.
        if (userPhrase[i] == ' ' || i == 0){
            // When it gets to the end, adds a space to keep the format.
            if (i == 0){
                phraseCopy += " ";
            }

            // Adds the substring to the auxiliary string and resets the character counter.
            phraseCopy += userPhrase.substr(i, letterCounter);
            letterCounter = 1;
        }
    }

    // Prints the auxiliary string once it is finished.
    cout << phraseCopy;
}

/**
  * The main function, asks the user for a sentence and stores it in a string.
  * Arguments: none.
  * Returns: zero value to end program.
  */
int main(){

    // Declares variable to store string.
    string phrase;

    // Asks the user for a sentence and stores it in a string.
    cout << "Type in a sentence.\n";
    getline(cin, phrase);

    // Calls the backwards writing function and pases the user string as argument.
    backWriting(phrase);

    return 0;
}
