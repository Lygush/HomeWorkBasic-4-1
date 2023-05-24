#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city{};
    std::string street{};
    int house{};
    int apartment{};

public:

    Address() {}

    Address(std::string city, std::string street, int house, int apartment) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    std::string Out() {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment) + "\n";
    }
};

int main()
{
    std::fstream fIn("in.txt");
    if (!fIn) {
        std::cout << "Error! File is not open";
    }
    else { 
        int addressCount{}, house{}, apatment{};
        std::string city{}, street{};
        fIn >> addressCount;
        Address* addressMass = new Address[addressCount];
        for (int i{}; i < addressCount; ++i) {
            fIn >> city;
            fIn >> street;
            fIn >> house;
            fIn >> apatment;
            addressMass[i] = Address(city, street, house, apatment);
        }
        std::ofstream fOut("out.txt");
        for (int i{ addressCount - 1 }; i >= 0; --i) {
            fOut << addressMass[i].Out();
        }
        delete[] addressMass;
        fOut.close();
    }
    fIn.close();
}

