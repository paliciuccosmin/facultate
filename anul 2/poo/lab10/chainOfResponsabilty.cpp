#include <iostream>
#include <string>

class Handler {
public:
    virtual void setNext(Handler* handler) = 0;
    virtual void handleRequest(const std::string& request) = 0;
};

class ConcreteHandlerA : public Handler {
private:
    Handler* nextHandler;

public:
    void setNext(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handles the request." << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler can handle the request." << std::endl;
        }
    }
};

class ConcreteHandlerB : public Handler {
private:
    Handler* nextHandler;

public:
    void setNext(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handles the request." << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler can handle the request." << std::endl;
        }
    }
};

class ConcreteHandlerC : public Handler {
private:
    Handler* nextHandler;

public:
    void setNext(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == "C") {
            std::cout << "ConcreteHandlerC handles the request." << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler can handle the request." << std::endl;
        }
    }
};

int main() {
    Handler* handlerA = new ConcreteHandlerA();
    Handler* handlerB = new ConcreteHandlerB();
    Handler* handlerC = new ConcreteHandlerC();

    handlerA->setNext(handlerB);
    handlerB->setNext(handlerC);

    handlerA->handleRequest("A");
    handlerA->handleRequest("B");
    handlerA->handleRequest("C");
    handlerA->handleRequest("D");
    return 0;
}
