#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<sstream>
#include"sqlite3.h"
using namespace std;

class Trip{
    private:
        string destination, date;
        float price;
        float distance;
        unsigned reservationCount;
        sqlite3* transportDb;
    friend class Operator;
    
};
class Operator{
    private:

    bool checkDate(string d)
    {
         
        std::time_t currentTime = std::time(nullptr);
        std::tm* currentLocalTime = std::localtime(&currentTime);
        char currentDateString[11];
        std::strftime(currentDateString, sizeof(currentDateString), "%Y-%m-%d", currentLocalTime);
        int result = d.compare(currentDateString);
        if(result<0)
            return true;
        else 
            return false;
    }
    bool checkSpell()
    {
        return true;
    }

    void addTrip(string new_dest,string new_date,float price,float distance)
    {

    }
    void createTable() {
        const char* create_table_query = "CREATE TABLE IF NOT EXISTS trips ("
                                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                        "destination TEXT NOT NULL,"
                                        "start_date TEXT NOT NULL,"
                                        "end_date TEXT NOT NULL);";

        int rc = sqlite3_exec(db, create_table_query, 0, 0, 0);

        if (rc != SQLITE_OK) {
            std::cerr << "Failed to create table: " << sqlite3_errmsg(db) << std::endl;
            exit(1);
        }
    }
};



int main()
{

}