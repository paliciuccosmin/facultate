#include <iostream>

using namespace std;

class Country {
public:
    virtual void getPopulation() const = 0;

    virtual void getCapital() const = 0;

    virtual void getOfficialLanguage() const = 0;
};

class Romania : public Country {
public:
    void getPopulation() const override {
        cout << "Populatia Romaniei este de aproximativ 19 milioane.\n";
    }

    void getCapital() const override {
        cout << "Capitala Romaniei este Bucuresti.\n";
    }

    void getOfficialLanguage() const override {
        cout << "Limba oficiala a Romaniei este limba romana.\n";
    }
};

class France : public Country {
public:
    void getPopulation() const override {
        cout << "Populatia Frantei este de aproximativ 67 milioane.\n";
    }

    void getCapital() const override {
        cout << "Capitala Frantei este Paris.\n";
    }

    void getOfficialLanguage() const override {
        cout << "Limba oficiala a Frantei este limba franceza.\n";
    }
};

class Bulgaria : public Country {
public:
    void getPopulation() const override {
        cout << "Populatia Bulgariei este de aproximativ 6,87 milioane.\n";
    }

    void getCapital() const override {
        cout << "Capitala Bulgariei este Sofia.\n";
    }

    void getOfficialLanguage() const override {
        cout << "Limba oficiala a Bulgariei este limba bulgara.\n";
    }
};

int main() {
    Romania romania;
    France france;
    Bulgaria bulgaria;

    cout << "Informatii despre Romania:\n";
    romania.getPopulation();
    romania.getCapital();
    romania.getOfficialLanguage();

    cout << "\nInformatii despre Franta:\n";
    france.getPopulation();
    france.getCapital();
    france.getOfficialLanguage();

    cout << "\nInformatii despre Bulgaria:\n";
    bulgaria.getPopulation();
    bulgaria.getCapital();
    bulgaria.getOfficialLanguage();

    return 0;
}
