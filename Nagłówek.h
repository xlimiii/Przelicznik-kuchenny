//
//  Naglowek.h
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#pragma once
#include <string>
void start(), tytul(), menu();
void instrukcja(), instrukcja1(), instrukcja2();
void przel_kulinarny();
int* wybor_produktu();
int* z_czego();
int* do_czego();
__declspec(selectany) int produkt{};
double jaka_gestosc(int);
void przel_jedn(int *wsk, int *wsk1, int *wsk2);
__declspec(selectany) int *Prod = &produkt;
__declspec(selectany) int wymiar1{};
__declspec(selectany) int *Wym1 = &wymiar1;
__declspec(selectany) int wymiar2{};
__declspec(selectany) int *Wym2 = &wymiar2;
__declspec(selectany)std::string tab_prod[20] = { "Maka pszenna","Maka ziemniaczana", "Maka krupczatka","Maka graham", "Maka zytnia","Cukier krysztal", "Cukier puder" ,"Platki owsiane",
		"Wiorki kokosowe","Mak", "Orzechy wloskie, laskowe, pekan zmielone","Migdaly zmielone", "Kakao","Smietana kremowka", "Olej","Mleko","Woda","Miod" };
__declspec(selectany)std::string wymiar[6] = { "Szklanka" ,"Lyzka kuchenna", "Lyzeczka" ,"Gramy","Kilogramy" };
__declspec(selectany)std::string wym_przez[6] = { "Szkl." ,"Lyzk. stol.", "Lyczeczk." ,"g","kg" };
__declspec(selectany) double tab[6] = { 250, 15, 5, 1, 1000 };
double* wyb_formy();
double* wyb_formy2();
__declspec(selectany) char *Z_for{};
__declspec(selectany) char *Do_for{};
void przel_foremek();
__declspec(selectany) double blach1, blach2, sredn;
void losuj_przepis();
double objetoscp(double, double);
double objetosck(double);
__declspec(selectany) double* v1;
__declspec(selectany) double* v2;
void wczyt_skladniki();
__declspec(selectany)int skl{};
__declspec(selectany) std::string *Nazwy_w{};
__declspec(selectany) double* Ilosci_w{};
__declspec(selectany) std::string* Jednostki_w{};
void przeliczone();