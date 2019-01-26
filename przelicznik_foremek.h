#pragma once
#include<string>
struct przelicznik_foremek {
	void instrukcja2();
	double* wyb_formy();
	double* wyb_formy2();
	char *Z_for{};
	char *Do_for{};
	void przel_foremek();
	double blach1, blach2, sredn;

	double objetoscp(double, double);
	double objetosck(double);
	double* v1;
	double* v2;
	void wczyt_skladniki();
	int skl{};
	std::string *Nazwy_w{};
	double* Ilosci_w{};
	std::string* Jednostki_w{};
	void przeliczone();
};