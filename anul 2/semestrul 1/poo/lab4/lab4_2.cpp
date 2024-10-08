#include <iostream>
#include <string>

using namespace std;

class Mamifere {
public:
    Mamifere() {
         cout << "Constructor Mamifere" <<  endl;
        type = "Mamifer";
    }

protected:
     string type;
};


class Vertebrate {
public:
    Vertebrate() {
         cout << "Constructor Vertebrate" <<  endl;
        spine = true;
    }

protected:
    bool spine;
};


class Caine : public Mamifere, public Vertebrate {
public:

    Caine() : Mamifere(), Vertebrate() {
         cout << "Constructor Caine" <<  endl;
         cout << "Tip: " << this->type << ", Are coloana vertebrala: " << (this->spine ? "Da" : "Nu") <<  endl;
    }


    Caine( string animalType, bool hasSpine) : Mamifere(), Vertebrate() {
         cout << "Constructor Caine" <<  endl;
        this->type = animalType;
        this->spine = hasSpine;
         cout << "Tip: " << this->type << ", Are coloana vertebrala: " << (this->spine ? "Da" : "Nu") <<  endl;
    }
};

int main() {
     cout << "Caine creat implicit:" <<  endl;
    Caine rex;
     cout << "\n------------------\n";
     cout << "Caine creat cu parametri:" <<  endl;
    Caine labrador("Labrador", true);

    return 0;
}
