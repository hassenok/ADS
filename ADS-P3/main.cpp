/*************************************************
 * ADS Praktikum 2.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:



/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV"

Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/
void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
        "importieren(j / n) ? >";
    cin >> j;
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
            cerr << "Fehler beim Lesen!" << endl;
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}
//
///////////////////////////////////////
int main()
{


    int result = Catch::Session().run();

    ///////////////////////////////////////
    // Ihr Code hier:
    Tree* myTree = new Tree();
    cout << "========================================" << endl;
    cout << "ADS-ELK-Stack v1.8, by Bhay Sanon" << endl;
    cout << "========================================" << endl; cout << endl;
    int eingabe = 0;
    while (true) {
        cout << "1) Datensatz einfuegen, manuell" << endl;
        cout << "2) Datensatz einfuegen, CSV Import" << endl;
        cout << "3) Suchen" << endl;
        cout << "4) Ausgabe in Preorder" << endl;
        cout << "5) Ausgabe in Levelorder" << endl;
        cout << "6) Ausgabe in Levelorder(mit Niveauauswahl) " << endl;
        cout << "7) Quit"<<endl;
        cin >> eingabe;

        if (eingabe == 1) {
            cout << "1) Datensatz einfuegen, manuell" << endl;
            int plz, alter;
            double einkommen;
            string sname;
            cout << "Name"; cin >> sname;
            cout << "Alter"; cin >> alter;
            cout << "Einkommen"; cin >> einkommen;
            cout << "PLZ"; cin >> plz;
            myTree->addNode(sname, alter, einkommen, plz);
            cout << "+ Ihr Datensatz wurde eingefügt" << endl;

        }
        else if (eingabe == 2) {
            mainscreen_addTreeCSV(myTree);
        }
        else if (eingabe == 3) {
            string s;
            cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
            cin >> s;
            myTree->searchNode(s);
        }
        else if (eingabe == 4) {
            
            myTree->printAll();
            cout << endl;


        }
        else if (eingabe == 5) {
            cout << "Ausgabe als Binäe Baum" << endl;
            myTree->printAll();
            cout << "Ausgabe in LevelOrder" << endl;
            myTree->printLevelOrder();
            cout << endl;
            cout << endl;
        }
        else if (eingabe == 6) {
            int niv;
            cout << "Bitte geben Sie das Niveau an ? ";
            cin >> niv;
            myTree->printLevelOrder(niv);
            cout << endl;
            cout << endl;

        }
        else if (eingabe == 7) {
            break;
        }


    }




    //
    ///////////////////////////////////////
    system("PAUSE");

    return 0;
}
