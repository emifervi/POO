/*
 *The program asks for a sentence and then a key word, after that it proceeds to change that word for the character *.
 *Author: Emilio Alonso Villa A00959385.
 *Date: January 16th 2018.
 */

#include <iostream>
#include <string>

using namespace std;

/**
  * The function takes the user sentence and keyword and replaces the keyword with an asterisk.
  * Arguments: the string provided by the user, and the keyword.
  * Returns: no returns, prints user string modified.
  */
void Censorship(string usrString, string someWord){

    // Goes through the loop looking for the substring of the keyword.
    for (int i = 0; i < usrString.length() - 1 ; i++){

        // When it finds the keyword, it modifies the original string replacing it with an asterisk.
        if(usrString.substr(i, someWord.length()) == someWord){
            usrString.replace(i, someWord.length(), "*");
        }
    }

    // Prints the modified string.
    cout << usrString;
}

/**
  * Main function, asks for a sentence and a keyword and stores in separated string variables.
  * Arguments: none.
  * Returns: zero value to end program.
  */
int main()
{
    // Variables to store the strings.
    string myString, word;

    // Asks for a sentence and stores it in a variable.
    cout << "Give me your sentence.\n";
    getline(cin, myString);

    // Asks for a keyword and stores it in a variable.
    cout << "Which word should we censor.\n";
    getline(cin, word);

    // Calls the Censorship function.
    Censorship(myString, word);

    return 0;
}
