#include <iostream>
#include <math.h>
using namespace std;

class Volume{
    private:
    int dimensions;
    public:
    void volume(){
        this->dimensions = 0;
        cout<<"Obiectul are "<<dimensions<<" dimensiuni"<<endl;
    }
    void volume(int l){
        cout<<"Volumul cubului este "<<pow(l,3)<<endl;
    }
    void volume(string r){
        int R=stoi(r);
        cout<<"Volumul sferei este "<<(4*M_PI*pow(R,3))/3<<endl;
    }
    void volume(int l,int h){
        cout<<"Volumul piramidei este "<<(l*l*h)/2;
    }
};

int main()
{
    Volume cub,sfera,piramida,inexistent;
    inexistent.volume();
    cub.volume(3);
    sfera.volume("7");
    piramida.volume(3,6);
}