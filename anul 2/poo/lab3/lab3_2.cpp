#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Student {
private:
    string nume, prenume, facultate, cnp;
    int an_nastere, an_infiintare_facultate;

public:
    void setNume(string nume) {
        this->nume = nume;
    }

    void setPrenume(string prenume) {
        this->prenume = prenume;
    }

    void setFacultate(string facultate) {
        this->facultate = facultate;
    }

    void setAn_nastere() {
        if (stoi(cnp.substr(0, 1)) == 1 || stoi(cnp.substr(0, 1)) == 2)
            this->an_nastere = stoi(cnp.substr(1, 2)) + 1900;
        else if (stoi(cnp.substr(0, 1)) == 5 || stoi(cnp.substr(0, 1)) == 6)
            this->an_nastere = stoi(cnp.substr(1, 2)) + 2000;
    }

    void setAn_infiintare(int an) {
        this->an_infiintare_facultate = an;
    }

    void setCNP(string cnp) {
        this->cnp = cnp;
    }

    string getCNP() {
        return this->cnp;
    }

    void checkSex() {
        int first_digit = stoi(this->cnp.substr(0, 1));
        if (first_digit == 1 || first_digit == 5) {
            cout << "It's a boy!" << endl;
        } else if (first_digit == 2 || first_digit == 6) {
            cout << "It's a girl!" << endl;
        } else {
            cout << "Invalid CNP!" << endl;
        }
    }

    int getVarsta() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        return currentYear - this->an_nastere;
    }

    int getDiferenta_Nastere_Facultate() {
        return abs(this->an_infiintare_facultate - this->an_nastere);
    }
};

int main() {
    Student persoana1;
    persoana1.setCNP("5021004076333");
    persoana1.checkSex();
    persoana1.setAn_nastere();
    persoana1.setAn_infiintare(1818); 
    cout << "Persoana are: " << persoana1.getVarsta() << " ani." << endl;
    cout << "Diferenta intre anul nasterii si infiintarea facultatii: " << persoana1.getDiferenta_Nastere_Facultate();

    return 0;
}
