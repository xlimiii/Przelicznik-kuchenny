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
	void ustaw_kursor(int x, int y);
	double wynik, ile;
	double *ilosc = &ile;
	double przel_jedn(int, int, int);
	std::string tab_prod[20] = { "Maka pszenna","Maka ziemniaczana", "Maka krupczatka","Maka graham", "Maka zytnia","Cukier krysztal", "Cukier puder" ,"Platki owsiane",
			"Wiorki kokosowe","Mak", "Orzechy wloskie, laskowe, pekan zmielone","Migdaly zmielone", "Kakao","Smietana kremowka", "Olej","Mleko","Woda","Miod", "Kasza manna", "Platki owsiane"};
	std::string wymiar[8] = { "Szklanka" ,"Lyzka kuchenna", "Lyzeczka" ,"Gramy", "Dekagramy", "Kilogramy", "Mililitry", "Litry" };
	std::string wym_przez[8] = { "szkl." ,"lyzk. stol.", "lyczeczk." ,"g", "dag", "kg", "ml" , "l" };
	double tab[8] = { 250, 15, 5, 1, 10, 1000, 1, 1000 };
	void drukuj_wynik(int, int, int, double);

};
