#include<iostream>


class Dane_klienta {
public:
	std::string imie, nazwisko;
	unsigned int wiek;
	float dlugosc_wizyty;
	float h_start_pon, h_end_pon, h_start_wt, h_end_wt, h_start_sr, h_end_sr, h_start_czw, h_end_czw, h_start_pt, h_end_pt; //podaje swoje zakresy czasowe w danym dniu

	void wczytajDane() {
		std::cout << "WprowadŸ imiê: ";
		std::cin >> imie;
		std::cout << "WprowadŸ nazwisko: ";
		std::cin >> nazwisko;
		std::cout << "WprowadŸ wiek: ";
		std::cin >> wiek;
		std::cout << "WprowadŸ d³ugoœæ wizyty: ";
		std::cin >> dlugosc_wizyty;
		std::cout << "WprowadŸ od której godziny mo¿esz mieæ wizytê w poniedzia³ek: ";
		std::cin >> h_start_pon;
		std::cout << "WprowadŸ do której godziny mo¿esz mieæ wizytê w poniedzia³ek: ";
		std::cin >> h_end_pon;
		std::cout << "WprowadŸ od której godziny mo¿esz mieæ wizytê we wtorek: ";
		std::cin >> h_start_wt;
		std::cout << "WprowadŸ do której godziny mo¿esz mieæ wizytê we wtorek: ";
		std::cin >> h_end_wt;
		std::cout << "WprowadŸ od której godziny mo¿esz mieæ wizytê w œrodê: ";
		std::cin >> h_start_sr;
		std::cout << "WprowadŸ do której godziny mo¿esz mieæ wizytê w œrodê: ";
		std::cin >> h_end_sr;
		std::cout << "WprowadŸ od której godziny mo¿esz mieæ wizytê we czwartek: ";
		std::cin >> h_start_pt;
		std::cout << "WprowadŸ do której godziny mo¿esz mieæ wizytê we czwartek: ";
		std::cin >> h_end_pt;
		std::cout << "WprowadŸ od której godziny mo¿esz mieæ wizytê w pi¹tek: ";
		std::cin >> h_start_pt;
		std::cout << "WprowadŸ do której godziny mo¿esz mieæ wizytê w pi¹tek: ";
		std::cin >> h_end_pt;
	}
};

