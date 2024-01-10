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

// Budowniczy - klasa abstrakcyjna
class WizytaBuilder {
public:
    virtual void UstawDate(std::string data) = 0;
    virtual void UstawGodzine(std::string godzina) = 0;
    virtual void UstawPacjenta(std::string pacjent) = 0;
    virtual Wizyta Zbuduj() = 0;
};

// Konkretny budowniczy dla wizyt
class StandardowyWizytaBuilder : public WizytaBuilder {
private:
    Wizyta wizyta;

public:
    void UstawDate(std::string data) override {
        wizyta.data = data;
    }

    void UstawGodzine(std::string godzina) override {
        wizyta.godzina = godzina;
    }

    void UstawPacjenta(std::string pacjent) override {
        wizyta.pacjent = pacjent;
    }

    Wizyta Zbuduj() override {
        return wizyta;
    }
};

class Harmonogram {
private:
    std::vector<Wizyta> wizyty;

public:
    void DodajWizyte(WizytaBuilder& builder) {
        wizyty.push_back(builder.Zbuduj());
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

    StandardowyWizytaBuilder wizytaBuilder;

    wizytaBuilder.UstawDate("2023-01-01");
    wizytaBuilder.UstawGodzine("10:00");
    wizytaBuilder.UstawPacjenta("Robert Kubek");
    harmonogram.DodajWizyte(wizytaBuilder);

    wizytaBuilder.UstawDate("2023-01-02");
    wizytaBuilder.UstawGodzine("14:30");
    wizytaBuilder.UstawPacjenta("Alicja Lyzka");
    harmonogram.DodajWizyte(wizytaBuilder);

    wizytaBuilder.UstawDate("2023-01-03");
    wizytaBuilder.UstawGodzine("11:45");
    wizytaBuilder.UstawPacjenta("Pawel Krempa");
    harmonogram.DodajWizyte(wizytaBuilder);

    harmonogram.WyswietlHarmonogram();

    harmonogram.WyszukajWizytyDlaPacjenta("Robert Kubek");

    return 0;
}