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

Book::Book(string s, int i, double p){
    author = s;
    title = i;
    price = p;
}
void Book::setAuthor(string a){
    author = a;
}
void Book::setTitle(int i){
    title = i;
}
void Book::setPrice(double p){
    price = p;
}
string Book::getAuthor(){
    return author;
}
int Book::getTitle(){
    return title;
}
double Book::getPrice(){
    return price;
}
double Book::raisePrice(double p){
    price += ((p * price)/100.00);
    return price;
}
void Book::display(){
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Price: " << price << endl;
}


#endif // BOOK_H_INCLUDED
