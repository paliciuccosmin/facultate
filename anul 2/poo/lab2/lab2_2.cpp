#include<iostream>

using namespace std;

class Car{
public:
string manufacture;
int year;
int engineSize;
Car(string m,int y,int e);
Car(int e,string manufacture);
Car(string m,int y);

};
Car::Car(string m,int y,int e)
{
    manufacture=m;
    year=y;
    engineSize=e;
}
Car::Car(int e, string manufacture){};

int main()
{

}