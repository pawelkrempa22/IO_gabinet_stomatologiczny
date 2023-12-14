
#include <iostream>
#include <math.h>
#include "funkcje.h"


double log_nat(double n) {
	return log(n);
}
float odchylenie_std(float arr[]) {
    float sum = 0.0, mean, odchylenie = 0.0;
    int i;

    for (i = 0; i < 5; ++i) {
        sum += arr[i];
    }

    mean = sum / 5;

    for (i = 0; i < 5; ++i) {
        odchylenie += pow(arr[i] - mean, 2);
    }

    return sqrt(odchylenie / 5);
}
double exponent(double a) {
    return exp(a);
}
double logarytm_z_10(double a) {
    return log10(a);
}

