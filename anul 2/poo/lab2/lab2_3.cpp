#include <iostream>
#include <cstring>

using namespace std;

class Sibling {
private:
    char *nume, *prenume;
    int varsta; // Changed varsta to int
public:
    Sibling(const char *n, const char *p, int v); // Updated constructor to take an int for varsta
    Sibling(const char *n, const char *p);
    Sibling(const char *n);
    Sibling(const Sibling &);
    ~Sibling();

    void afisare() {
        cout << "NUME: " << this->nume << "\nPRENUME: " << this->prenume << "\nVARSTA: " << varsta << "\n";
    }
    void update(const char *nume, const char *prenume, int varsta); // Updated update method to take an int for varsta
    void updateNume(const char *string);
    void updateVarsta(int age); // Updated updateVarsta method to take an int
    void updatePrenume(const char *string);
};

Sibling::Sibling(const Sibling &initial) {
    nume = new char[strlen(initial.nume) + 1];
    prenume = new char[strlen(initial.prenume) + 1];
    varsta = initial.varsta;
    strcpy(nume, initial.nume);
    strcpy(prenume, initial.prenume);
}

Sibling::~Sibling() {
    delete[] this->nume;
    delete[] this->prenume;
}

Sibling::Sibling(const char *n, const char *p, int v) {
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
    prenume = new char[strlen(p) + 1];
    strcpy(prenume, p);
    varsta = v;
}

Sibling::Sibling(const char *n, const char *p) {
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
    prenume = new char[strlen(p) + 1];
    strcpy(prenume, p);
    varsta = -1; // Default value for varsta
}

Sibling::Sibling(const char *n) {
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
    prenume = new char[strlen("NECUNOSCUT") + 1];
    strcpy(prenume, "NECUNOSCUT");
    varsta = -1; // Default value for varsta
}

void Sibling::update(const char *numeNou, const char *prenumeNou, int varstaNoua) {
    delete[] nume;
    delete[] prenume;
    nume = new char[strlen(numeNou) + 1];
    prenume = new char[strlen(prenumeNou) + 1];
    varsta = varstaNoua;
    strcpy(nume, numeNou);
    strcpy(prenume, prenumeNou);
}

void Sibling::updateNume(const char *numeNou) {
    delete[] nume;
    nume = new char[strlen(numeNou) + 1];
    strcpy(nume, numeNou);
}

void Sibling::updatePrenume(const char *prenumeNou) {
    delete[] prenume;
    prenume = new char[strlen(prenumeNou) + 1];
    strcpy(prenume, prenumeNou);
}

void Sibling::updateVarsta(int age) {
    varsta = age;
}

int main() {
    Sibling sibling1("Andrei", "Florea", 40);
    sibling1.afisare();
    Sibling sibling2 = sibling1;
    sibling2.afisare();
    sibling2.updateNume("Paul");
    sibling2.updateVarsta(30);
    sibling1.afisare();
    sibling2.afisare();
    return 0;
}
