//
//  przelicznik_foremek.cpp
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#include<iostream>
#include <windows.h> 
#include <string>
#include<fstream>
#include"Nag³ówek.h"
#include"przelicznik_foremek.h"
using namespace std;
void przelicznik_foremek::glowna() //funkcja g³ówna 
{
	char kont;
	do {
		for (int i = 0; i < ilosc_skladnikow + 10; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				ustaw_kursor(j, i); cout << " ";
			}
		}
		ustaw_kursor(46, 1); cout << "Czy chcesz przeliczac dalej?" << endl;
		ustaw_kursor(57, 2); cout << "A - tak";
		ustaw_kursor(49, 3); cout << "M - nie, wroc do menu";
		ustaw_kursor(42, 4); cout << "E - nie, zakoncz dzialanie programu";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(50, 5); cout << "Wpisz A, M lub E: ";
		cin >> kont;
		kont = toupper(kont);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		switch (kont)
		{
		case 'A': przel_foremek(); break;
		case 'M': menu(); break;
		case 'E': return; break;
		default: {cout << "Cos poszlo nie tak, sprobuj ponownie"; } break;
		}
	} while (kont != 'A' || kont != 'M' || kont != 'E');

}
void przelicznik_foremek::instrukcja2() //instrukcja
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "                                                 PRZELICZNIK FOREMEK                                                   " << endl;
	cout << "   Ten kalkulator pozwala na przeliczania skladnikow z przepisu na inna foremke (prostokatna blaszke lub tortownice)   " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                             Instrukcja obslugi programu                                             *" << endl; 
	cout << "*                                             1) Wybierz forme z przepisu.                                            *" << endl;
	cout << "*                               2) Wybierz forme, do ktorej chcesz wykonac przeliczenie.                              *" << endl;
	cout << "*                                        3) Podaj ilosc skladnikow w przepisie                                        *" << endl;
	cout << "*           4) Wpisz kolejno: nazwe produktu, pozniej jego ilosc oraz jednostke, w ktorej ilosc jest podana.          *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "Wcisnij enter, aby przejsc dalej.";
	cin.get(); cin.get();
}
void przelicznik_foremek::przel_foremek() //g³ówna funkcja
{
	instrukcja2();
	wyb_formy();
	wyb_formy2();
	wczyt_skladniki();
	przeliczone(Nazwy_w, Ilosci_w, Jednostki_w);
	glowna();

}
double przelicznik_foremek::wyb_formy() //wybor foremek, zwraca objetosc
{
	char z_for;
	do {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		ustaw_kursor(28, 2); cout.width(64); cout << "*****************************************************************" << endl;
		ustaw_kursor(28, 3); cout.width(64);  cout << left << "*                       Foremka z przepisu: " << "*" << endl;
		ustaw_kursor(28, 4); cout.width(64);  cout << left << "*                          A - blaszka" << "*" << endl;
		ustaw_kursor(28, 5); cout.width(64); cout << left << "*                         B - tortownica" << "*" << endl;
		ustaw_kursor(28, 6); cout.width(64); cout << "*****************************************************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(28, 7); cout << "Wpisz A lub B: ";
		cin >> z_for;
		z_for = toupper(z_for);
		if (z_for != 'A' && z_for != 'B') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Cos poszlo nie tak, sprobuj ponownie."; Sleep(1500);
		}
	} while (z_for != 'A' && z_for != 'B');
	if (z_for == 'A')
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		ustaw_kursor(47, 1); cout << "Foremka z przepisu: blaszka";
		ustaw_kursor(52, 3);  cout << "Podaj wymiary (w cm): " << endl;
		ustaw_kursor(50, 5); cout << "                   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(49, 4) ; cout << "Dlugosc pierwszego boku =  ";
		cin >> blach1;
		ustaw_kursor(50, 5); cout << "Dlugosc drugiego boku = ";
		ustaw_kursor(74 ,5); cin >> blach2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		v1 = objetoscp(blach1, blach2);
		
	}
	else if (z_for == 'B')
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		ustaw_kursor(50, 5); cout << "                   ";
		ustaw_kursor(47, 1); cout << "Foremka z przepisu: tortownica";
		ustaw_kursor(52, 3);  cout << "Podaj wymiary (w cm): " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(52, 4); cout << "Srednica blaszki = ";
		cin >> sredn;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		objetosck(sredn);
		v1 = objetosck(sredn);
	}
	return v1;
}
double przelicznik_foremek::wyb_formy2() //wybór formy docelowej, zwraca objetosc
{
	char do_for;
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		ustaw_kursor(28, 9); cout.width(64); cout << "*****************************************************************" << endl;
		ustaw_kursor(28, 10); cout.width(64);  cout << left << "*                         Foremka docelowa: " << "*" << endl;
		ustaw_kursor(28, 11); cout.width(64);  cout << left << "*                           A - blaszka" << "*" << endl;
		ustaw_kursor(28, 12); cout.width(64); cout << left << "*                          B - tortownica" << "*" << endl;
		ustaw_kursor(28, 13); cout.width(64); cout << "*****************************************************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(28, 14); cout << "Wpisz A lub B: ";
		cin >> do_for;
		do_for = toupper(do_for);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if (do_for != 'A' && do_for != 'B') {
			cout << "Cos poszlo nie tak, sprobuj ponownie."; Sleep(1500);
		}
	} while (do_for != 'A' && do_for != 'B');
	if (do_for == 'A') 
	{
		ustaw_kursor(47, 8); cout << "Foremka docelowa: blaszka";
		ustaw_kursor(52, 10);  cout << "Podaj wymiary (w cm): " << endl;
		ustaw_kursor(50, 12); cout << "                   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(49, 11); cout << "Dlugosc pierwszego boku =  ";
		cin >> blach1;
		ustaw_kursor(50, 12); cout << "Dlugosc drugiego boku = ";
		cin >> blach2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		v2 = objetoscp(blach1, blach2);
	}
	else if (do_for == 'B')
	{
		ustaw_kursor(50, 12); cout << "                   ";
		ustaw_kursor(47, 8); cout << "Foremka docelowa: tortownica";
		ustaw_kursor(52, 10);  cout << "Podaj wymiary (w cm): " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(52, 11); cout << "Srednica blaszki = ";
		cin >> sredn;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		objetosck(sredn);
		v2 = objetosck(sredn);
	}
	return v2;
}
int przelicznik_foremek::wczyt_skladniki() //wczytuje nazwy, ilosci, jednostki
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	ustaw_kursor(30, 15); cout << "Z ilu skladnikow sklada sie ciasto?"; 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout<<" Wpisz ilosc skladnikow: ";
	cin >> ilosc_skladnikow;
	for (int i = 0; i < 119; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			ustaw_kursor(i, j); cout << " ";
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	ustaw_kursor(28, 1); cout.width(64); cout << "*****************************************************************" << endl;
	string *Nazwy;
	Nazwy = new string[ilosc_skladnikow];
	double *Ilosci;
	Ilosci = new double[ilosc_skladnikow];
	string *Jednostka;
	Jednostka = new string[ilosc_skladnikow];
	for (int i = 0; i < ilosc_skladnikow; i++)
	{
		string nazwa;
		for (int j = 0; j < ilosc_skladnikow*3+2; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			ustaw_kursor(28, 2+ 3*ilosc_skladnikow); cout.width(64); cout << "*****************************************************************" << endl;
			ustaw_kursor(92, j + 1 ); cout << "*";
			ustaw_kursor(28, j + 1); cout << "*";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(30, 2+3*i); cout << "Nazwa produktu: ";
		cin >> nazwa;
		Nazwy[i] = nazwa;
		double ilosc;
		ustaw_kursor(30, 3+3*i); cout << "Ilosc produktu: ";
		cin >> ilosc;
		Ilosci[i] = ilosc;
		string jednostka;
		ustaw_kursor(30, 4+3*i); cout << "Jednostka: ";
		cin >> jednostka;
		Jednostka[i] = jednostka;
	}
	Nazwy_w = Nazwy;
	Ilosci_w = Ilosci;
	Jednostki_w = Jednostka;
	return ilosc_skladnikow;
}
void przelicznik_foremek::przeliczone( string* wsk1, double* wsk2, string* wsk3) //wyswietla przeliczone wartosci
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "Skladniki w przeliczeniu na wybrana foremke: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i < ilosc_skladnikow; i++)
	{
		cout << *(wsk1 + i) << ": " << *(wsk2 + i) * v2/v1 << " " << *(wsk3 + i) << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\nCzy chcesz zapisac przeliczone wartosci do pliku?" << endl << "Wpisz T/N: ";
	char wybor;
	cin >> wybor;
	wybor = toupper(wybor);
	if (wybor == 'T')
	{
		ofstream plik("Skladniki.txt");
		plik << "Skladniki w przeliczeniu na wybrana foremke: " << endl;
		for (int i = 0; i < ilosc_skladnikow; i++)
		{
			plik << *(wsk1 + i) << ": " << *(wsk2 + i) * v2 / v1 << *(wsk3 + i) << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\nPrzeliczone wartosci zostaly zapisane w pliku \"Skladniki\"" << endl;
	}
}
double przelicznik_foremek::objetoscp(double a, double b) //objetosc prostokatnej blaszki
{
	double objetosc;
	objetosc = a * b;
	return objetosc;
}
double przelicznik_foremek::objetosck(double d) //objetosc tortownicy
{
	double objetosc;
	objetosc = (d / 2) * (d / 2) * 3.14;
	return objetosc;
}
void ustaw_kursor(int x, int y) //ustawia kursor
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}