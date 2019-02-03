//
//  1_przelicznik_kulinarny.cpp
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#include<iostream>
#include <windows.h> 
#include <string>
#include<fstream>
#include"Nag³ówek.h"
#include"przelicznik_kulinarny.h"
using namespace std;
void przelicznik_kulinarny::instrukcja1()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout.width(49); cout << " "; cout << "PRZELICZNIK KULINARNY"  << endl;
	cout.width(12); cout << " "; cout << "Ten kalkulator pozwala przeliczac miare, wage i objetosc skladnikow na wybrane jednostki/miary.  " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout.width(10); cout << " "; cout << "****************************************************************************************************" << endl;
	cout.width(10); cout << " "; cout << "*                                Instrukcja obslugi programu                                       *" << endl;
	cout.width(10); cout << " "; cout << "*              1) Wybierz z listy produkt, dla ktorego chcesz wykonac przeliczenie.                *" << endl;
	cout.width(10); cout << " "; cout << "*                  2) Wybierz, dla jakiej jednostki masz podana ilosc produktu.                    *" << endl;
	cout.width(10); cout << " "; cout << "*              3) Wybierz, w jakiej jednostce chcesz otrzymac wynik po przeliczeniu.               *" << endl;
	cout.width(10); cout << " "; cout << "*                       4) Podaj ilosc produktu dla znanego wymiaru.                               *" << endl;
	cout.width(10); cout << " "; cout << "*                                                                                                  *" << endl;
	cout.width(10); cout << " "; cout << "****************************************************************************************************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout.width(10); cout << " "; cout << "Wcisnij enter, aby przejsc dalej.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin.get(); cin.get();
}
void przelicznik_kulinarny::glowna()
{
	char kont;
	do {
		ustaw_kursor(43, 11); cout<< "                                                                        ";
		ustaw_kursor(46, 11); cout << "Czy chcesz przeliczac dalej?" << endl;
		ustaw_kursor(57, 12); cout << "A - tak";
		ustaw_kursor(49, 13); cout << "M - nie, wroc do menu";
		ustaw_kursor(42, 14); cout << "E - nie, zakoncz dzialanie programu";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(50, 15); cout << "Wpisz A, M lub E: ";
		cin >> kont;
		kont = toupper(kont);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		switch (kont)
		{
		case 'A': przel_kulinarny(); break;
		case 'M': menu(); break;
		case 'E': return; break;
		default: {ustaw_kursor(42, 16); cout << "Cos poszlo nie tak, sprobuj ponownie"; ustaw_kursor(68, 15); cout << "  "; } break;
		}
	} while (kont != 'A' || kont != 'M' || kont != 'E');

}
void przelicznik_kulinarny::przel_kulinarny()
{
	instrukcja1();
	wybor_produktu();
	z_czegoz();
	do_czegoz();
	przel_jedn(produkt, z_czego, do_czego);
	drukuj_wynik(produkt, z_czego, do_czego, wynik);
	glowna();
	
}
int przelicznik_kulinarny::wybor_produktu()
{	do {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout.width(44); cout << " ";  cout << "Jaki produkt chcesz przeliczyc? " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout.width(27); cout << " "; cout << "  *****************************************************************" << endl;
		string s;
		for (int i = 0; i < 20; i++)
		{
			s = "  * " + to_string(i + 1) + ". " + tab_prod[i];
			cout.width(27); cout << " "; cout.width(66); cout << left << s << "* " << endl;
		}
		cout.width(27); cout << " "; cout << "  *****************************************************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout.width(27); cout << " "; cout << "  Wpisz numer produktu: ";
		cin >> produkt;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if ((produkt < 1) || (produkt > 20))
		{
			cout.width(29); cout << " "; cout << "Cos poszlo nie tak. Sprobuj ponownie" << endl;
			Sleep(2000);
		}
	} while ((produkt < 1) || (produkt > 20));
	system("CLS");
	return produkt;
}
int przelicznik_kulinarny::z_czegoz()
{
	do {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Przeliczasz produkt: " << tab_prod[produkt - 1] << "\n\n\n\n";
		cout.width(44); cout << " ";  cout << "Z jakiego wymiaru chcesz przeliczac? " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout.width(27); cout << " "; cout << "  *****************************************************************" << endl;
		string s;
		for (int i = 0; i < 8; i++)
		{
			s = "  * " + to_string(i + 1) + ". " + wymiar[i];
			cout.width(27); cout << " "; cout.width(66); cout << left << s << "* " << endl;
		}
		cout.width(27); cout << " "; cout << "  *****************************************************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout.width(29); cout << " "; cout << "Wybierz numer: ";
		cin >> z_czego;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if (z_czego != 1 && z_czego != 2 && z_czego != 3 && z_czego != 4 && z_czego != 5 && z_czego != 6 && z_czego!=7 && z_czego != 8)
		{
			cout << "Cos poszlo nie tak. Sprobuj ponownie" << endl;
			Sleep(2000);
		}
	} while (z_czego != 1 && z_czego != 2 && z_czego != 3 && z_czego != 4 && z_czego != 5 && z_czego != 6 && z_czego != 7 && z_czego != 8);
	return z_czego;
}
int przelicznik_kulinarny::do_czegoz() 
{
	do
	{
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Przeliczasz produkt: " << tab_prod[produkt-1] << endl;
		cout << "Przeliczasz z wymiaru: " << wymiar[z_czego - 1] << "\n\n\n\n";
		cout.width(44); cout << " "; cout << "Jaki jest wymiar docelowy? " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout.width(29); cout << " "; cout << "*****************************************************************" << endl;
		string s;
		for (int i = 0; i < 8; i++)
		{
			s = "  * " + to_string(i + 1) + ". " + wymiar[i];
			cout.width(27); cout << " "; cout.width(66); cout << left << s << "* " << endl;
		}
		cout.width(27); cout << " "; cout << "  *****************************************************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout.width(29); cout << " "; cout << "Wybierz numer: ";
		cin >> do_czego;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if (do_czego != 1 && do_czego != 2 && do_czego != 3 && do_czego != 4 && do_czego != 5 && do_czego != 6 && do_czego != 7 && do_czego != 8)
		{
			cout << "Cos poszlo nie tak. Sprobuj ponownie" << endl;
			Sleep(3000);
		}
	} while (do_czego != 1 && do_czego != 2 && do_czego != 3 && do_czego != 4 && do_czego != 5 && do_czego != 6 && do_czego != 7 && do_czego != 8);
	return do_czego;
}
double przelicznik_kulinarny::jaka_gestosc(int a) //funckja zwracajaca gestosc podanego produktu
{
	double tab_d[20]; //tabela gêstoœci
	tab_d[0] = 0.68; //maka pszenna
	tab_d[1] = 0.76; //maka ziemniaczana
	tab_d[2] = 0.84; //maka krupczatka
	tab_d[3] = 0.64; // maka graham
	tab_d[4] = 0.55; //maka zytnia
	tab_d[5] = 0.88; //cukier krysztal
	tab_d[6] = 0.68; //cukier puder
	tab_d[7] = 0.48; //platki owsiane
	tab_d[8] = 0.44; //wiorki kokosowe
	tab_d[9] = 0.64; //mak
	tab_d[10] = 0.52; //orzechy w³oskie, laskowe, pekan zmielone
	tab_d[11] = 0.44; //migdaly zmielone
	tab_d[12] = 0.52; //kakao
	tab_d[13] = 1.04; //smietana kremowka
	tab_d[14] = 0.92; //olej
	tab_d[15] = 1; //mleko
	tab_d[16] = 1; //woda
	tab_d[17] = 1.44; //miod
	tab_d[18] = 0.71; //kasza manna
	tab_d[19] = 0.5; //platki owsiane

	return tab_d[a];
}
double przelicznik_kulinarny::przel_jedn(int a, int b, int c)
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "Przeliczasz produkt: " << tab_prod[a - 1] << endl;
	cout << "Przeliczasz z wymiaru: " << wymiar[b - 1] << endl;
	cout << "Przeliczasz do wymiaru: " << wymiar[c - 1] << "\n\n\n";
	cout.width(50); cout << " "; cout << "Podaj ilosc produktu" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout.width(27); cout << " "; cout << "  *****************************************************************" << endl;
	cout.width(27); cout << " "; cout << "  *                                                               *" << endl;
	cout.width(27); cout << " "; cout << "  *                     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "Ilosc produktu:                           "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout <<"*" << endl;
	cout.width(27); cout << " "; cout << "  *                                                               *" << endl;
	cout.width(27); cout << " "; cout << "  *****************************************************************" << endl; 
	double Ilosc;
	ustaw_kursor(67, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cin >> Ilosc;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	*ilosc = Ilosc;
		if ((b) == 1 || (b) == 2 || (b) == 3 || (b)== 7 || (b) ==8)
		{
			if ((c) == 4 || (c) == 5 || (c) == 6) {
				wynik = Ilosc * jaka_gestosc(a - 1) * tab[b - 1] / tab[c - 1];
			}
			else if ((c) == 1 || (c) == 2 || (c) == 3 || (c) == 7 || (c) == 8)
			{
				wynik = (Ilosc * tab[b - 1]) / tab[c - 1];
			}
		}
		else if ((b) == 4 || (b) == 5 || (b) == 6)
		{
			if ((c) == 1 || (c) == 2 || (c) == 3 || (c) == 7 || (c) == 8)
			{
				wynik = Ilosc * tab[b - 1] / jaka_gestosc(a - 1) / tab[c - 1];
			}
			else if ((c) == 4 || (c) == 5 || (c) == 6)
			{
				wynik = Ilosc * tab[b - 1] / tab[c - 1];
			}
		}
		return wynik;
}
void przelicznik_kulinarny::drukuj_wynik(int a, int b, int c, double wynik)
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	ustaw_kursor(58, 1); cout.width(68); cout << "WYNIK" << endl;
	ustaw_kursor(29, 3); cout.width(65); cout.fill('*'); cout << "*";
	ustaw_kursor(29, 4); cout.width(64); cout.fill(' '); cout  << ("* Przeliczales produkt: "  + tab_prod[a - 1]) <<  "* " << endl;
	ustaw_kursor(29, 5); cout.width(64); cout << ("* Przeliczales z wymiaru: " + wymiar[b - 1]) << "* " << endl;
	ustaw_kursor(29, 6); cout.width(64); cout << ("* Przeliczales do wymiaru: "+  wymiar[c - 1]) << "* " << endl;
	ustaw_kursor(29, 7); cout.width(64); cout << ("* Ilosc produktu: " +  to_string(ile)) << "* " << "\n\n";
	ustaw_kursor(29, 8); cout.width(64); cout <<  ("* Wynik: " + to_string(ile) +" " + wym_przez[b - 1] + " to " + to_string(wynik) + " " + wym_przez[c - 1]) << "* " << endl;
	ustaw_kursor(29, 9); cout.width(65); cout.fill('*'); cout << "*" << endl; cout.fill(' ');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	ustaw_kursor(43, 11); cout << "Nacisnij enter, aby przejsc dalej.";
	cin.get(); cin.get();
}
void przelicznik_kulinarny::ustaw_kursor(int x, int y)
{
	COORD c;
	c.X = x ;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}