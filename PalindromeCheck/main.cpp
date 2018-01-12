//The program asks the user for a phrase and checks if it is a palindrome.
//Emilio Fernando Alonso Villa A00959385.
//11 January 2017.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string phrase;
    bool flag = true;
    cout << "Type the phrase that you want to analyze\n";
    getline(cin, phrase);

    //Erases the space characters.
    for(int i = 0; i < phrase.length(); i++){
        if(phrase[i] == ' '){
            phrase.erase(i,1);
        }
    }

    //Goes through the string from left to right and right to left,
    //compares each pair of characters converted to lowercases
    //if they are not equal the flag becomes false and breaks loop.
    for( int i = 0, j = phrase.length() - 1; i < (phrase.length())/2 && flag; i++, j--){
        if (tolower(phrase[i]) != tolower(phrase[j])){
            flag = false;
        }
    }

    //After analyzing the data it tells the user if it is a palindrome or not.
    if(flag){
        cout << "It is a palindrome.\n";
    }
    else{
        cout << "It is not a palindrome\n";
    }

    return 0;
}
