#include <iostream>
#include <string>

int main() {
  bool wybor = 0;

  std::cout << "(0) Umowienie wizyty\n";
  std::cout << "(1) Odwolanie wizyty\n";
  std::cin >> wybor;
  std::cout << "\n";

  if (!wybor) {
    std::string imie_pacjenta;
    std::string nazwisko_pacjenta;
    long pesel_pacjenta;

    std::cout << "Podaj Imie pacjenta\n";
    std::cin >> imie_pacjenta;
    std::cout << "\n";
    std::cout << "Podaj nazwisko pacjenta\n";
    std::cin >> nazwisko_pacjenta;

    bool popr_pesel = false;
    while (!popr_pesel) {
      std::cout << "\n";
      std::cout << "Podaj pesel pacjenta\n";
      std::cin >> pesel_pacjenta;
      if (pesel_pacjenta >= 1000000000 && pesel_pacjenta <= 9999999999) {
        popr_pesel = true;
      } else {
        std::cout << "Podano bledny pesel\n";
      }
    }
  } else {
    // Odwolanie wizyty
  }

  return 0;
}
