#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
// Component interface
class Component {
public:
    virtual void operation() = 0;
};

// Leaf class
class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite class
class Composite : public Component {
private:
    std::vector<Component*> components;

public:
    void add(Component* component) {
        components.push_back(component);
    }

    #include <algorithm>

    void remove(Component* component) {
        // Remove the component from the vector
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

    void operation() override {
        std::cout << "Composite operation" << std::endl;

        // Call operation on all child components
        for (Component* component : components) {
            component->operation();
        }
    }
};

int main() {
    // Create leaf components
    Leaf* leaf1 = new Leaf();
    Leaf* leaf2 = new Leaf();
    Leaf* leaf3 = new Leaf();

    // Create composite component
    Composite* composite = new Composite();

    // Add leaf components to the composite
    composite->add(leaf1);
    composite->add(leaf2);
    composite->add(leaf3);

    // Call operation on the composite
    composite->operation();
    return 0;
}
