#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void zarejestrujUzytkownika(const string& nazwaPliku) {
    cout << "Podaj nazwe uzytkownika: ";
    string nazwaUzytkownika;
    cin >> nazwaUzytkownika;

    cout << "Podaj haslo: ";
    string haslo;
    cin >> haslo;

    // zapis
    ofstream plik(nazwaPliku, ios::app);
    if (plik.is_open()) {
        plik << nazwaUzytkownika << " " << haslo << endl;
        cout << "Rejestracja zakonczona sukcesem" << endl;
        plik.close();
    } else {
        cout << "Blad podczas otwierania pliku." << endl;
    }
}

bool zaloguj(const string& nazwaPliku) {
    cout << "Podaj nazwe uzytkownika: ";
    string nazwaUzytkownika;
    cin >> nazwaUzytkownika;

    cout << "Podaj haslo: ";
    string haslo;
    cin >> haslo;

    // sprawdzenie danych 
    ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        string linia;
        while (getline(plik, linia)) {
            size_t pozycjaSpacji = linia.find(' ');
            string uzytkownik = linia.substr(0, pozycjaSpacji);
            string hasloZapisane = linia.substr(pozycjaSpacji + 1);

            if (uzytkownik == nazwaUzytkownika && hasloZapisane == haslo) {
                cout << "Logowanie udane" << endl;
                plik.close();
                return true;
            }
        }
        cout << "Bledne dane logowania." << endl;
        plik.close();
    } else {
        cout << "Blad podczas otwierania pliku." << endl;
    }

    return false;
}

int main() {
    const string nazwaPliku = "baza_uzytkownikow.txt";

    cout << "Wybierz opcje:" << endl;
    cout << "1. Zarejestruj sie" << endl;
    cout << "2. Zaloguj sie" << endl;

    int opcja;
    cin >> opcja;

    switch (opcja) {
        case 1:
            zarejestrujUzytkownika(nazwaPliku);
            break;
        case 2:
            if (zaloguj(nazwaPliku)) {
                // Tutaj jesli jest to stomatolog to ma dostep do bazy i harmonogramu wizyt, a jesli 
                //jest to klient to moze korzystac z opcji zarzadzania swoja wizyta
            }
            break;
        default:
            cout << "Nieprawidlowa opcja." << endl;
            break;
    }

    return 0;
}