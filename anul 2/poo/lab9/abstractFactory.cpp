#include <iostream>
#include <string>

// Abstract Product A: Engine
class Engine {
public:
    virtual std::string getType() const = 0;
};

// Concrete Product A1: CommercialEngine
class CommercialEngine : public Engine {
public:
    std::string getType() const override {
        return "Commercial Engine";
    }
};

// Concrete Product A2: MilitaryEngine
class MilitaryEngine : public Engine {
public:
    std::string getType() const override {
        return "Military Engine";
    }
};

// Abstract Product B: Wings
class Wings {
public:
    virtual std::string getType() const = 0;
};

// Concrete Product B1: CommercialWings
class CommercialWings : public Wings {
public:
    std::string getType() const override {
        return "Commercial Wings";
    }
};

// Concrete Product B2: MilitaryWings
class MilitaryWings : public Wings {
public:
    std::string getType() const override {
        return "Military Wings";
    }
};

// Abstract Factory: AircraftFactory
class AircraftFactory {
public:
    virtual Engine* createEngine() = 0;
    virtual Wings* createWings() = 0;
};

// Concrete Factory 1: CommercialAircraftFactory
class CommercialAircraftFactory : public AircraftFactory {
public:
    Engine* createEngine() override {
        return new CommercialEngine();
    }

    Wings* createWings() override {
        return new CommercialWings();
    }
};

// Concrete Factory 2: MilitaryAircraftFactory
class MilitaryAircraftFactory : public AircraftFactory {
public:
    Engine* createEngine() override {
        return new MilitaryEngine();
    }

    Wings* createWings() override {
        return new MilitaryWings();
    }
};

// Client Code
void buildAndDisplayAircraft(AircraftFactory& factory) {
    Engine* engine = factory.createEngine();
    Wings* wings = factory.createWings();

    std::cout << "Assembling an aircraft with " << engine->getType() << " and " << wings->getType() << ".\n";

}

int main() {
    // Client uses Commercial Aircraft Factory
    CommercialAircraftFactory commercialFactory;
    buildAndDisplayAircraft(commercialFactory);

    // Client uses Military Aircraft Factory
    MilitaryAircraftFactory militaryFactory;
    buildAndDisplayAircraft(militaryFactory);

    return 0;
}
/*Pros:

Izolează detaliile concrete ale obiectelor create, permitând schimbul facil al familiilor de obiecte.
Asigură consistența între obiectele create.
Cons:

Poate deveni complex în cazul adăugării unor noi tipuri de obiecte.
Necesită crearea unor interfețe și clase suplimentare.
*/