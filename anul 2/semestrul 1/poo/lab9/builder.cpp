#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Salad {
public:
    void addIngredient(const string& ingredient) {
        ingredients.push_back(ingredient);
    }

    void display() const {
        cout << "Salad Ingredients:\n";
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient << "\n";
        }
    }

private:
    vector<string> ingredients;
};


class SaladBuilder {
public:
    virtual void buildBase() = 0;
    virtual void buildVegetables() = 0;
    virtual void buildProtein() = 0;
    virtual Salad getResult() const = 0;
};

class GreekSaladBuilder : public SaladBuilder {
public:
    void buildBase() override {
        salad.addIngredient("Lettuce");
    }

    void buildVegetables() override {
        salad.addIngredient("Tomatoes");
        salad.addIngredient("Cucumbers");
        salad.addIngredient("Red onions");
        salad.addIngredient("Kalamata olives");
    }

    void buildProtein() override {
        salad.addIngredient("Feta cheese");
    }

    Salad getResult() const override {
        return salad;
    }
private:
    Salad salad;
};

class CaesarSaladBuilder : public SaladBuilder {
public:
    void buildBase() override {
        salad.addIngredient("Romaine lettuce");
    }

    void buildVegetables() override {
        salad.addIngredient("Cherry tomatoes");
    }

    void buildProtein() override {
        salad.addIngredient("Grilled chicken");
    }

    Salad getResult() const override {
        return salad;
    }

private:
    Salad salad;
};


class SaladDirector {
public:
    Salad makeSalad(SaladBuilder& builder) {
        builder.buildBase();
        builder.buildVegetables();
        builder.buildProtein();
        return builder.getResult();
    }
};

int main() {
    SaladDirector director;
    GreekSaladBuilder greekSaladBuilder;
    Salad greekSalad = director.makeSalad(greekSaladBuilder);

    CaesarSaladBuilder caesarSaladBuilder;
    Salad caesarSalad = director.makeSalad(caesarSaladBuilder);

    cout << "Greek Salad:\n";
    greekSalad.display();

    cout << "\nCaesar Salad:\n";
    caesarSalad.display();
    return 0;
}

/*Pros:

Permite construirea de obiecte complexe pas cu pas.
Util în cazul obiectelor cu mulți parametri.
Cons:

Crește complexitatea codului din cauza necesității clasei Builder suplimentare.
Nu se pot asigura la nivel de compilare că toți parametrii necesari au fost furnizați.*/