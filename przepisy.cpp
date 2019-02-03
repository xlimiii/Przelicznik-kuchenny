//
//  3_losuj_przepis.cpp
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#include<iostream>
#include <windows.h> 
#include <string>
#include <time.h>
#include <fstream>
#include"Nag³ówek.h"
#include"przelicznik_foremek.h"
#include"przepisy.h"
using namespace std;
przelicznik_foremek p;
constexpr int ile_przepisow = 10;
przepis szarlotka{ 10, "Szarlotka", nullptr }; 
przepis sernik_cyt{ 9, "Sernik cytrynowy", &szarlotka };
przepis sernik{ 8,"Sernik", &sernik_cyt };
przepis murzynek{ 7, "Murzynek", &sernik };
przepis marchewka{ 6, "Ciasto marchewkowe", &murzynek };
przepis country{ 5, "Ciasto Kinder Country", &marchewka };
przepis bounty{ 4, "Ciasto Bounty", &country };
przepis brownie{ 3, "Brownie", &bounty };
przepis bananowiec{ 2, "Bananowiec", &brownie };
przepis babka{ 1, "Babka", &bananowiec };
przepisy gotuj_z_limka{ &babka };
string tablica_z_nazwami[4][ile_przepisow] = { {"0","1","2","3","4","5", "6","7","8","9"}, {"Babka.txt", "Bananowiec.txt", "Brownie.txt", "Bounty.txt", "Country.txt", "Marchewka.txt", "Murzynek.txt", "Sernik.txt", "Sernik_cyt.txt", "Szarlotka.txt"},{"1","2","3","4","5","6", "7", "8","9","10"}, {"Przepis na babke","Przepis na pyszne ciasto bananowe","Przepis na brownie \"Czarna Magia\"", "Przepis na ciasto jak Bounty", "Przepis na ciasto jak Kinder Country", "Przepis na ciasto marchewkowe","Przepis na murzynka", "Przepis na sernik", "Przepis na sernik cytrynowy", "Przepis na szarlotke"}};
przepis tablica[ile_przepisow] = { babka, bananowiec, brownie, marchewka, murzynek, szarlotka };
void wybierz_przepis()
{
	int liczba;
	liczba = gotuj_z_limka.drukuj_liste();
	string s_nr_przepisu;
	string nazwa;
	s_nr_przepisu = to_string(liczba);
	for (int i = 0; i < ile_przepisow; i++)
	{
		if (s_nr_przepisu == tablica_z_nazwami[2][i])
		{
			nazwa = tablica_z_nazwami[1][i];
		}
	}
	tablica[liczba - 1].wyswietl_przepis(nazwa, liczba);
}
void wylosuj_przepis()
{
	system("cls");
	int nr_przepisu;
	srand(time(NULL));
	nr_przepisu = rand() % ile_przepisow + 1;  //losuje 0,1,2,3,4 albo 5
	cout << "Wylosowano liczbe: " << nr_przepisu;
	fstream plik;
	string s;
	string s_nr_przepisu;
	string nazwa;
	s_nr_przepisu = to_string(nr_przepisu);
	for (int i = 0; i < ile_przepisow; i++)
	{
		if (s_nr_przepisu == tablica_z_nazwami[0][i])
			nazwa = tablica_z_nazwami[1][i];
	}
	tablica[nr_przepisu - 1].wyswietl_przepis(nazwa, nr_przepisu);
}
void przepis::drukuj_nazwe()
{
	cout << numer << ". " << tytul << endl;
}
void przepis::wyswietl_przepis(string nazwa, int a)
{
	ifstream plik;
	string s;
	int gdzie;
	gdzie = gdzie_zaczac(nazwa, a);
	plik.open(nazwa.c_str(), ios::in);            //otwarcie pliku do oczytu
	if (plik.is_open()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << tablica_z_nazwami[3][a - 1] << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		plik.seekg(gdzie, ios::beg);
		while (!plik.eof()) {
			getline(plik, s);
			cout << s << endl;
		}
	}
	else
		cout << "Nie mozna otworzyc pliku." << endl;
	plik.close();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "Czy chcesz przeliczyc ten przepis na inna foremke? \nWpisz T/N: ";
	char wybor;
	cin >> wybor;
	wybor = toupper(wybor);
	if (wybor == 'T')
	{
		tablica[a - 1].sprawdz_ilosc_skladnikow(nazwa, a);
		tablica[a - 1].sprawdz_v1(nazwa, a);
		tablica[a - 1].przelicz(nazwa, a);
	}
		cout << "Wcisnij enter, aby kontynuowac.";
		cin.get(); cin.get();
		char kont;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		do {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(46, 1); cout << "Co chcesz teraz zrobic?" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		ustaw_kursor(44, 2); cout << "A - wroc do listy przepisow";
		ustaw_kursor(45, 3); cout << "M - wroc do menu glownego";
		ustaw_kursor(43, 4); cout << "E - zakoncz dzialanie programu";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(48, 5); cout << "Wpisz A, M lub E: ";
		cin >> kont;
		kont = toupper(kont);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		switch (kont)
		{
		case 'A': wybierz_przepis(); break;
		case 'M': menu(); break;
		case 'E': return; break;
		default: {
			cout << "Cos poszlo nie tak, sprobuj ponownie"; } break;
		}
	} while (kont != 'A' || kont != 'M' || kont != 'E');
}
int przepis::sprawdz_ilosc_skladnikow(std::string nazwa, int a)
{
	system("cls");
	int pozycja;
	ifstream plik;
	size_t pos{};
	string s{};
	plik.open(nazwa.c_str(), ios::in);
	if (plik.is_open())
	{
		while (getline(plik, s))
		{
			pos = s.find("skladnikow:");
			if (pos != string::npos)
			{
				pozycja = plik.tellg();
				plik.seekg(pozycja, ios::beg);
				plik >> s;
				p.ilosc_skladnikow = stoi(s);
				return p.ilosc_skladnikow;
			}
		}
	}
	else {
		cout << "Nie mozna otworzyc pliku. ";
		return p.ilosc_skladnikow;
	}
	plik.close();
}
double przepis::sprawdz_v1(std::string nazwa, int a)
{
	system("cls");
	ifstream plik;
	size_t pos{};
	string s{};
	plik.open(nazwa.c_str(), ios::in);
	if (plik.is_open())
	{
		plik >> s;
		if (s == "Tortownica:")
		{
			double srednica;
			plik >> s;
			srednica = stod(s);
			p.v1 = p.objetosck(srednica);
		}
		else if (s == "Blaszka:")
		{
			double a, b;
			plik >> s;
			a = stod(s);
			plik >> s;
			b = stod(s);
			p.v1 = p.objetoscp(a, b);
		}
	}
	plik.close();
	return p.v1;
}
void przepis::przelicz(std::string nazwa, int a)
{
	system("cls");
	p.wyb_formy2();
	ifstream plik;
	size_t pos;
	string s;
	int pozycja;
	plik.open(nazwa.c_str(), ios::in);
	if (plik.is_open())
	{
		while (getline(plik, s))
		{
			pos = s.find("Skladniki:");
			if (pos != string::npos)
			{
				pozycja = plik.tellg();
				plik.seekg(pozycja, ios::beg);
				string *Nazwy;
				Nazwy = new string[p.ilosc_skladnikow];
				double *Ilosci;
				Ilosci = new double[p.ilosc_skladnikow];
				string *Jednostka;
				Jednostka = new string[p.ilosc_skladnikow];
				for (int i = 0; i < p.ilosc_skladnikow; i++)
				{
					plik >> s;
					Nazwy[i] = s;
					plik >> s;
					Ilosci[i] = stod(s);
					plik >> s;
					Jednostka[i] = s;
				}
				p.Nazwy_w = Nazwy;
				p.Ilosci_w = Ilosci;
				p.Jednostki_w = Jednostka;
				p.przeliczone(p.Nazwy_w, p.Ilosci_w, p.Jednostki_w);
				delete[] Jednostka;
				delete[] Ilosci;
				delete[] Nazwy;
			}
		}
	}
	plik.close();
}
int przepis::gdzie_zaczac(std::string nazwa, int a)
{
	system("cls");
	int pozycja;
	ifstream plik;
	size_t pos{};
	string s{};
	plik.open(nazwa.c_str(), ios::in);
	if (plik.is_open())
	{
		while (getline(plik, s))
		{
			pos = s.find("XXX");
			if (pos != string::npos)
			{
				pozycja = plik.tellg();
				return pozycja;
			}
		}
		plik.close();
	}
	else
	{
		cout << "Nie mozna otworzyc pliku.";
		return 0;
	}
}
int przepisy::drukuj_liste()
{
	int liczba;
	do {
		system("cls");
		for (int i = 12; i <= 12 + ile_przepisow; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			ustaw_kursor(22, 1); cout << "                                                  ,,                     " << endl;
			ustaw_kursor(22, 2); cout << "`7MM\"\"\"Mq..                                       db                     " << endl;
			ustaw_kursor(22, 3); cout << "  MM   `MM.                                                              " << endl;
			ustaw_kursor(22, 4); cout << "  MM   ,M9 `7Mb,od8 M\"\"\"MMV.  gP\"Ya  `7MMpdMAo. `7MM  ,pP\"Ybd `7M'   `MF'" << endl;
			ustaw_kursor(22, 5); cout << "  MMmmdM9    MM' \"\' \'  AMV  ,M\'   Yb   MM   `Wb   MM  8I   `\"   VA   ,V  " << endl;
			ustaw_kursor(22, 6); cout << "  MM         MM       AMV   8M\"\"\"\"\"\"   MM    M8   MM  `YMMMa.    VA ,V   " << endl;
			ustaw_kursor(22, 7); cout << "  MM         MM      AMV  , YM.    ,   MM   ,AP   MM  L.   I8     VVV    " << endl;
			ustaw_kursor(22, 8); cout << ".JMML.     .JMML.   AMMmmmM  `Mbmmd'   MMbmmd'  .JMML.M9mmmP'     ,V     " << endl;
			ustaw_kursor(22, 9); cout << "                                       MM                        ,V      " << endl;
			ustaw_kursor(22, 10); cout << "                                     .JMML.                   OOb\"     " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			ustaw_kursor(18, 11); cout.width(79); cout.fill('*'); cout << "*";
			ustaw_kursor(18, i); cout << "*";
			ustaw_kursor(96, i); cout << "*";
			ustaw_kursor(18, 13 + ile_przepisow); cout.width(79); cout.fill('*'); cout << "*"; cout.fill(' ');
		}
		przepis* biezacy = pierwszy;
		int n = 12;
		while (biezacy)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			ustaw_kursor(20, n);
			biezacy->drukuj_nazwe();
			biezacy = biezacy->kolejny;
			n++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		ustaw_kursor(18, 14 + ile_przepisow); cout << "Ktory przepis chcesz wyswietlic? Wpisz odpowiednia liczbe: ";
		cin >> liczba;
	} while (liczba > ile_przepisow);
	return liczba;
}