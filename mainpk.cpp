#include <iostream>
#include "funkcje.h"
#include <math.h>

int main() {
	float tab[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	std::cout << "logarytm naturalny liczby 5.0 wynosi: " << log_nat(5.0) << std::endl;
	std::cout << "odchylenie standardowe tablicy 5 elementow (tab) wynosi: " << odchylenie_std(tab)<<std::endl;
	std::cout << "exponent liczby 5.0 wynosi " << exponent(5.0)<<std::endl;
	std::cout << "logarytm liczby 5.0 z 10 wynosi " << logarytm_z_10(5.0) << std::endl;
	//log z 10 dopisac w domu
	return 0;
}
