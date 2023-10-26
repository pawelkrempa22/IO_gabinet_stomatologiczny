#include <iostream>
#include <vector>
#include <string>

class Wizyta {
public:
    std::string data;
    std::string godzina;
    std::string pacjent;

    Wizyta(std::string d, std::string g, std::string p) : data(d), godzina(g), pacjent(p) {}
};

class Harmonogram {
private:
    std::vector<Wizyta> wizyty;

public:
    void DodajWizyte(std::string data, std::string godzina, std::string pacjent) {
        Wizyta wizyta(data, godzina, pacjent);
        wizyty.push_back(wizyta);
    }

    void WyswietlHarmonogram() {
        std::cout << "Harmonogram Wizyt:\n";
        for (const auto& wizyta : wizyty) {
            std::cout << "Data: " << wizyta.data << ", Godzina: " << wizyta.godzina << ", Pacjent: " << wizyta.pacjent << "\n";
        }
    }

    void WyszukajWizytyDlaPacjenta(std::string pacjent) {
        std::cout << "Wizyty dla pacjenta " << pacjent << ":\n";
        for (const auto& wizyta : wizyty) {
            if (wizyta.pacjent == pacjent) {
                std::cout << "Data: " << wizyta.data << ", Godzina: " << wizyta.godzina << "\n";
            }
        }
    }
};

int main() {
    Harmonogram harmonogram;

   

   

    return 0;
}