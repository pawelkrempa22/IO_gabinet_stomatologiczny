#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include "C:\Users\48729\Desktop\logowanie\logowanie\logowanie.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestyLogowanie
{
    TEST_CLASS(TestyFunkcji)
    {
    public:
        const std::string nazwaPlikuTestowego = "testowa_baza_uzytkownikow.txt";

        TEST_METHOD(ZarejestrujUzytkownikaTest)
        {
            // Symulacja wejścia od uzytkownika
            std::istringstream input("NowyUzytkownik\nNoweHaslo\n");
            std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

            // Wywolanie funkcji
            zarejestrujUzytkownika(nazwaPlikuTestowego);

            // przywrocenie oryginalnego cin
            std::cin.rdbuf(oldCin);

            // check czy plik zapisany
            std::ifstream plik(nazwaPlikuTestowego);
            std::string linia;
            getline(plik, linia);
            plik.close();

            Assert::AreEqual("NowyUzytkownik NoweHaslo", linia.c_str());
        }

        TEST_METHOD(ZalogujTest)
        {
            // Przygotowanie pliku testowego
            std::ofstream testowyPlik(nazwaPlikuTestowego);
            testowyPlik << "NowyUzytkownik NoweHaslo" << std::endl;
            testowyPlik.close();

            // Symulacja wejscia od uzytkownika
            std::istringstream input("NowyUzytkownik\nNoweHaslo\n");
            std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

            // Wywolanie funkcji
            bool rezultat = zaloguj(nazwaPlikuTestowego);

            // przywrocenie oryginalnego cin
            std::cin.rdbuf(oldCin);

            // sprawdzenie czy zalogowano
            Assert::IsTrue(rezultat);
        }
    };
}
