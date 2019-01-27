#pragma once
#include<string>
struct przelicznik_kulinarny {
	void glowna();
	void instrukcja1();
	void przel_kulinarny();
	int wybor_produktu();
	int z_czegoz();
	int do_czegoz();
	int produkt, z_czego, do_czego;
	double jaka_gestosc(int);
	void przel_jedn(int, int, int);
	std::string tab_prod[20] = { "Maka pszenna","Maka ziemniaczana", "Maka krupczatka","Maka graham", "Maka zytnia","Cukier krysztal", "Cukier puder" ,"Platki owsiane",
			"Wiorki kokosowe","Mak", "Orzechy wloskie, laskowe, pekan zmielone","Migdaly zmielone", "Kakao","Smietana kremowka", "Olej","Mleko","Woda","Miod" };
	std::string wymiar[6] = { "Szklanka" ,"Lyzka kuchenna", "Lyzeczka" ,"Gramy","Kilogramy" };
	std::string wym_przez[6] = { "Szkl." ,"Lyzk. stol.", "Lyczeczk." ,"g","kg" };
	double tab[6] = { 250, 15, 5, 1, 1000 };
};
