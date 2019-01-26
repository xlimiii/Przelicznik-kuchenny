#pragma once
#include<string>
struct przelicznik_kulinarny {
	void instrukcja1();
	void przel_kulinarny();
	int* wybor_produktu();
	int* z_czego();
	int* do_czego();
	int produkt{};
	double jaka_gestosc(int);
	void przel_jedn(int *wsk, int *wsk1, int *wsk2);
	int *Prod = &produkt;
	int wymiar1{};
	int *Wym1 = &wymiar1;
	int wymiar2{};
	int *Wym2 = &wymiar2;
	std::string tab_prod[20] = { "Maka pszenna","Maka ziemniaczana", "Maka krupczatka","Maka graham", "Maka zytnia","Cukier krysztal", "Cukier puder" ,"Platki owsiane",
			"Wiorki kokosowe","Mak", "Orzechy wloskie, laskowe, pekan zmielone","Migdaly zmielone", "Kakao","Smietana kremowka", "Olej","Mleko","Woda","Miod" };
	std::string wymiar[6] = { "Szklanka" ,"Lyzka kuchenna", "Lyzeczka" ,"Gramy","Kilogramy" };
	std::string wym_przez[6] = { "Szkl." ,"Lyzk. stol.", "Lyczeczk." ,"g","kg" };
	double tab[6] = { 250, 15, 5, 1, 1000 };
};
