#pragma once
#include<string>
struct przelicznik_foremek {
	void instrukcja2();
	double wyb_formy();
	double wyb_formy2();
	double v1, v2;
	std::string z, d;
	std::string* Z_for = &z;
	std::string* Do_for = &d;
	void przel_foremek();
	double blach1, blach2, sredn;
	double objetoscp(double, double);
	double objetosck(double);
	int wczyt_skladniki();
	int ilosc_skladnikow;
	std::string naz, jedn;
	double ile;
	std::string *Nazwy_w = &naz;
	double* Ilosci_w = &ile;
	std::string* Jednostki_w = &jedn;
	void przeliczone(std::string* wsk1, double* wsk2, std::string* wsk3);
};