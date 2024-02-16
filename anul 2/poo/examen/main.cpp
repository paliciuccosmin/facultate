#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    Product(double price, const std::string& color, const std::string& size, const std::string& type)
        : price(price), color(color), size(size), type(type) {}

    virtual void displayDetails() const = 0;
    std::string getType() const {
        return type;
    }
    int getPrice() const {
        return price;
    }
    std::string getColor() const {
        return color;
    }
    std::string getSize() const {
        return size;
    }

protected:
    double price;
    std::string color;
    std::string size;
    std::string type;
};

class SkiEquipment : public Product {
public:
    SkiEquipment(double price, const std::string& color, const std::string& size, const std::string& type)
        : Product(price, color, size, type) {}

    void displayDetails() const override {
        std::cout << "Ski Equipment - Price: " << price << ", Color: " << color << ", Size: " << size << ", Type: " << type << std::endl;
    }
};

class SnowboardEquipment : public Product {
public:
    SnowboardEquipment(double price, const std::string& color, const std::string& size, const std::string& type)
        : Product(price, color, size, type) {}

    void displayDetails() const override {
        std::cout << "Snowboard Equipment - Price: " << price << ", Color: " << color << ", Size: " << size << ", Type: " << type << std::endl;
    }
};

class ProtectionProduct : public Product {
public:
    ProtectionProduct(double price, const std::string& color, const std::string& size, const std::string& type)
        : Product(price, color, size, type) {}

    void displayDetails() const override {
        std::cout << "Protection Product - Price: " << price << ", Color: " << color << ", Size: " << size << ", Type: " << type << std::endl;
    }
};

class Catalog {
private:
    std::vector<Product*> products;

public:
    void addProduct(Product* product) {
        products.push_back(product);
    }

    void displayCatalog() const {
        for (const auto& product : products) {
            product->displayDetails();
        }
    }

    void recommendEquipment(int height, int weight) const {
        for (const auto& product : products) {
            if (product->getType() == "equipment") {
                if (height > 140 && height < 160 && weight > 40 && weight < 60) {
                    product->displayDetails();
                }
                if (height > 160 && height < 180 && weight > 60 && weight < 80) {
                    product->displayDetails();
                }
                if (height > 180 && height < 200 && weight > 80 && weight < 100) {
                    product->displayDetails();
                }
                if (height > 200 && weight > 100) {
                    product->displayDetails();
                }
            }
        }
    }

    void recommendSki(int height) const {
        for (const auto& product : products) {
            if (product->getType() == "ski") {
                if (height > 140 && height < 160) {
                    product->displayDetails();
                }
                if (height > 160 && height < 180) {
                    product->displayDetails();
                }
                if (height > 180 && height < 200) {
                    product->displayDetails();
                }
                if (height > 200) {
                    product->displayDetails();
                }
            }
        }
    }

    void recommendSnowboard(int height) const {
        for (const auto& product : products) {
            if (product->getType() == "snowboard") {
                if (height > 140 && height < 160) {
                    product->displayDetails();
                }
                if (height > 160 && height < 180) {
                    product->displayDetails();
                }
                if (height > 180 && height < 200) {
                    product->displayDetails();
                }
                if (height > 200) {
                    product->displayDetails();
                }
            }
        }
    }
};

class Cart {
private:
    std::vector<Product*> products;

public:
    void addProduct(Product* product) {
        products.push_back(product);
    }
    void displayCart() const {
        for (const auto& product : products) {
            product->displayDetails();
        }
    }
    void deleteProduct(Product* product) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if ((*it)->getType() == product->getType() && (*it)->getSize() == product->getSize()) {
                products.erase(it);
                break;
            }
        }
    }
    void displayTotal() const {
        double total = 0;
        for (const auto& product : products) {
            total += product->getPrice();
        }
        std::cout << "Total: " << total << std::endl;
    }
    void displayTotalWithDiscount() const {
        double total = 0;
        for (const auto& product : products) {
            total += product->getPrice();
        }
        if (total < 1000) {
            total = total - total * 0.1;
        }
        if (total > 1000 && total < 2000) {
            total = total - total * 0.15;
        }
        if (total > 2000) {
            total = total - total * 0.2;
        }
        std::cout << "Total: " << total << std::endl;
    }
};

void meniuRecommend() {}

void meniu(Catalog& catalog) {
    while (true) {
        std::cout << "1. Display catalog" << std::endl;
        std::cout << "2. Recommend equipment" << std::endl;
        std::cout << "3. Recommend Ski" << std::endl;
        std::cout << "4. Recommend Snowboard" << std::endl;
        std::cout << "5. Exit" << std::endl;
        int option;
        std::cin >> option;
        if (option == 1) {
            catalog.displayCatalog();
        }
        if(option==2){
            int height,weight,answer;
            std::cout<<"Height: ";
            std::cin>>height;
            std::cout<<"Weight: ";
            std::cin>>weight;
            std::cout<<"What type of product do you want?"<<endl;
            std::cout<<"1.Equipement"<<endl;
            std::cout<<"2.Ski"<<endl;
            std::cout<<"3.Snowboard"<<endl;
            cin>>answer;
            if(answer==1)
                catalog.recommendEquipment(weight,height);
            if(answer==2)
                catalog.recommendSki(height);
            if(answer==3)
                catalog.recommendSnowboard(height);
        }
    }
}

int main() {
    Catalog catalog;

    catalog.addProduct(new SkiEquipment(200.0, "Red", "M", "ski"));
    catalog.addProduct(new SnowboardEquipment(250.0, "Blue", "L", "snowboard"));
    catalog.addProduct(new ProtectionProduct(30.0, "Black", "S", "protection"));

    meniu(catalog);

    // Eliberarea resurselor

    return 0;
}
