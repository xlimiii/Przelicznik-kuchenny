//
//  przepisy.h
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#pragma once
#include <string>
struct przepis {
	int numer;
	std::string tytul;
	przepis* kolejny;
	void drukuj_nazwe();
	void wyswietl_przepis(std::string nazwa, int);
	int sprawdz_ilosc_skladnikow(std::string nazwa, int);
	double sprawdz_v1(std::string nazwa, int);
	void przelicz(std::string nazwa, int);
	int gdzie_zaczac(std::string nazwa, int);
};
struct przepisy {
	przepis* pierwszy;
	int drukuj_liste();
};
void wybierz_przepis();
void wylosuj_przepis();