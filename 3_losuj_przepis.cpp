//
//  3_losuj_przepis.cpp
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
#include <fstream>
#include"Nag³ówek.h"
using namespace std;
void wewnetrzna()
{
	char wybor;
	do {
		cout << "Co chcesz teraz zrobic?\nA - losuj jeszcze raz\nM - wroc do menu\nE - wyjdz z programu\n";
		cout << "Wpisz A/M/E: ";
		cin >> wybor;
		if (wybor == 'A')
			losuj_przepis();
		else if (wybor == 'M')
			menu();
		else if (wybor == 'E')
			return;
		else
			cout << "Cos poszlo nie tak, sprobuj ponownie. ";
	} while (wybor != 'A' && wybor != 'M' && wybor != 'E');
}
void losuj_przepis()
{
	int nr_przepisu;
	srand(time(NULL));
	nr_przepisu = rand() % 5 + 1;
	cout << "Wyswietl numer przepisu: " << nr_przepisu << endl;
	fstream plik;
	string s;
	if (nr_przepisu == 1)
	{
		plik.open("Jablecznik.txt", ios::in);
		if (plik.is_open())
		{
			while (!plik.eof())
			{
				getline(plik, s);
				cout << s << endl;
			}
		}
		else
			cout << "Nie mozna otworzyc plik." << endl;
		plik.close();
	}
	else if (nr_przepisu == 2)
	{
		plik.open("Babka.txt", ios::in);
		if (plik.is_open()) {
			while (!plik.eof()) {
				getline(plik, s);
				cout << s << endl;
			}
		}
		else
			cout << "Nie mozna otworzyc plik." << endl;
		plik.close();
	}
	else if (nr_przepisu == 3)
	{
		plik.open("Murzynek.txt", ios::in);
		if (plik.is_open()) {
			while (!plik.eof()) {
				getline(plik, s);
				cout << s << endl;
			}
		}
		else
			cout << "Nie mozna otworzyc plik." << endl;
		plik.close();
	}
	else if (nr_przepisu == 4)
	{
		plik.open("Brownie.txt", ios::in);
		if (plik.is_open()) {
			while (!plik.eof()) {
				getline(plik, s);
				cout << s << endl;
			}
		}
		else
			cout << "Nie mozna otworzyc plik." << endl;
		plik.close();
	}
	else if (nr_przepisu == 5)
	{
		plik.open("Sernik.txt", ios::in);
		if (plik.is_open()) {
			while (!plik.eof()) {
				getline(plik, s);
				cout << s << endl;
			}
		}
		else
			cout << "Nie mozna otworzyc plik." << endl;
		plik.close();
	}
	char wybor;
	cout << "Czy chcesz zapisac przepis do pliku? " << endl << "Wpisz T/N: ";
	cin >> wybor;
	if (wybor == 'T')
	{
		ofstream plik1("Twoj_przepis.txt");
		plik1 << s; //poprawic!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		cout << "Wylosowany przepis zostal zapisany w pliku \"Twoj_przepis\"";
	}
		wewnetrzna();
}
