#include <iostream>


int main() {
	int AA [10];
	int liczba;
	int ujemne = 0;
	int i = 0;
	while (i < 10) {
		std::cin >> liczba;
		if (liczba < 0) {
			ujemne++;
		}
		AA[i] = liczba;
		i++;
	}
	int BB[] = new int;


	return 0;
}