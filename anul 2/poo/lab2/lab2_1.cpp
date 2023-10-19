#include<iostream>
#include<ctime>

using namespace std;

class Timp {
    public:
    string time;
    Timp(string t){
        time=t;
    }
    ~Timp(){
        cout << "Object is being deleted" << endl;
    }
};

int main()
{   time_t now=time(0);
    string t=ctime(&now);
    Timp timp1(t);
    cout<<timp1.time;

}