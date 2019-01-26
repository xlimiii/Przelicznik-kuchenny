//
//  2_przelicznik_foremek.cpp
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
using namespace std;
void instrukcja2()
{
	system("cls");
	cout << "PRZELICZNIK FOREMEK\n";
	cout << "Ten kalkulator pozwala na przeliczania skladnikow z przepisu na inna foremke (prostokatna blaszke lub tortownice)\n";
	cout << "Instrukcja obslugi programu\n";
	cout << "1) Wybierz forme z przepisu.\n";
	cout << "2) Wybierz forme, do ktorej chcesz wykonac przeliczenie.\n";
	cout << "3) Podaj ilosc skladnikow w przepisie\n";
	cout << "4) Wpisz kolejno: nazwe produktu, pozniej jego ilosc oraz jednostke, w ktorej ilosc jest podana.\n";
	cout << "\nWcisnij enter, aby przejsc dalej.";
	cin.get(); cin.get();
}
void przel_foremek()
{
	instrukcja2();
	wyb_formy();
	wyb_formy2();
	wczyt_skladniki();
	przeliczone();

}
double* wyb_formy()
{
	system("cls");
	char z_for;
	Z_for = &z_for;
	cout << "Foremka z przepisu: " << endl;
	cout << "A - blaszka" << endl << "B - tortownica" << endl;
	cout << "Wpisz A lub B" << endl;
	cin >> z_for;
	if (z_for == 'A')
	{
		cout << "Podaj wymiary (w cm): " << endl;
		cout << "Dlugosc pierwszego boku =  ";
		cin >> blach1;
		cout << "Dlugosc drugiego boku = ";
		cin >> blach2;
		double x;
		x = objetoscp(blach1, blach2);
		v1 = &x;
	}
	else if (z_for == 'B')
	{
		cout << "Podaj srednice (w cm): ";
		cin >> sredn;
		double x;
		objetosck(sredn);
		x = objetosck(sredn);
		v1 = &x;
	}
	cout << v1 << *v1 << endl;
	system("pause");
	return v1;
}
double* wyb_formy2()
{
	system("cls");

	char do_for;
	Do_for = &do_for;
	cout << "Foremka z przepisu: " << *v1 << endl << endl;
	cout << "Foremka docelowa: " << endl;
	cout << "A - blaszka" << endl << "B - tortownica" << endl;
	cout << "Wpisz A lub B" << endl;
	cin >> do_for;
	if (do_for == 'A') // ewentualnie zrobiæ z tego dwie funkcje, ktore sie wywoluja na if, a wartosci blach itp. wskazniki?
	{
		cout << "Podaj wymiary (w cm): " << endl;
		cout << "Dlugosc pierwszego boku =  ";
		cin >> blach1;
		cout << "Dlugosc drugiego boku = ";
		cin >> blach2;
		double x;
		x = objetoscp(blach1, blach2);
		v2 = &x;
	}
	else if (do_for == 'B')
	{
		cout << "Podaj srednice (w cm): ";
		cin >> sredn;
		objetosck(sredn);
		*v2 = objetosck(sredn);
	}
	return v2;
}
void wczyt_skladniki()
{
	cout << "Z ilu skladnikow sklada sie ciasto? ";
	int ilosc_skladnikow;
	cin >> ilosc_skladnikow;
	string *Nazwy;
	Nazwy = new string[ilosc_skladnikow];
	double *Ilosci;
	Ilosci = new double[ilosc_skladnikow];
	string *Jednostka;
	Jednostka = new string[ilosc_skladnikow];
	for (int i = 0; i < ilosc_skladnikow; i++)
	{
		string nazwa;
		cout << "Nazwa produktu: ";
		cin >> nazwa;
		Nazwy[i] = nazwa;
		double ilosc;
		cout << "Ilosc produktu: ";
		cin >> ilosc;
		Ilosci[i] = ilosc;
		string jednostka;
		cout << "Jednostka: ";
		cin >> jednostka;
		Jednostka[i] = jednostka;
	}
	skl = ilosc_skladnikow;
	Nazwy_w = &Nazwy[0];
	Ilosci_w = &Ilosci[0];
	Jednostki_w = &Jednostka[0];
}
void przeliczone()
{
	for (int i = 0; i < skl; i++)
	{
		cout << *(Nazwy_w + i) << ": " << *(Ilosci_w + i) * (*v2) / (*v1) << *(Jednostki_w + i) << endl;
	}
}
double objetoscp(double a, double b)
{
	double objetosc;
	objetosc = a * b;
	return objetosc;
}
double objetosck(double d)
{
	double objetosc;
	objetosc = (d / 2) * (d / 2) * 3.14;
	return objetosc;
}