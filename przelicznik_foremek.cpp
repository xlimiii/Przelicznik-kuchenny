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
#include"przelicznik_foremek.h"
using namespace std;
void przelicznik_foremek::instrukcja2()
{
	system("cls");
	cout << "                                                 PRZELICZNIK FOREMEK                                                   " << endl;
	cout << "   Ten kalkulator pozwala na przeliczania skladnikow z przepisu na inna foremke (prostokatna blaszke lub tortownice)   " << endl << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                           Instrukcja obslugi programu                                               *" << endl;
	cout << "*                                           1) Wybierz forme z przepisu.                                              *" << endl;
	cout << "*                          2) Wybierz forme, do ktorej chcesz wykonac przeliczenie.                                   *" << endl;
	cout << "*                                    3) Podaj ilosc skladnikow w przepisie                                            *" << endl;
	cout << "*          4) Wpisz kolejno: nazwe produktu, pozniej jego ilosc oraz jednostke, w ktorej ilosc jest podana.           *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "Wcisnij enter, aby przejsc dalej.";
	cin.get(); cin.get();
}
void przelicznik_foremek::przel_foremek()
{
	instrukcja2();
	wyb_formy();
	wyb_formy2();
	wczyt_skladniki();
	przeliczone(Nazwy_w, Ilosci_w, Jednostki_w);

}
double przelicznik_foremek::wyb_formy() //wybor foremek, zwraca objetosc
{
	system("cls");
	char z_for;
	cout << "Foremka z przepisu: " << endl;
	cout << "A - blaszka" << endl << "B - tortownica" << endl;
	cout << "Wpisz A lub B: ";
	cin >> z_for;
	if (z_for == 'A')
	{
		cout << "Podaj wymiary (w cm): " << endl;
		cout << "Dlugosc pierwszego boku =  ";
		cin >> blach1;
		cout << "Dlugosc drugiego boku = ";
		cin >> blach2;
		v1 = objetoscp(blach1, blach2);
		
	}
	else if (z_for == 'B')
	{
		cout << "Podaj srednice (w cm): ";
		cin >> sredn;
		objetosck(sredn);
		v1 = objetosck(sredn);
	}
	return v1;
}
double przelicznik_foremek::wyb_formy2()
{
	char do_for;
	cout << "Foremka docelowa: " << endl;
	cout << "A - blaszka" << endl << "B - tortownica" << endl;
	cout << "Wpisz A lub B: ";
	cin >> do_for;
	if (do_for == 'A') // ewentualnie zrobiæ z tego dwie funkcje, ktore sie wywoluja na if, a wartosci blach itp. wskazniki?
	{
		cout << "Podaj wymiary (w cm): " << endl;
		cout << "Dlugosc pierwszego boku =  ";
		cin >> blach1;
		cout << "Dlugosc drugiego boku = ";
		cin >> blach2;
		v2 = objetoscp(blach1, blach2);
	}
	else if (do_for == 'B')
	{
		cout << "Podaj srednice (w cm): ";
		cin >> sredn;
		objetosck(sredn);
		v2 = objetosck(sredn);
	}
	return v2;
}
int przelicznik_foremek::wczyt_skladniki()
{
	cout << "Z ilu skladnikow sklada sie ciasto? ";
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
	Nazwy_w = Nazwy;
	Ilosci_w = Ilosci;
	Jednostki_w = Jednostka;
	return ilosc_skladnikow;
}
void przelicznik_foremek::przeliczone( string* wsk1, double* wsk2, string* wsk3)
{
	system("cls");
	cout << "Skladniki w przeliczeniu na wybrana foremke: " << endl;
	for (int i = 0; i < ilosc_skladnikow; i++)
	{
		cout << *(wsk1 + i) << ": " << *(wsk2 + i) * v2/v1 << " " << *(wsk3 + i) << endl;
	}
	cout << "\nCzy chcesz zapisac przeliczone wartosci do pliku?" << endl << "Wpisz T/N: ";
	char wybor;
	cin >> wybor;
	if (wybor == 'T')
	{
		ofstream plik("Skladniki.txt");
		plik << "Skladniki w przeliczeniu na wybrana foremke: " << endl;
		for (int i = 0; i < ilosc_skladnikow; i++)
		{
			plik << *(wsk1 + i) << ": " << *(wsk2 + i) * v2 / v1 << *(wsk3 + i) << endl;
		}
		cout << "Przeliczone wartosci zostaly zapisane w pliku \"Skladniki\"" << endl;
	}
}
double przelicznik_foremek::objetoscp(double a, double b)
{
	double objetosc;
	objetosc = a * b;
	return objetosc;
}
double przelicznik_foremek::objetosck(double d)
{
	double objetosc;
	objetosc = (d / 2) * (d / 2) * 3.14;
	return objetosc;
}