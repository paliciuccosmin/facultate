#include<stdlib.h>
#include<iostream>

using namespace std;

class Student {

    public:
    string nume,prenume,grupa,pastrat,imbunatatiri,dezvoltarePersonala,dupaFacultate;
};

int main()
{
    Student student;
    student.nume ="Paliciuc";
    student.prenume ="Cosmin-Constantin";
    student.grupa ="323AC";
    student.pastrat ="Formatul laboratorului";
    student.imbunatatiri ="nimic";
    student.dezvoltarePersonala ="Cursuri de 3D modelling";
    student.dupaFacultate="Full stack";
    cout<<student.nume<<endl<<student.grupa<<endl<<student.pastrat<<endl<<student.imbunatatiri<<endl<<student.dezvoltarePersonala<<endl<<student.dupaFacultate;
}