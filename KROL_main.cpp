#include <iostream>
#include "funkcje.h"
using namespace std;

int main() {
    double x = 4.0;
    double arr[] = { 2.0, 4.0, 5.0, 6.0, 7.0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Logarytm naturalny z " << x << " wynosi: " << Funkcje::logarytmNaturalny(x) << endl;
    cout << "Odchylenie standardowe wynosi: " << Funkcje::odchylenieStandardowe(arr, n) << endl;
    cout << "Wartosc exponentu dla " << x << " wynosi: " << Funkcje::wartoscExponentu(x) << endl;

    //znajdz najwieksza wartosc tablicy
    double maxVal = Funkcje::maxValue(arr, n);
    cout << "Maksymalna wartosc w tablicy wynosi: " << maxVal << endl;

    return 0;
}