#include <iostream>
using namespace std;
int main() {
  
    for (int liczba = 300; liczba <= 1200;liczba++) {
        if (liczba % 2 == 1) {
            cout << liczba << " ";
        }
      else  if (liczba % 400 == 0) {
            cout << "\n";
        }
        else if (liczba % 100 == 0) {
            cout << "*** ";
        }
    }

    return 0;
}