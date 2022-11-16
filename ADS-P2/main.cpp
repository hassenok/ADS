/*************************************************
* ADS Praktikum 2.1
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;


int main()
{

	int result = Catch::Session().run();
	// Ihr Code hier:
	Ring test;
	while (true) {
		int zahl;
		cout << "==================================" << endl;
		cout << "SuperBackUp-Organizer over 9000, by HT" << endl;
		cout << "==================================" << endl;
		cout << "1) Backup anlegen" << endl;
		cout << "2) Backup suchen" << endl;
		cout << "3) Alle Backups ausgeben" << endl;
		cout << "?>";
		cin >> zahl;
		if (zahl == 1) {
			string s1, s2;
			cout << "+Neuen Datensatz anlegen " << endl;
			cout << "Beschreibung ?> ";
			cin >> s1;
			cout << "Data ?> ";
			cin >> s2;
			test.Ring::addNewNode(s1, s2);
			cout << "+Ihr Datensatz wurde hinzugefuegt." << endl;

		}
		else if (zahl == 2) {
			string s;
			cout << "+Nach welchen Daten soll gesucht werden? " << endl;
			cin >> s;
			test.Ring::search(s);
		}
		else if (zahl == 3) {
			test.Ring::print();
		}

	}



	//
	///////////////////////////////////////
	system("Pause");
	return 0;
}
