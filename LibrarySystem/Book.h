#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

class Book{
private:
    // Attributes of the class.
    string author;
    int title;
    double price;

public:
    // Constructor method;
    Book();
    Book(string s, int i, double p);

    // Access and modification methods;
    void setAuthor(string a);
    void setTitle(int i);
    void setPrice(double p);
    string getAuthor();
    int getTitle();
    double getPrice();
    // Functional methods.
    double raisePrice(double p);
    void display();
};
// Default Constructor.
Book::Book (){
    author = "";
    title = 0;
    price = 0.0;
}
// Constructor that takes the arguments to create the object.
Book::Book(string s, int i, double p){
    author = s;
    title = i;
    price = p;
}

// Methods to set the modify of the attributes.
void Book::setAuthor(string a){
    author = a;
}
void Book::setTitle(int i){
    title = i;
}
void Book::setPrice(double p){
    price = p;
}

// Methods to access the value of the attributes.
string Book::getAuthor(){
    return author;
}
int Book::getTitle(){
    return title;
}
double Book::getPrice(){
    return price;
}

/*
 * Functional methods
 */
 // Raises the price of the book in turn by a given percentage.
double Book::raisePrice(double p){
    price += ((p * price)/100.00);
    return price;
}

// Displays the info of the book in the console.
void Book::display(){
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Price: " << price << endl;
}


#endif // BOOK_H_INCLUDED
