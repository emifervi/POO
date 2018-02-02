/**
  * The program allows the user to create a registry of a book with its title, the author and a price.
  * It displays the info of the book and allows the user to raise the price of the book by a given percent.
  * Author: Emilio Fernando Alonso Villa | A00959385.
  * Date: January 31st, 2018.
  */
#include <iostream>
#include <string>
using namespace std;
// Header of class to be used.
#include "Book.h"

int main(){

    // Declare variables to be used.
    string author;
    int title;
    double price, percentage;
    char cOption;

    do{
    // Asks user for the info about the book and store in variables.
    cout << "+ What's the name of the author?\n";
    cin.ignore();
    getline(cin, author);
    cout << "\n+ Which title is it?\n";
    cin >> title;
    do{
        cout << "\n+ What's the price? ";
        cin >> price;
    }while (price <= 0);

    // Declare object of class book and assign values to the attributes.
    Book regBook(author, title, price);

    // Display the info given by the user about the book.
    regBook.display();

    // Display the current price and ask which percent of that price do they want to raise the cost of the book.
    do{
        cout << "\n+ Current price: " << regBook.getPrice() << "\nWhich percent do you want to raise the price ? ";
        cin >> percentage;
    }while(percentage <= 0);

    // Call raisePrice method of the class Book.
    regBook.raisePrice(percentage);

    // Display new data about the book.
    cout << "\n+ New data about the book: \n";
    regBook.display();

    // Ask if the user wants to go at it again with another book.
    cout << "\n+ Do you want to do another one? (y/n).\n";
    cin >> cOption;

    }while (tolower(cOption) != 'n');

    return 0;
}
