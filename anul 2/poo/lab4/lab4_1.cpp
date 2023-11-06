#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Beer {
protected:
     string type;
     string origin;

public:
    Beer() : type("Default"), origin("Default") {}
    Beer( string beerType,  string beerOrigin) : type(beerType), origin(beerOrigin) {}

     string getType() const {
        return type;
    }

     string getOrigin() const {
        return origin;
    }
};

class BeerTypeA : private Beer {
private:
    int length;

public:
    BeerTypeA() : length(0) {}
    BeerTypeA( string beerType,  string beerOrigin, int labelLength) : Beer(beerType, beerOrigin), length(labelLength) {}

    float getLabelArea() {
        return length * length;
    }

    void displayInfo() {
         cout << "Type: " << getType() << ", Origin: " << getOrigin() << ", Label Area: " << getLabelArea() <<  endl;
    }
};

class BeerTypeB : private Beer {
private:
    int radius;

public:
    BeerTypeB() : radius(0) {}
    BeerTypeB( string beerType,  string beerOrigin, int labelRadius) : Beer(beerType, beerOrigin), radius(labelRadius) {}

    float getLabelArea() {
        return M_PI * radius * radius;
    }

    void displayInfo() {
         cout << "Type: " << getType() << ", Origin: " << getOrigin() << ", Label Area: " << getLabelArea() <<  endl;
    }
};

class BeerTypeC : private Beer {
private:
    int base;
    int height;

public:
    BeerTypeC() : base(0), height(0) {}
    BeerTypeC( string beerType,  string beerOrigin, int labelBase, int labelHeight) : Beer(beerType, beerOrigin), base(labelBase), height(labelHeight) {}

    float getLabelArea() {
        return (base * height)/2;
    }

    void displayInfo() {
         cout << "Type: " << getType() << ", Origin: " << getOrigin() << ", Label Area: " << getLabelArea() <<  endl;
    }
};

int main() {
    BeerTypeA beerA("Type A", "Origin A", 5);
    beerA.displayInfo();

    BeerTypeB beerB("Type B", "Origin B", 4);
    beerB.displayInfo();

    BeerTypeC beerC("Type C", "Origin C", 6, 3);
    beerC.displayInfo();

    return 0;
}
