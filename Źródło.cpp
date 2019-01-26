//
//  Zrodlo.cpp
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
using piti = int;
int main()
{
	piti a = 3;
	piti b = ++a + + +a;
	cout << "b = " << b;
	system("pause");
	start();
	system("pause");
}
/*przel_foremek
funkcja licz¹ca objêtoœæ walca(dla tortownicy) , prostopad³oœcianu
najpierw podaæ foremki (z jakiej, do jakiej)
póŸniej iloœæ sk³adników
*/

void start()
{
	PlaySound("muzyka.wav", NULL, SND_ASYNC | SND_LOOP);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << " ___________________________________________________________________" << endl;
	cout << "|                      (o)          (o)                             |" << endl;
	cout << "|              (o)     ,|,          \\|,           (o)               |" << endl;
	cout << "|              ,|,     |~\\           |~\   (o)     ,|,               |" << endl;
	cout << "|              \\~|     \\ |   (o)     |`\\  ,|,     |~\\               |" << endl;
	cout << "|              |`\\     |`\\@@@,|,@@@@\ | @@@ ~|     \\ |               |" << endl;
	cout << "|              \\ | o@@@\\ |@@@\\~|@@@@|`\\@@@|`\\@@@o |`\\               |" << endl;
	cout << "|             o|`\\@@@@@|`\\@@@|`\\@@@@\\ |@@@\\ |@@@@@\\ |o              |" << endl;
	cout << "|           o@@\\ |@@@@@\  |@@@\\ |@@@@@@@@@@|`\\@@@@@|`\\@@o            |" << endl;
	cout << "|          @@@@|`\\@@@@@@@@@@@|`\\@@@@@@@@@@\\ |@@@@@\\ |@@@@           |" << endl;
	cout << "|          p@@@@@@@@@@@@@@@@@\\ |@@@@@@@@@@|`\\@@@@@@@@@@@q           |" << endl;
	cout << "|          @@o@@@@@@@@@@@@@@@|`\\@@@@@@@@@@@@@@@@@@@@@@o@@           |" << endl;
	cout << "|          @:@@@o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@o@@::@           |" << endl;
	cout << "|          ::@@::@@o@@@@@@@@@@@@@@@@@@@@@@@@@@@@o@@:@@::@           |" << endl;
	cout << "|          ::@@::@@@@::oo@@@@oo@@@@@ooo@@@@@o:::@@@::::::           |" << endl;
	cout << "|          %::::::@::::::@@@@:::@@@:::::@@@@:::::@@:::::%           |" << endl;
	cout << "|          %%::::::::::::@@::::::@:::::::@@::::::::::::%%           |" << endl;
	cout << "|          ::%%%::::::::::@::::::::::::::@::::::::::%%%::           |" << endl;
	cout << "|        .#::%::%%%%%%:::::::::::::::::::::::::%%%%%::%::#.         |" << endl;
	cout << "|      .###::::::%%:::%:%%%%%%%%%%%%%%%%%%%%%:%:::%%:::::###.       |" << endl;
	cout << "|    .#####::::::%:::::%%::::::%%%%:::::%%::::%::::::::::#####.     |" << endl;
	cout << "|   .######`:::::::::::%:::::::%:::::::::%::::%:::::::::'######.    |" << endl;
	cout << "|   .#########``::::::::::::::::::::::::::::::::::::''#########.    |" << endl;
	cout << "|   .#############``::::::::::::::::::::::::'''###############.'    |" << endl;
	cout << "|    `.######################################################.'     |" << endl;
	cout << "|      ` .##################################################. '     |" << endl;
	cout << "|___________________________________________________________________|" << endl;
	Sleep(3000);
	system("CLS");
	tytul();
}