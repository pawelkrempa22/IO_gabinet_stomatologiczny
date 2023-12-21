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

    void WyswietlHarmonogram() const {
        std::cout << "Harmonogram Wizyt:\n";
        for (const auto& wizyta : wizyty) {
            std::cout << "Data: " << wizyta.data << ", Godzina: " << wizyta.godzina << ", Pacjent: " << wizyta.pacjent << "\n";
        }
    }

    void WyszukajWizytyDlaPacjenta(std::string pacjent) const {
        std::cout << "Wizyty dla pacjenta " << pacjent << ":\n";
        for (const auto& wizyta : wizyty) {
            if (wizyta.pacjent == pacjent) {
                std::cout << "Data: " << wizyta.data << ", Godzina: " << wizyta.godzina << "\n";
            }
        }
    }

    // Dodana publiczna metoda Wizyty()
    std::vector<Wizyta> Wizyty() const {
        return wizyty;
    }
};

int main() {
    Harmonogram harmonogram;

    // Tutaj można wywołać różne metody harmonogramu do testów

    return 0;
}