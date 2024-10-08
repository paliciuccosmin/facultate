#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <chrono>
#include <time.h>
#include <iomanip>
using namespace std;

class CsvAdapter {
protected:
    string filename;
    vector<vector<string>> data;

    void processRow(const vector<int>& row) {
        int student=row[0];
        int sleep = row[1];
        int headaches = row[2];
        int academicPerformance=row[3];
        int studyLoad=row[4];
        int extracurricular=row[5];
        int stress=row[6];
    }

public:
    CsvAdapter(const string& filename) : filename(filename) {
        readData();
    }

    void displaySleepQualityInfo() {
        double avgSleepQuality = getAvgSleepQuality();
        cout << "Average Kindly Rate your Sleep Quality: " << avgSleepQuality << endl;
        auto breakdownSleepQuality = getBreakdownSleepQuality();
        cout << "Breakdown Sleep Quality:" << endl;
        for (const auto& entry : breakdownSleepQuality) {
            cout << entry.first << ": " << entry.second << " students" << endl;
        }
    }

protected:
    void readData() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening the CSV file." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            vector<int> row;
            stringstream ss(line);
            string cell;

            while (getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            processRow(row);
            data.push_back(row);
        }

        file.close();
    }

    double getAvgSleepQuality() const {
        double total = 0.0;
        for (const auto& row : data) {
            total += stod(row[1]);  // Use index 1 for the second column
        }
        return total / data.size();
    }

    map<string, int> getBreakdownSleepQuality() const {
        return getBreakdown(1);  // Use index 1 for the second column
    }

    map<string, int> getBreakdown(int columnIndex) const {
        map<string, int> breakdown;

        for (const auto& row : data) {
            string value = row[columnIndex];
            breakdown[value]++;
        }

        return breakdown;
    }
};

class Student : public CsvAdapter {
public:
    int student;
        int sleep;
        int headaches;
        int academicPerformance;
        int studyLoad;
        int extracurricular;
        int stress;
    using CsvAdapter::CsvAdapter;  // Inherit the constructor from CsvAdapter
};

class Professor {
public:
    Professor(const string& studentFilename) : student(studentFilename) {}

    void generateReport() const {
        ofstream reportFile("raport.txt");

        if (reportFile.is_open()) {
            reportFile << "Raport generat la: " << getCurrentUTCDateTime() << endl << endl;

            // Access student information and add it to the report
            student.displaySleepQualityInfo();

            // Add recommendations for stress reduction
            reportFile << endl << "Recomandari:" << endl;
            reportFile << "1. Realizati cercetari in timpul testelor pentru a diminua stresul." << endl;

            cout << "Raportul a fost generat cu succes." << endl;
        } else {
            cerr << "Eroare la deschiderea fisierului de raport." << endl;
        }
    }

private:
    string getCurrentUTCDateTime() const {
        auto now = chrono::system_clock::now();
        auto currentTime = chrono::system_clock::to_time_t(now);

        ostringstream oss;
        oss << put_time(gmtime(&currentTime), "%F %T UTC");

        return oss.str();
    }

    Student student;
};

int main() {
   S
    return 0;
}
