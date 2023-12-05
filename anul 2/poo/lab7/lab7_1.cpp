#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
    void concat(T a, T b)
        {   
            char cat[2];
            strcpy(cat, a);
            strcat(cat, b);
            cout<<cat;
        }
template<>
    void concat(int a, int b)
    {
        string c=to_string(a);
        string d=to_string(b);
        string result=c+d;
        cout<<stoi(result);
    }

int main(){
    concat(10,20);
    cout<<endl;
    concat("a","b");
}