#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>

using namespace std;

class HashTable {
public:
	HashTable(int size);		// Konstruktor
	~HashTable();				// Destruktor
	int insert(int item);		// f�gt ein Element der Hashtabelle hinzu
	int at(int i);				// Liefert das i-te Element der Hashtabelle zur�ck
	int getCollisionCount();    // Liefert die Anzahl der Kollisionen zur�ck
	int getSize();				// Liefert die Gr��e der Hashtabelle zur�ck
	int getElements();			// Liefert die Anzahl der Elemente der Hashtabelle zur�ck
private:
	int size;					// Gr��e der HashTable
	int elements;				// Anz. d. Elemente in HashTable
	int collisionCount;			// Anz. d. Kollisionen beim Einf�gen
	vector<int>* hashTable;		// HashTable
	int hashValue(int item);	// Hashindex berechnen
};


#endif 