#include<iostream>


class Dane_klienta {
public:
	std::string imie, nazwisko;
	unsigned int wiek;
	float dlugosc_wizyty;
	float h_start_pon, h_end_pon, h_start_wt, h_end_wt, h_start_sr, h_end_sr, h_start_czw, h_end_czw, h_start_pt, h_end_pt; //podaje swoje zakresy czasowe w danym dniu

	void wczytajDane() {
		std::cout << "Wprowad� imi�: ";
		std::cin >> imie;
		std::cout << "Wprowad� nazwisko: ";
		std::cin >> nazwisko;
		std::cout << "Wprowad� wiek: ";
		std::cin >> wiek;
		std::cout << "Wprowad� d�ugo�� wizyty: ";
		std::cin >> dlugosc_wizyty;
		std::cout << "Wprowad� od kt�rej godziny mo�esz mie� wizyt� w poniedzia�ek: ";
		std::cin >> h_start_pon;
		std::cout << "Wprowad� do kt�rej godziny mo�esz mie� wizyt� w poniedzia�ek: ";
		std::cin >> h_end_pon;
		std::cout << "Wprowad� od kt�rej godziny mo�esz mie� wizyt� we wtorek: ";
		std::cin >> h_start_wt;
		std::cout << "Wprowad� do kt�rej godziny mo�esz mie� wizyt� we wtorek: ";
		std::cin >> h_end_wt;
		std::cout << "Wprowad� od kt�rej godziny mo�esz mie� wizyt� w �rod�: ";
		std::cin >> h_start_sr;
		std::cout << "Wprowad� do kt�rej godziny mo�esz mie� wizyt� w �rod�: ";
		std::cin >> h_end_sr;
		std::cout << "Wprowad� od kt�rej godziny mo�esz mie� wizyt� we czwartek: ";
		std::cin >> h_start_pt;
		std::cout << "Wprowad� do kt�rej godziny mo�esz mie� wizyt� we czwartek: ";
		std::cin >> h_end_pt;
		std::cout << "Wprowad� od kt�rej godziny mo�esz mie� wizyt� w pi�tek: ";
		std::cin >> h_start_pt;
		std::cout << "Wprowad� do kt�rej godziny mo�esz mie� wizyt� w pi�tek: ";
		std::cin >> h_end_pt;
	}
};

