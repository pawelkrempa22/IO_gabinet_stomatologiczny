#include "funkcje.h"
#include <cmath>

double Funkcje::logarytmNaturalny(double x) {
    return log(x);
}

double Funkcje::odchylenieStandardowe(double arr[], int n) {
    if (n <= 0) {
        return 0.0;
    }

    double sum = 0.0, mean, standardDeviation = 0.0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    mean = sum / n;

    for (int i = 0; i < n; ++i) {
        standardDeviation += pow(arr[i] - mean, 2);
    }

    return sqrt(standardDeviation / n);
}

double Funkcje::wartoscExponentu(double x) {
    return exp(x);
}

double Funkcje::maxValue(const double arr[], int n) {
    if (n <= 0) {
        return 0.0;
    }

    double maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return maxVal;
}