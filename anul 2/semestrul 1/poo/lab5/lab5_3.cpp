#include <iostream>
#include <string>

using namespace std;

class ConcatenareString {
private:
    string primulString;
    string alDoileaString;

public:
    ConcatenareString(const string& primul, const string& alDoilea)
        : primulString(primul), alDoileaString(alDoilea) {}

    string operator-(const ConcatenareString& other) const {
        return primulString + " " + alDoileaString + " " + other.primulString+ " " + other.alDoileaString;
    }

    void afiseaza() const {
        cout << "Primul String: " << primulString << ", Al Doilea String: " << alDoileaString << endl;
    }
};

int main() {
    ConcatenareString obiect1("Buna", "ziua");
    ConcatenareString obiect2(",imi place", "POO");

    obiect1.afiseaza();
    obiect2.afiseaza();

    string rezultat = obiect1 - obiect2;
    cout << "Rezultat: " << rezultat << endl;

    return 0;
}
