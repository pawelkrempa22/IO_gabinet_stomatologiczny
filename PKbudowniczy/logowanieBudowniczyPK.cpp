#include <iostream>
#include <fstream>
#include <string>

// Forward declaration
class Uzytkownik;

// Builder interface
class RejestracjaBuilder {
public:
    virtual void setNazwaUzytkownika() = 0;
    virtual void setHaslo() = 0;
    virtual void zapiszDoPliku() = 0;
    virtual Uzytkownik getResult() const = 0;
};

// Product class
class Uzytkownik {
public:
    friend class RejestracjaBuilderImpl;

    Uzytkownik() = default;

    bool zaloguj() {
        std::cout << "Podaj nazwe uzytkownika: ";
        std::cin >> nazwaUzytkownika;

        std::cout << "Podaj haslo: ";
        std::cin >> haslo;

        std::ifstream plik(nazwaPliku);
        if (plik.is_open()) {
            std::string linia;
            while (getline(plik, linia)) {
                size_t pozycjaSpacji = linia.find(' ');
                std::string uzytkownik = linia.substr(0, pozycjaSpacji);
                std::string hasloZapisane = linia.substr(pozycjaSpacji + 1);

                if (uzytkownik == nazwaUzytkownika && hasloZapisane == haslo) {
                    std::cout << "Logowanie udane" << std::endl;
                    plik.close();
                    return true;
                }
            }
            std::cout << "Bledne dane logowania." << std::endl;
            plik.close();
        } else {
            std::cout << "Blad podczas otwierania pliku." << std::endl;
        }

        return false;
    }

private:
    std::string nazwaUzytkownika;
    std::string haslo;
    std::string nazwaPliku = "baza_uzytkownikow.txt";
};

// Concrete builder for registration
class RejestracjaBuilderImpl : public RejestracjaBuilder {
public:
    RejestracjaBuilderImpl(const std::string& nazwaPliku) : nazwaPliku(nazwaPliku) {}

    void setNazwaUzytkownika() override {
        std::cout << "Podaj nazwe uzytkownika: ";
        std::cin >> uzytkownik.nazwaUzytkownika;
    }

    void setHaslo() override {
        std::cout << "Podaj haslo: ";
        std::cin >> uzytkownik.haslo;
    }

    void zapiszDoPliku() override {
        std::ofstream plik(nazwaPliku, std::ios::app);
        if (plik.is_open()) {
            plik << uzytkownik.nazwaUzytkownika << " " << uzytkownik.haslo << std::endl;
            std::cout << "Rejestracja zakonczona sukcesem" << std::endl;
            plik.close();
        } else {
            std::cout << "Blad podczas otwierania pliku." << std::endl;
        }
    }

    Uzytkownik getResult() const override {
        return uzytkownik;
    }

private:
    Uzytkownik uzytkownik;
    std::string nazwaPliku;
};

int main() {
    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1. Zarejestruj sie" << std::endl;
    std::cout << "2. Zaloguj sie" << std::endl;

    int opcja;
    std::cin >> opcja;

    switch (opcja) {
        case 1: {
            RejestracjaBuilderImpl rejestracjaBuilder("baza_uzytkownikow.txt");
            rejestracjaBuilder.setNazwaUzytkownika();
            rejestracjaBuilder.setHaslo();
            rejestracjaBuilder.zapiszDoPliku();
            Uzytkownik zarejestrowanyUzytkownik = rejestracjaBuilder.getResult();
            break;
        }
        case 2: {
            Uzytkownik uzytkownik;
            if (uzytkownik.zaloguj()) {
                // uzytkownik moze zarzadzac wizyta, jesli uzytkownikiem jest stomatolog to ma dostep do grafiku
            }
            break;
        }
        default:
            std::cout << "Nieprawidlowa opcja." << std::endl;
            break;
    }

    return 0;
}