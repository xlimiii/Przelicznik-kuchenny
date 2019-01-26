//
//  1_przelicznik_kulinarny.cpp
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#include<iostream>
#include <windows.h> 
#include <stdlib.h> 
#include <string>
#include <cstdlib> 
#include <time.h>
#include<fstream>
#include"Nag³ówek.h"
#include"przelicznik_kulinarny.h"
using namespace std;
void przelicznik_kulinarny::instrukcja1()
{
	system("cls");
	cout << "PRZELICZNIK KULINARNY \n";
	cout << "Ten kalkulator pozwala przeliczac miare, wage i objetosc skladnikow na wybrane jednostki/miary.\n\n";
	cout << "Instrukcja obslugi programu\n";
	cout << "1) Wybierz z listy produkt, dla ktorego chcesz wykonac przeliczenie. \n";
	cout << "2) Wybierz, dla jakiej jednostki masz podana ilosc produktu.\n";
	cout << "3) Wybierz, w jakiej jednostce chcesz otrzymac wynik po przeliczeniu.\n";
	cout << "4) Podaj ilosc produktu dla znanego wymiaru.\n\n";
	cout << "Wcisnij enter, aby przejsc dalej.";
	cin.get(); cin.get();
}
void przelicznik_kulinarny::przel_kulinarny()
{
	instrukcja1();
	wybor_produktu();
	z_czego();
	do_czego();
	przel_jedn(Prod, Wym1, Wym2);
}
int* przelicznik_kulinarny::wybor_produktu()
{
	int produkt;
	do {
		system("CLS");
		cout << "Jaki produkt chcesz przeliczyc? " << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << i + 1 << ". " << tab_prod[i] << endl;
		}
		cout << "Wpisz numer produktu: ";
		cin >> produkt;
		if ((produkt < 1) || (produkt > 20))
		{
			cout << "Cos poszlo nie tak. Sprobuj ponownie" << endl;
			Sleep(2000);
		}
	} while ((produkt < 1) || (produkt > 20));
	*Prod = produkt;
	system("CLS");
	return Prod;
}
int* przelicznik_kulinarny::z_czego()
{
	int z_czego;
	do {
		system("CLS");
		cout << "Przeliczasz produkt: " << tab_prod[*Prod - 1] << endl;
		cout << "Z jakiego wymiaru chcesz przeliczac:" << endl;
		for (int i = 0; i < 6; i++)
		{
			{
				cout << i + 1 << ". " << wymiar[i] << endl;
			}
		}
		cout << "Wybierz numer: ";
		cin >> z_czego;
		if (z_czego != 1 && z_czego != 2 && z_czego != 3 && z_czego && 4 && z_czego != 5 && z_czego != 6)
		{
			cout << "Cos poszlo nie tak. Sprobuj ponownie" << endl;
			Sleep(2000);
		}
	} while (z_czego < 1 || z_czego > 6);
	*Wym1 = z_czego;
	return Wym1;
}
int* przelicznik_kulinarny::do_czego() //funckja
{
	int do_czego;
	do
	{
		system("CLS");
		cout << "Przeliczasz produkt: " << tab_prod[*Prod - 1] << endl;
		cout << "Przeliczasz z wymiaru: " << wymiar[*Wym1 - 1] << endl;
		cout << "Jaka jest wymiar docelowy?" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ". " << wymiar[i] << endl;
		}
		cout << "Wybierz numer: ";
		cin >> do_czego;
		if (do_czego < 1 || do_czego > 6)
		{
			cout << "Cos poszlo nie tak. Sprobuj ponownie" << endl;
			Sleep(3000);
		}
	} while (do_czego < 1 || do_czego > 6);
	*Wym2 = do_czego;
	return Wym2;
}
double przelicznik_kulinarny::jaka_gestosc(int a) //funckja zwracajaca gestosc podanego produktu
{
	double tab_d[20]; //tabela gêstoœci
	tab_d[0] = 0; //0
	tab_d[1] = 0.68; //maka pszenna
	tab_d[2] = 0.76; //maka ziemniaczana
	tab_d[3] = 0.84; //maka krupczatka
	tab_d[4] = 0.64; // maka graham
	tab_d[5] = 0.55; //maka zytnia
	tab_d[6] = 0.88; //cukier krysztal
	tab_d[7] = 0.68; //cukier puder
	tab_d[8] = 0.48; //platki owsiane
	tab_d[9] = 0.44; //wiorki kokosowe
	tab_d[10] = 0.64; //mak
	tab_d[11] = 0.52; //orzechy w³oskie, laskowe, pekan zmielone
	tab_d[12] = 0.44; //migdaly zmielone
	tab_d[13] = 0.52; //kakao
	tab_d[14] = 1.04; //smietana kremowka
	tab_d[15] = 0.92; //olej
	tab_d[16] = 1; //mleko
	tab_d[17] = 1; //woda
	tab_d[18] = 1.44; //miod
	return tab_d[a];
}
void przelicznik_kulinarny::przel_jedn(int *a, int *b, int *c)
{
	system("CLS");
	cout << "Przeliczasz produkt: " << tab_prod[*a - 1] << endl;
	cout << "Przeliczasz z wymiaru: " << wymiar[*b - 1] << endl;
	cout << "Przeliczasz do wymiaru: " << wymiar[*c - 1] << endl;
	cout << "Ilosc produktu: ";
	double ilosc, wynik;
	cin >> ilosc;
	if (*b == *c)
	{
		cout << "Przeliczasz z wymiaru: " << wymiar[*b - 1] << " na wymiar: " << wymiar[*c - 1] << ". " << endl;
		wynik = ilosc;
		cout << ilosc << wym_przez[*b - 1] << " to po prostu " << wynik << wym_przez[*c - 1] << ". " << endl;
	}
	else
	{
		if ((*b) == 1 || (*b) == 2 || (*b) == 3)
		{
			wynik = ilosc * jaka_gestosc(*a - 1) * tab[*b - 1] / tab[*c - 1];
			cout << ilosc << wym_przez[*b - 1] << " to  " << wynik << wym_przez[*c - 1] << ". " << endl; //sprawdzic tab dla jednostek dodanych
		}
		else if ((*b) == 4 || (*b) == 5)
		{
			if ((*c) == 1 || (*c) == 2 || (*c) == 3)
			{
				wynik = ilosc * tab[*b - 1] / jaka_gestosc(*a - 1) / tab[*c - 1];
				cout << ilosc << wym_przez[*b - 1] << " to " << wynik << wym_przez[*c - 1] << ". " << endl;
			}
			else if ((*c) == 4 || (*c) == 5)
			{
				wynik = ilosc * tab[*b - 1] / tab[*c - 1];
				cout << ilosc << wym_przez[*b - 1] << " to " << wynik << wym_przez[*c - 1] << ". " << endl;
			}
		}
	}
}