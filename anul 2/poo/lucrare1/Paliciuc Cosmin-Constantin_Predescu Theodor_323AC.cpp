#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class CsvAdapter {
protected:
    vector<vector<int>> studentData;

    bool readStudentData(const string& line) {
        istringstream ss(line);
        string token;
        vector<int> studentAttributes;

        while (getline(ss, token, ',')) {
            studentAttributes.push_back(stoi(token));
        }

        studentData.push_back(studentAttributes);
        return true;
    }
};

class Student : public CsvAdapter {
public:
    bool readFromCSV(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return false;
        }

        string line;
        if (getline(file, line)) {
            getline(file, line); // Read headers

            while (getline(file, line)) {
                readStudentData(line);
            }

            file.close();
            return true;
        } else {
            cerr << "Error reading file: " << filename << endl;
            file.close();
            return false;
        }
    }

    double getAvgSleepQuality() const {
        return calculateAverage(2); // Assuming sleep quality is at index 1
    }

    double getAvgNrHeadaches() const {
        return calculateAverage(3); // Assuming number of headaches is at index 2
    }

    double getAvgAcademicPerformance() const {
        return calculateAverage(4); // Assuming academic performance is at index 3
    }

    double getAvgStudyLoad() const {
        return calculateAverage(5); // Assuming study load is at index 4
    }

    double getAvgExtracurricularActivities() const {
        return calculateAverage(6); // Assuming extracurricular activities is at index 5
    }

    double getAvgStressLevels() const {
        return calculateAverage(7); // Assuming stress levels is at index 6
    }

    vector<int> getBreakdownSleepQuality() const {
        return calculateBreakdown(1);
    }

    vector<int> getBreakdownNrHeadaches() const {
        return calculateBreakdown(2);
    }

    vector<int> getBreakdownAcademicPerformance() const {
        return calculateBreakdown(3);
    }

    vector<int> getBreakdownStudyLoad() const {
        return calculateBreakdown(4);
    }

    vector<int> getBreakdownExtracurricularActivities() const {
        return calculateBreakdown(5);
    }

    vector<int> getBreakdownStressLevels() const {
        return calculateBreakdown(6);
    }

private:
    double calculateAverage(int attributeIndex) const {
        if (studentData.empty()) {
            cerr << "No student data available." << endl;
            return 0.0;
        }

        double totalValue = 0.0;
        for (const auto& studentAttributes : studentData) {
            totalValue += studentAttributes[attributeIndex - 1];
        }

        return totalValue / studentData.size();
    }

    vector<int> calculateBreakdown(int attributeIndex) const {
        vector<int> breakdown(5, 0);

        for (const auto& studentAttributes : studentData) {
            int value = studentAttributes[attributeIndex - 1];
            if (value >= 1 && value <= 5) {
                breakdown[value - 1]++;
            }
        }

        return breakdown;
    }
};

class Professor {
public:
    // Method to generate a report and export it to a text file
    void generateReport(const Student& student, const string& fileName) const {
        ofstream reportFile(fileName);
        if (!reportFile.is_open()) {
            cerr << "Error opening report file: " << fileName << endl;
            return;
        }

        // Generate report content
        reportFile << "Student Report" << endl;
        reportFile << "-----------------------" << endl;

        // Include student information
        reportFile << "Average Sleep Quality: " << student.getAvgSleepQuality() << endl;
        reportFile << "Average Number of Headaches: " << student.getAvgNrHeadaches() << endl;
        reportFile << "Average Academic Performance: " << student.getAvgAcademicPerformance() << endl;
        reportFile << "Average Study Load: " << student.getAvgStudyLoad() << endl;
        reportFile << "Average Extracurricular Activities: " << student.getAvgExtracurricularActivities() << endl;
        reportFile << "Average Stress Levels: " << student.getAvgStressLevels() << endl;

        // Include date and time of report generation in UTC format
        time_t currentTime = time(nullptr);
        tm* utcTime = gmtime(&currentTime);
        reportFile << "Report generated on: " << put_time(utcTime, "%Y-%m-%d %H:%M:%S UTC") << endl;

        // Include stress reduction recommendations
        reportFile << "-----------------------" << endl;
        reportFile << "Stress Reduction Recommendations:" << endl;
        reportFile << "1. Consider incorporating mindfulness or relaxation techniques into your daily routine." << endl;
        reportFile << "2. Plan and organize your study schedule to avoid last-minute stress." << endl;
        reportFile << "3. Ensure you are getting enough quality sleep to support overall well-being." << endl;

        reportFile.close();
        cout << "Report generated successfully and saved to: " << fileName << endl;
    }
};

int main() {
    Student student;

    // Replace "your_file.csv" with the actual file name
    if (student.readFromCSV("data.csv")) {
        cout << "Average Sleep Quality: " << student.getAvgSleepQuality() << endl;
        cout << "Average Number of Headaches: " << student.getAvgNrHeadaches() << endl;
        cout << "Average Academic Performance: " << student.getAvgAcademicPerformance() << endl;
        cout << "Average Study Load: " << student.getAvgStudyLoad() << endl;
        cout << "Average Extracurricular Activities: " << student.getAvgExtracurricularActivities() << endl;
        cout << "Average Stress Levels: " << student.getAvgStressLevels() << endl;

        // Print breakdowns
        vector<int> breakdownSleepQuality = student.getBreakdownSleepQuality();
        cout << "Breakdown Sleep Quality: ";
        for (int i : breakdownSleepQuality) {
            cout << i << " ";
        }
        cout << endl;

        vector<int> breakdownNrHeadaches = student.getBreakdownNrHeadaches();
        cout << "Breakdown Number of Headaches: ";
        for (int i : breakdownNrHeadaches) {
            cout << i << " ";
        }
        cout << endl;

        vector<int> breakdownAcademicPerformance = student.getBreakdownAcademicPerformance();
        cout << "Breakdown Academic Performance: ";
        for (int i : breakdownAcademicPerformance) {
            cout << i << " ";
        }
        cout << endl;

        vector<int> breakdownStudyLoad = student.getBreakdownStudyLoad();
        cout << "Breakdown Study Load: ";
        for (int i : breakdownStudyLoad) {
            cout << i << " ";
        }
        cout << endl;

        vector<int> breakdownExtracurricularActivities = student.getBreakdownExtracurricularActivities();
        cout << "Breakdown Extracurricular Activities: ";
        for (int i : breakdownExtracurricularActivities) {
            cout << i << " ";
        }
        cout << endl;

        vector<int> breakdownStressLevels = student.getBreakdownStressLevels();
        cout << "Breakdown Stress Levels: ";
        for (int i : breakdownStressLevels) {
            cout << i << " ";
        }
        cout << endl;
    }
    Professor professor;
    professor.generateReport(student, "report.txt");

    return 0;
}
