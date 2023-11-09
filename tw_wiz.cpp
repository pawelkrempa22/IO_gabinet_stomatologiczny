#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

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
  std::srand(std::time(NULL));

  std::vector<std::vector<int>> wizyty;

  int id = 0;
  int dzien = 1;
  int miesiac = 11;
  int godzina = 8;
  while (dzien < 31) {
    id = std::rand() % 10;
    std::vector<int> innerVec;
    innerVec.push_back(id);
    innerVec.push_back(dzien);
    innerVec.push_back(miesiac);
    innerVec.push_back(godzina);
    godzina++;
    if (godzina > 16) {
      dzien++;
      godzina = 8;
    }
    wizyty.push_back(innerVec);
  }
  write2DVectorToFile(wizyty, "wizyty.txt");

  return 0;
}
