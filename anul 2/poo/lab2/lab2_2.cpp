#include <iostream>
using namespace std;

class Car {
public:
  string manufacture;
  int year;
  int engineSize;
  string fuel;

  Car(string m, int y, int e, string f);
  Car(string m, int e, string f);
  Car(string m, string f);
  Car();
  ~Car() {
    cout << "Baza de date a fost stearsa" << endl;
  }
};

Car::Car(string m, int y, int e, string f) {
  manufacture = m;
  year = y;
  engineSize = e;
  fuel = f;
}

Car::Car(string m, int e, string f) {
  manufacture = m;
  year = 2023;
  engineSize = e;
  fuel = f;
}

Car::Car(string m, string f) {
  manufacture = m;
  year = 2023;
  engineSize = 0;
  fuel = f;
}

Car::Car() {
  manufacture = "Dacia";
  year = 2005;
  engineSize = 1500;
  fuel = "Diesel";
}

int main() {
  Car car1("Bmw", 2003, 2000, "Diesel");
  Car car2("Audi", 3000, "Diesel");
  Car car3("Tesla", "Electric");
  Car car4;
  cout << car1.manufacture << " " << car1.year << " " << car1.engineSize << " " << car1.fuel << endl;
  cout << car2.manufacture << " " << car2.year << " " << car2.engineSize << " " << car2.fuel << endl;
  cout << car3.manufacture << " " << car3.year << " " << car3.engineSize << " " << car3.fuel << endl;
  cout << car4.manufacture << " " << car4.year << " " << car4.engineSize << " " << car4.fuel << endl;
  return 0;
}
