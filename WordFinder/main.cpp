/*
 * The program scans two files, one with random text and one with words, it uses the word data bank
 * to search those words in the random text file, then it tells the user the number of times each word
 * of the bank is repeated.
 * Author: Emilio Alonso Villa A00959385.
 * Date: January 23rd, 2018.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/** The function scans through the long string and check every substring of the long from a position given by the counter
  * and with the length of the word we are looking for.
  * Arguments: string taken from a file in main function, word taken from a file in main function and appearances passed by
  * main function.
  * Returns: the number of appearances of a word.
  */
int WordCompare (string sentence, string word, int appearances){

    // Loop to scan the long string and compare.
    for (int i = 0; i < sentence.length() - 1; i++){

        // If the substring matches the word we are looking for, then we add to the counter.
        if (sentence.substr(i, word.length()) == word){
            appearances++;
        }
    }

    // Return the number of times the word is repeated.
    return appearances;
}

/**
  * The main function, opens the files that will be scanned, receives words and scans both files
  * uses the WordCompare function to check how many times a word is repeated and prints it.
  * Arguments: none.
  * Returns: zero value to end function.
  */
int main(){

    // Declare variables for files, strings and an appearance counter.
    ifstream inTextFile, inWordFile;
    string textLine, wordSearch;
    int iCount;

    // Open file with words to open, and assign to variable.
    inWordFile.open("Palabras.txt");

    // Scan to the file with words and receive a word.
    while(getline(inWordFile, wordSearch)){

        // Counter at 0 because no appearances yet
        iCount = 0;

        // Open file with multiple sentences, scan it and call the word compare function.
        inTextFile.open("Texto.txt");
        while(getline(inTextFile, textLine)){
            iCount = WordCompare(textLine, wordSearch, iCount);
        }

        // Print in the console screen the word and how many times it appears in the long text.
        cout << wordSearch << " is repeated " << iCount << " times.\n";

        // Close both files.
        inTextFile.close();
    }

    inWordFile.close();

    return 0;
}
