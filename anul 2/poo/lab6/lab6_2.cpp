#include <iostream>
using namespace std;


class Book {
private:
    string titlu;
    string autor;

public:
    Book() {
        titlu = "Cat timp infloresc lamaii";
        autor = "ZOULFA KATOUH";
    }

    virtual void print() {
        cout << "Gen: Necunoscut";
    }

    friend class Library; 
};

class Library {
public:
    virtual void display(Book &book) {
        cout << "Titlu: " << book.titlu << endl;
        cout << "Autor: " << book.autor << endl;
    }
};

class Fiction : public Book {
public:
    void print(){
        cout<<"Gen: Fictiune";
    }
};

int main()
 {
    Book book;
    Library lib;
    lib.display(book);
    Fiction fic;
    fic.print();

    return 0;
}