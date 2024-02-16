#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Apartment {
    private:
        int nrCamere;
        double suprafata;
        int etaj;
        int	totalEtaje;
        int sector;
        int scor;	
        int pret;
    public:
        Apartment()
        {
            this->nrCamere = 0;
            this->suprafata = 0;
            this->etaj = 0;
            this->totalEtaje = 0;
            this->sector = 0;
            this->scor = 0;
            this->pret = 0;
        }
        Apartment(int nrCamere, double suprafata, int etaj, int totalEtaje, int sector, int scor, int pret) {
            this->nrCamere = nrCamere;
            this->suprafata = suprafata;
            this->etaj = etaj;
            this->totalEtaje = totalEtaje;
            this->sector = sector;
            this->scor = scor;
            this->pret = pret;
        }
    bool filtrareDupaNrCamere(int n) {
        if (this->nrCamere == n)
            return true;
        else
            return false;      
    }
    bool filtrareDupaPret(int pretMin, int pretMax) {
        if (this->pret >= pretMin && this->pret <= pretMax)
            return true;
        else
            return false;
    }
    void afisare() {
        cout<<"Numar camere: "<<this->nrCamere<<" Suprafata: "<<this->suprafata<<" Etaj: "<<this->etaj<<" Total etaje: "<<this->totalEtaje<<" Sector: "<<this->sector<<" Scor: "<<this->scor<<" Pret: "<<this->pret<<endl;
    }
    int getSector() {
        return this->sector;
    }
    int getNrCamere() {
        return this->nrCamere;
    }
    int getPret() {
        return this->pret;
    }
    double getSuprafata() {
        return this->suprafata;
    }
};

class CSVReader {
public:
    vector<vector<string>> readCSV(const string& filePath) {
        vector<vector<string>> data;

        ifstream file(filePath);
        if (!file.is_open()) {
            cout << "Failed to open file: " << filePath << endl;
            return data;
        }

        string line;
        while (getline(file, line)) {
            vector<string> row;
            size_t pos = 0;
            string token;
            while ((pos = line.find(',')) != string::npos) {
                token = line.substr(0, pos);
                row.push_back(token);
                line.erase(0, pos + 1);
            }
            row.push_back(line);
            data.push_back(row);
        }

        file.close();
        return data;
    }
};

class CSVReaderFacade {
private:
    CSVReader csvReader;

public:
    vector<vector<string>> readCSV(const string& filePath) {
        return csvReader.readCSV(filePath);
    }
};


int main() {
    CSVReaderFacade csvReaderFacade;
    vector<vector<string>> data = csvReaderFacade.readCSV("Bucharest_HousePriceDataset.csv");
    Apartment* apartments = new Apartment[data.size()]; 
    for(int i = 0; i < data.size(); i++) {
        int nrCamere = stoi(data[i][0]);
        double suprafata = stod(data[i][1]); 
        int etaj = stoi(data[i][2]); 
        int totalEtaje = stoi(data[i][3]); 
        int sector = stoi(data[i][4]); 
        int scor = stoi(data[i][5]); 
        int pret = stoi(data[i][6]); 

        apartments[i] = Apartment(nrCamere, suprafata, etaj, totalEtaje, sector, scor, pret);
    }
    cout<<"Introduceti numarul de camere: ";
    int nr;
    cin>>nr;
    vector<Apartment> favorites; // Create a vector to store favorite apartments
    for(int i=0; i < data.size(); i++)
        if(apartments[i].filtrareDupaNrCamere(nr) == true)
        {
            cout<<i<<" ";
            apartments[i].afisare();
        }
    cout<<"Doriti sa adaugati un apartament in lista de favorite? (1/0) ";
    int raspuns;
    cin>>raspuns;
    if(raspuns == 1)
    {
        cout<<"Introduceti numarul apartamentului: ";
        int nrApartament;
        cin>>nrApartament;
        cout<<"Apartamentul a fost adaugat in lista de favorite!"<<endl;
        favorites.push_back(apartments[nrApartament]);

        int sectorApartament = apartments[nrApartament].getSector();
        int nrCamereApartament = apartments[nrApartament].getNrCamere();
        int pretApartament = apartments[nrApartament].getPret();

        int recomandari = 0;
        for (int i = 0; i < data.size() && recomandari < 3; i++) {
            if (apartments[i].getSector() == sectorApartament && apartments[i].getNrCamere() == nrCamereApartament) {
                int difPret = abs(apartments[i].getPret() - pretApartament);
                double difPretPercentage = (double)difPret / pretApartament * 100;
                if (difPretPercentage <= 15 && i != nrApartament) {
                    cout << "Recomandare: ";
                    apartments[i].afisare();
                    favorites.push_back(apartments[i]);
                    recomandari++;
                }
            }
        }
    }
    else
        cout<<"Nu ati adaugat niciun apartament in lista de favorite!"<<endl;
    cout<<"Introduceti pretul minim: ";
    int pretMin;
    cin>>pretMin;
    cout<<"Introduceti pretul maxim: ";
    int pretMax;
    cin>>pretMax;
    for(int i=0; i < data.size(); i++)
        if(apartments[i].filtrareDupaPret(pretMin, pretMax) == true)
        {
            cout<<i<<" ";
            apartments[i].afisare();
        }
    cout<<"Doriti sa adaugati un apartament in lista de favorite? (1/0) ";
    cin>>raspuns;
    if(raspuns == 1)
    {
        cout<<"Introduceti numarul apartamentului: ";
        int nrApartament;
        cin>>nrApartament;
        cout<<"Apartamentul a fost adaugat in lista de favorite!"<<endl;
        favorites.push_back(apartments[nrApartament]);

        int sectorApartament = apartments[nrApartament].getSector();
        int nrCamereApartament = apartments[nrApartament].getNrCamere();
        int pretApartament = apartments[nrApartament].getPret();

        int recomandari = 0;
        for (int i = 0; i < data.size() && recomandari < 3; i++) {
            if (apartments[i].getSector() == sectorApartament && apartments[i].getNrCamere() == nrCamereApartament) {
                int difPret = abs(apartments[i].getPret() - pretApartament);
                double difPretPercentage = (double)difPret / pretApartament * 100;
                if (difPretPercentage <= 15 && i != nrApartament) {
                    cout << "Recomandare: ";
                    apartments[i].afisare();
                    favorites.push_back(apartments[i]);
                    recomandari++;
                }
            }
        }
    }
    else
        cout<<"Nu ati adaugat niciun apartament in lista de favorite!"<<endl;

    
    return 0;
}
