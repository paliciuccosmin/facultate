#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Money {
private:
    int amount;
    static int count_higher_than_50;

public:
    Money() {
        amount = rand() % 101;
    }

    void count() {
        Money::count_higher_than_50++;
    }

    int getAmount() {
        return amount;
    }

    static int getCountHigherThan50() {
        return count_higher_than_50;
    }
};

int Money::count_higher_than_50 = 0;

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    Money objects[5];

    for (int i = 0; i < 5; i++) {
        if (objects[i].getAmount() > 50) {
            objects[i].count();
        }
    }

    cout << "Number of objects with amount greater than 50: " << Money::getCountHigherThan50() << std::endl;

    return 0;
}
