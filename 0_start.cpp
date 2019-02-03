//
//  0_start.cpp
//  "Gotuj z Limk¹"
//
//  Created by Dominika Limanowka on 23/01/2019.
//  Copyright © 2019 Dominika Limanowka. All rights reserved.
#include<iostream>
#include <windows.h> //SETCONSOLE-KOLOR
#include"Nag³ówek.h"
#include"przelicznik_foremek.h"
#include"przelicznik_kulinarny.h"
#include"przepisy.h"
using namespace std;
void start()
{
	PlaySound("muzyka.wav", NULL, SND_ASYNC | SND_LOOP);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout.width(23); cout << " ";
	cout << "    ___________________________________________________________________" << endl;
	cout.width(23); cout << " ";
	cout << "   |                      (o)          (o)                             |" << endl; //67
	cout.width(23); cout << " ";
	cout << "   |              (o)     ,|,          \\|,           (o)               |" << endl;
	cout.width(23); cout << " ";
	cout << "   |              ,|,     |~\\           |~\   (o)     ,|,               |" << endl;
	cout.width(23); cout << " ";
	cout << "   |              \\~|     \\ |   (o)     |`\\  ,|,     |~\\               |" << endl;
	cout.width(23); cout << " ";
	cout << "   |              |`\\     |`\\@@@,|,@@@@\ | @@@ ~|     \\ |               |" << endl;
	cout.width(23); cout << " ";
	cout << "   |              \\ | o@@@\\ |@@@\\~|@@@@|`\\@@@|`\\@@@o |`\\               |" << endl;
	cout.width(23); cout << " ";
	cout << "   |             o|`\\@@@@@|`\\@@@|`\\@@@@\\ |@@@\\ |@@@@@\\ |o              |" << endl;
	cout.width(23); cout << " ";
	cout << "   |           o@@\\ |@@@@@\  |@@@\\ |@@@@@@@@@@|`\\@@@@@|`\\@@o            |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          @@@@|`\\@@@@@@@@@@@|`\\@@@@@@@@@@\\ |@@@@@\\ |@@@@           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          p@@@@@@@@@@@@@@@@@\\ |@@@@@@@@@@|`\\@@@@@@@@@@@q           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          @@o@@@@@@@@@@@@@@@|`\\@@@@@@@@@@@@@@@@@@@@@@o@@           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          @:@@@o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@o@@::@           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          ::@@::@@o@@@@@@@@@@@@@@@@@@@@@@@@@@@@o@@:@@::@           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          ::@@::@@@@::oo@@@@oo@@@@@ooo@@@@@o:::@@@::::::           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          %::::::@::::::@@@@:::@@@:::::@@@@:::::@@:::::%           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          %%::::::::::::@@::::::@:::::::@@::::::::::::%%           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |          ::%%%::::::::::@::::::::::::::@::::::::::%%%::           |" << endl;
	cout.width(23); cout << " ";
	cout << "   |        .#::%::%%%%%%:::::::::::::::::::::::::%%%%%::%::#.         |" << endl;
	cout.width(23); cout << " ";
	cout << "   |      .###::::::%%:::%:%%%%%%%%%%%%%%%%%%%%%:%:::%%:::::###.       |" << endl;
	cout.width(23); cout << " ";
	cout << "   |    .#####::::::%:::::%%::::::%%%%:::::%%::::%::::::::::#####.     |" << endl;
	cout.width(23); cout << " ";
	cout << "   |   .######`:::::::::::%:::::::%:::::::::%::::%:::::::::'######.    |" << endl;
	cout.width(23); cout << " ";
	cout << "   |   .#########``::::::::::::::::::::::::::::::::::::''#########.    |" << endl;
	cout.width(23); cout << " ";
	cout << "   |   .#############``::::::::::::::::::::::::'''###############.'    |" << endl;
	cout.width(23); cout << " ";
	cout << "   |    `.######################################################.'     |" << endl;
	cout.width(23); cout << " ";
	cout << "   |      ` .##################################################. '     |" << endl;
	cout.width(23); cout << " ";
	cout << "   |___________________________________________________________________|" << endl;
	cout.width(23); cout << " ";
	Sleep(3000);
	system("CLS");
	tytul();
}
void tytul()
{
	cout << endl;
	cout.width(23); cout << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "**********************************************************************" << endl;
	cout.width(23); cout << " "; cout << "*            "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << ".g8```bgd              mm                   db       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "   *" << endl;
	cout.width(23); cout << " "; cout << "*          "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << ".dP'     `M              MM                             "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*          "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "dM'       `   ,pW`Wq.  mmMMmm  `7MM  `7MM   `7MM        "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*          ";  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "MM           6W'   `Wb   MM      MM    MM     MM       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);cout << "   *" << endl;
	cout.width(23); cout << " "; cout << "*          "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "MM.    `7MMF'8M     M8   MM      MM    MM     MM        "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*          "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "`Mb.     MM  YA.   ,A9   MM      MM    MM     MM       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);cout<< "   *" << endl;
	cout.width(23); cout << " "; cout << "*            "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "``bmmmdPY   `Ybmd9'    `Mbmo   `Mbod`YML.   MM        "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*               "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "                                      QO MP        "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*                "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "                                    `bmP          "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*                "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "               M```MMV                            "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*                ";  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "               '  AMV                              "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << " *" << endl;
	cout.width(23); cout << " "; cout << "*                  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "               AMV                            "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "    *" << endl;
	cout.width(23); cout << " "; cout << "*                 ";  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "               AMV  ,                          "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "    *" << endl;
	cout.width(23); cout << " "; cout << "*                  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "             AMMmmmM                         "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "     *" << endl;
	cout.width(23); cout << " "; cout << "*                                                                    *" << endl;
	cout.width(23); cout << " "; cout << "* "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "   `7MMF'      `7MMF'`7MMM.     ,MMF'`7MMF' `YMM'       db     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "    *" << endl;
	cout.width(23); cout << " "; cout << "*  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "    MM          MM    MMMb    dPMM    MM   .M'        ;MM:      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "* "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "     MM          MM    M YM   ,M MM    MM .d`,         V^MM.     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "* "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "     MM          MM    M  Mb  M' MM    MMMMM.        ,M  `MM     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "    MM      ,   MM    M  YM.P'  MM    MM  VMA       AbmmmqMA    "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "*  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "    MM     ,M   MM    M  `YM'   MM    MM   `MM.    A'     VML   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << "  *" << endl;
	cout.width(23); cout << " "; cout << "* "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "   .JMMmmmmMMM .JMML..JML. `'  .JMML..JMML.   MMb..AMA.   .AMMA.  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << " *" << endl;
	cout.width(23); cout << " "; cout << "*  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "                                                           aA.   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << " *" << endl;
	cout.width(23); cout << " "; cout << "*  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "                                                           aA.   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); cout << " *" << endl;
	cout.width(23); cout << " "; cout << "**********************************************************************";
	Sleep(5000);
	menu();
}
void menu()
{
	system("CLS");
	instrukcja();
	int wybor;
	do {
		przelicznik_foremek x;
		przelicznik_kulinarny y;
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout.width(34); cout << " "; cout <<" `7MMM.     ,MMF'                                 " << endl;
		cout.width(34); cout << " "; cout <<"   MMMb    dPMM                                   " << endl;
		cout.width(34); cout << " "; cout <<"   M YM   ,M MM   .gP`Ya  `7MMpMMMb.  `7MM  `7MM  " << endl;
		cout.width(34); cout << " "; cout <<"   M  Mb  M' MM  ,M'   Yb   MM    MM    MM    MM  " << endl;
		cout.width(34); cout << " "; cout <<"   M  YM.P'  MM  8M`MMMM    MM    MM    MM    MM  " << endl;
		cout.width(34); cout << " "; cout <<"   M  `YM'   MM  YM.    ,   MM    MM    MM    MM  " << endl;
		cout.width(34); cout << " "; cout <<" .JML. `'  .JMML. `Mbmmd' .JMML  JMML.  `Mbod`YML." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout.width(21); cout << " "; cout << "****************************************************************************" << endl;
		cout.width(21); cout << " "; cout << "*                                                                          *" << endl;
		cout.width(21); cout << " "; cout << "*                         1. Przelicznik kulinarny                         *" << endl;
		cout.width(21); cout << " "; cout << "*                          2. Przelicznik foremek                          *" << endl;
		cout.width(21); cout << " "; cout << "*                           3. Przepisy na ciasta                          *" << endl;
		cout.width(21); cout << " "; cout << "*                            4. Wylosuj przepis                            *" << endl;
		cout.width(21); cout << " "; cout << "*                                                                          *" << endl;
		cout.width(21); cout << " "; cout << "****************************************************************************" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout.width(21); cout << " "; cout << "Wpisz cyfre: ";
		cin >> wybor;
		switch (wybor)
		{
		case 1: y.przel_kulinarny(); break;
		case 2: x.przel_foremek(); break;
		case 3: wybierz_przepis(); break;
		case 4: wylosuj_przepis(); break;
		default: {cout.width(21); cout << " "; cout << "Cos poszlo nie tak... Sprobuj ponownie" << endl; Sleep(1500); } break;
		}
	} while (wybor != 1 &&  wybor != 3 && wybor !=2);
}
void instrukcja()
{
	cout.width(50); cout << " ";
	cout << "INSTRUKCJA" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "     *************************************************************************************************************" << endl;
	cout << "     *                                                                                                           *" << endl;
	cout << "     *        Ten program ma celu ulatwic zycie podczas codziennych i niecodziennych kuchennych podbojow.        *" << endl;
	cout << "     *    Jezeli kiedykolwiek zastanawiales sie \"Ile lyzek to 100 gram maki?\" - ten program jest dla Ciebie.     *" << endl;
	cout << "     *  Jezeli kiedykolwiek chciales upiec tort majac do dyspozycji tylko blaszke - ten program jest dla Ciebie. *" << endl;
	cout << "     *           Jezeli masz ochote upiec ciasto, lecz nie wiesz jakie - ten program jest dla Ciebie.            *" << endl;
	cout << "     *                                                                                                           *" << endl;
	cout << "     *************************************************************************************************************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "     Wcisnij enter, aby przejsc dalej.                                                                         " << endl;
	cin.get();
}