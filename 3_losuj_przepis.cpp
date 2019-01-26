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
#include<fstream>
#include"Nag³ówek.h"
using namespace std;
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
				plik >> s;
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
				plik >> s;
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
				plik >> s;
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
				plik >> s;
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
				plik >> s;
				cout << s << endl;
			}
		}
		else
			cout << "Nie mozna otworzyc plik." << endl;
		plik.close();
	}
}
