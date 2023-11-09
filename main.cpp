#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool readDataFromFile(const std::string &filename,
                      std::vector<std::vector<int>> &data) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Failed to open the file." << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::vector<int> row;
    size_t start = 0;

    while (start < line.length()) {
      size_t end = line.find(' ', start);

      if (end == std::string::npos) {
        end = line.length();
      }

      std::string token = line.substr(start, end - start);
      int value = std::stoi(token); // Convert the token to an integer
      row.push_back(value);

      start = end + 1;
    }

    data.push_back(row);
  }

  file.close();
  return true;
}

void write2DVectorToFile(const std::vector<std::vector<int>> &data,
                         const std::string &filename) {
  // Create an output file stream
  std::ofstream outFile(filename);

  // Check if the file was opened successfully
  if (!outFile.is_open()) {
    std::cerr << "Error: Unable to open the file " << filename << std::endl;
    return;
  }

  // Iterate through the 2D vector and write its contents to the file
  for (const auto &row : data) {
    for (const int value : row) {
      outFile << value << " ";
    }
    outFile << "\n"; // Start a new line for the next row
  }

  // Close the file
  outFile.close();

  std::cout << "Data written to " << filename << " successfully." << std::endl;
}

int main() {
  int id_pacjenta = 1;
  bool wybor = 0;

  std::vector<std::vector<int>> wizyty;

  std::cout << "(0) Umowienie wizyty\n";
  std::cout << "(1) Odwolanie wizyty\n";
  std::cin >> wybor;
  std::cout << "\n";

  if (!wybor) {
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // UMAWIANIE WIZYTY
    if (readDataFromFile("wizyty.txt", wizyty)) {

      std::cout << "Wolne terminy wizyt\n";
      std::cout << "Dzien Miesiac Godzina ID Wizyty\n";
      for (int i = 0; i < wizyty.size(); i++) {
        if (wizyty[i][0] == 0) {
          for (int j = 1; j < 4; j++) {
            std::cout << wizyty[i][j] << "      ";
          }
          std::cout << i;
          std::cout << std::endl;
        }
      }
      int id_wizyty_do_umowienia;
      std::cin >> id_wizyty_do_umowienia;
      if (std::isnan(id_wizyty_do_umowienia) || id_wizyty_do_umowienia < 0 ||
          id_wizyty_do_umowienia > wizyty.size() ||
          wizyty[id_wizyty_do_umowienia][0] != 0) {
        std::cout << "Podano bledne id\n";
      } else {
        bool potwierdzenie = false;
        std::cout << "Czy jestes pewien(a)?:\n";
        std::cout << "(0)   (1)\n";
        std::cout << "Nie   Tak\n";
        std::cin >> potwierdzenie;
        if (potwierdzenie) {
          wizyty[id_wizyty_do_umowienia][0] = id_pacjenta;
          write2DVectorToFile(wizyty, "wizyty.txt");
          std::cout << "Wizyta pomyslnie umowiona\n";
        }
      }
    } else {
      std::cout << "Blad odzczytu bazy danych\n";
    }

  } else {
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ODWOLYWANIE WIZYTY
    //  wizyty sa w formacie (id pacjenta, dzien wizyty, miesiac wizyty,
    //  godzina wizyty)

    if (readDataFromFile("wizyty.txt", wizyty)) {

      std::cout << "Twoje wizyty\n";
      std::cout << "Dzien Miesiac Godzina ID Wizyty\n";
      for (int i = 0; i < wizyty.size(); i++) {
        if (wizyty[i][0] == id_pacjenta) {
          for (int j = 1; j < 4; j++) {
            std::cout << wizyty[i][j] << "      ";
          }
          std::cout << i;
          std::cout << std::endl;
        }
      }

      int id_wizyty_do_usuniecia;
      std::cout << "Podaj id wizyty do usuniecia\n";
      std::cin >> id_wizyty_do_usuniecia;
      if (std::isnan(id_wizyty_do_usuniecia) || id_wizyty_do_usuniecia < 0 ||
          id_wizyty_do_usuniecia > wizyty.size() ||
          wizyty[id_wizyty_do_usuniecia][0] != id_pacjenta) {
        std::cout << "podano bledne id\n";
      } else {
        bool potwierdzenie = false;
        std::cout << "Czy jestes pewien(a)?:\n";
        std::cout << "(0)   (1)\n";
        std::cout << "Nie   Tak\n";
        std::cin >> potwierdzenie;
        if (potwierdzenie) {
          wizyty[id_wizyty_do_usuniecia][0] = 0;
          write2DVectorToFile(wizyty, "wizyty.txt");
          std::cout << "Wizyta odwolana\n";
        }
      }
    }
  }

  return 0;
}
