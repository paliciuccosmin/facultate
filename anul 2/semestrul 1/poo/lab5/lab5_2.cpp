#include <iostream>
#include <string>

using namespace std;


class Angajat {
protected:
    string nume;
    double salariuBaza;

public:
    Angajat(const string& nume, double salariuBaza)
        : nume(nume), salariuBaza(salariuBaza) {}

    virtual void afiseazaDetalii() const {
        cout << "Nume: " << nume << ", Salariu de baza: " << salariuBaza << endl;
    }

    virtual void calculeazaSalariu() {
        cout << "Calcul salariu pentru Angajat: " << salariuBaza << endl;
    }
};


class Manager : public Angajat {
protected:
    double bonusManager;

public:
    Manager(const string& nume, double salariuBaza, double bonusManager)
        : Angajat(nume, salariuBaza), bonusManager(bonusManager) {}

    void afiseazaDetalii() const override {
        cout << "Nume: " << nume << ", Salariu de baza: " << salariuBaza << ", Bonus Manager: " << bonusManager << endl;
    }

    void calculeazaSalariu() override {
        double salariuTotal = salariuBaza + bonusManager;
        cout << "Calcul salariu pentru Manager: " << salariuTotal << endl;
    }
};


class Director : public Manager {
protected:
    double bonusDirector;

public:
    Director(const string& nume, double salariuBaza, double bonusManager, double bonusDirector)
        : Manager(nume, salariuBaza, bonusManager), bonusDirector(bonusDirector) {}

    void afiseazaDetalii() const override {
        cout << "Nume: " << nume << ", Salariu de baza: " << salariuBaza << ", Bonus Manager: " << bonusManager << ", Bonus Director: " << bonusDirector << endl;
    }

    void calculeazaSalariu() override {
        double salariuTotal = salariuBaza + bonusManager + bonusDirector;
        cout << "Calcul salariu pentru Director: " << salariuTotal << endl;
    }
};

int main() {
    Angajat angajat("Ion", 50000);
    Manager manager("Andrei", 60000, 10000);
    Director director("David", 70000, 10000, 20000);


    angajat.afiseazaDetalii();
    angajat.calculeazaSalariu();

    manager.afiseazaDetalii();
    manager.calculeazaSalariu();

    director.afiseazaDetalii();
    director.calculeazaSalariu();

    return 0;
}
