#include <iostream>
#include <vector>
#include <algorithm>
// Observer interface
class Observer {
public:
    virtual void update() = 0;
};

// Concrete Observer
class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "ConcreteObserver: Received an update." << std::endl;
    }
};

// Subject interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        // Find and remove the observer
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() override {
        // Notify all observers
        for (auto observer : observers) {
            observer->update();
        }
    }
};

int main() {
    // Create subject and observers
    ConcreteSubject subject;
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    // Attach observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Notify observers
    subject.notify();

    // Detach observer1 from the subject
    subject.detach(&observer1);

    // Notify observers again
    subject.notify();

    return 0;
}
