#include <iostream>
#include <string>

using namespace std;

class Singleton {
private:
    string nume, iubeste;

    static Singleton *instancePtr;

    Singleton() {}

public:

    Singleton(const Singleton &obj) = delete;


    static Singleton *getInstance() {
        if (instancePtr == NULL) {
            instancePtr = new Singleton();
        }
        return instancePtr;
    }


    void setValues(const string &nume, const string &iubeste) {
        this->nume = nume;
        this->iubeste = iubeste;
    }

    void print() const {
        cout << nume << " iubeste " << iubeste << "." << endl;
    }
};


Singleton *Singleton::instancePtr = nullptr;

int main() {

    Singleton *obiect = Singleton::getInstance();
    obiect->setValues("Cosmin", "POO");
    obiect->print();
    Singleton *obictNou = Singleton::getInstance();
    obictNou->print();  


    return 0;
}
/*
Pros:
Asigură că o clasă are doar o instanță și furnizează un punct global de acces la aceasta.
Eficient pentru resursele care sunt costisitoare în privința inițializării (de exemplu, conexiuni la baze de date).

Cons:
Poate introduce probleme de concurență într-un mediu cu mai multe fire de execuție.
Poate ascunde dependențele reale ale clasei, făcând testarea unitară dificilă.
*/