#include <iostream>

// Subsystem classes
class SubsystemA {
public:
    void operationA() {
        std::cout << "Subsystem A operation" << std::endl;
    }
};

class SubsystemB {
public:
    void operationB() {
        std::cout << "Subsystem B operation" << std::endl;
    }
};

class SubsystemC {
public:
    void operationC() {
        std::cout << "Subsystem C operation" << std::endl;
    }
};

// Facade class
class Facade {
private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
    SubsystemC subsystemC;

public:
    void complexOperation() {
        subsystemA.operationA();
        subsystemB.operationB();
        subsystemC.operationC();
    }
};

int main() {
    Facade facade;
    facade.complexOperation();

    return 0;
}
