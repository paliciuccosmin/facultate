#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm> 
#include <numeric>

using namespace std;

class Country {
public:
    string countryName;
    string region;
    int surface;
    double populationInThousands;
    double PopulationDensity;
    int grossDomesticProduct;
    double growthRate;
    double perCapital;
    double economyAgriculture;
    double economyIndustry;
    double economyServices;
    double employmentAgriculture;
    double employmentIndustry;
    double employmentServices;
    double unemployment;
    double populationGrowthRate;

    // Constructor to initialize object using a CSV line
    Country(const vector<string>& tokens) {
        try {
            if (tokens.size() >= 14) {
                countryName = tokens[0];
                region = tokens[1];
                surface = stoi(tokens[2]);
                populationInThousands = stod(tokens[3]);
                PopulationDensity = stod(tokens[4]);
                grossDomesticProduct = stoi(tokens[5]);
                growthRate = stod(tokens[6]);
                perCapital = stod(tokens[7]);
                economyAgriculture = stod(tokens[8]);
                economyIndustry = stod(tokens[9]);
                economyServices = stod(tokens[10]);
                employmentAgriculture = stod(tokens[11]);
                employmentIndustry = stod(tokens[12]);
                employmentServices = stod(tokens[13]);
                unemployment = stod(tokens[14]);
                populationGrowthRate = stod(tokens[15]);
            } else {
                // Handle error or provide default values
                cerr << "Error: Insufficient tokens in the line.\n";
            }
        } catch (const std::exception& e) {
            // Handle the exception and print more information
            cerr << "Error converting string to number: " << e.what() << "\n";
            // You might want to log the problematic string or provide default values
        }
    }

    static bool compareByPopulation(const Country& c1, const Country& c2) {
        return c1.populationInThousands >= c2.populationInThousands;
    }
    static bool compareBySurface(const Country& c1, const Country& c2) {
        return c1.surface >= c2.surface;
    }
    static bool compareByGrossDomesticProduct(const Country& c1, const Country& c2) {
        return c1.grossDomesticProduct >= c2.grossDomesticProduct;
    }
};

class CSVReader {
private:
    string filename;

public:
    CSVReader(const string& filename) : filename(filename) {}

    vector<Country> readCSV() {
        ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            cerr << "Error opening the file.\n";
            return {};
        }

        string line;
        vector<Country> countries;

        // Skip the first line
        getline(inputFile, line);

        while (getline(inputFile, line)) {
            istringstream iss(line);
            string token;
            vector<string> tokens;

            while (getline(iss, token, ','))
             {  if(token=="...")
                    tokens.push_back(0);
                tokens.push_back(token);
            }

            countries.push_back(Country(tokens));
        }

        inputFile.close();

        return countries;
    }
};
/*(class Project extends Country{

}*/


// Function to print the top N countries based on population
void printTopCountriesByPopulation(const vector<Country>& countries) {//metoda de rezolvare
    // Sort countries by population (descending order)
    vector<Country> sortedCountries = countries;
    sort(sortedCountries.begin(), sortedCountries.end(), Country::compareByPopulation);

    // Print the top 5 countries based on population
    cout << "Top " << 5 << " countries based on population:\n";
    for (size_t i = 0; i < 5; ++i) {
        cout << sortedCountries[i].countryName << " - Population: " << sortedCountries[i].populationInThousands << " thousand\n";
    }
}
void printTopCountriesBySurface(const vector<Country>& countries) {
    // Sort countries by surface (descending order)
    vector<Country> sortedCountries = countries;
    sort(sortedCountries.begin(), sortedCountries.end(), Country::compareBySurface);

    // Print the top 5 countries based on surface
    cout << "Top " << 5 << " countries based on surface:\n";
    for (size_t i = 0; i < 5; ++i) {
        cout << sortedCountries[i].countryName << " - Surface: " << sortedCountries[i].surface << " km2\n";
    }
}
void printTopCountriesByGDP(const vector<Country>& countries) {
    // Sort countries by GDP (descending order)
    vector<Country> sortedCountries = countries;
    sort(sortedCountries.begin(), sortedCountries.end(), Country::compareByGrossDomesticProduct);

    // Print the top 5 countries based on GDP
    cout << "Top " << 5 << " countries based on GDP:\n";
    for (size_t i = 0; i <5; ++i) {
        cout << sortedCountries[i].countryName << " - GDP " << sortedCountries[i].grossDomesticProduct << " million current US$\n";
    }
}

int main() {
    string filename = "data.csv"; 
    CSVReader csvReader(filename);
    vector<Country> countries = csvReader.readCSV();

    // Use an iterator to remove countries not from Europe
    auto it = remove_if(
        countries.begin(),
        countries.end(),
        [](const Country& c) {
            return c.region.find("Europe") == string::npos;
        }
    );
    // Erase the removed countries from the vector
    countries.erase(it, countries.end());

    cout<<"--------------------------------------\n";
    // Print the top 5 countries based on population
    printTopCountriesByPopulation(countries);
    cout<<"--------------------------------------\n";
    // Print the top 5 countries based on population
    printTopCountriesBySurface(countries);
    cout<<"--------------------------------------\n";
    // Print the top 5 countries based on population
    printTopCountriesByGDP(countries);
    //Print the 
    string tara;
    getline(cin, tara);
    for(const auto& country : countries){
        if(tara==country.countryName){
            cout<<tara<<" Economy:Agriculture: "<< country.economyAgriculture<<"% Economy:Industry: "<< country.economyIndustry<<"% Economy:Services: "<<country.economyServices<<'%'<<endl;
            break;
        }
    }
    
    return 0;
}
