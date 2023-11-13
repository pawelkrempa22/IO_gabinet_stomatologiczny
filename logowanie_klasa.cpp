#include <iostream>
#include <fstream>
#include <string>

class Uzytkownik {
public:
    Uzytkownik(const std::string& nazwaPliku) : nazwaPliku(nazwaPliku) {}

    void zarejestruj() {
        std::cout << "Podaj nazwe uzytkownika: ";
        std::cin >> nazwaUzytkownika;

        std::cout << "Podaj haslo: ";
        std::cin >> haslo;

        std::ofstream plik(nazwaPliku, std::ios::app);
        if (plik.is_open()) {
            plik << nazwaUzytkownika << " " << haslo << std::endl;
            std::cout << "Rejestracja zakonczona sukcesem" << std::endl;
            plik.close();
        } else {
            std::cout << "Blad podczas otwierania pliku." << std::endl;
        }
    }

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
    std::string nazwaPliku;
};

int main() {
    const std::string nazwaPliku = "baza_uzytkownikow.txt";

    std::cout << "Wybierz opcje:" << std::endl;
    std::cout << "1. Zarejestruj sie" << std::endl;
    std::cout << "2. Zaloguj sie" << std::endl;

    int opcja;
    std::cin >> opcja;

    Uzytkownik uzytkownik(nazwaPliku);

    switch (opcja) {
        case 1:
            uzytkownik.zarejestruj();
            break;
        case 2:
            if (uzytkownik.zaloguj()) {
                // uzytkownik moze zarzadzac wizyta, jesli uzytkownikiem jest stomatolog to ma dostep do grafiku
            }
            break;
        default:
            std::cout << "Nieprawidlowa opcja." << std::endl;
            break;
    }

    return 0;
}