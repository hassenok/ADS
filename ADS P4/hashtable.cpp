#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {

	//*****************************
	// implement constructor here *
	//*****************************
	
	hashTable = new vector<int>(size);
	for (int i = 0; i < size; i++) {
		hashTable->at(i) = -1;
	}
	this->size = size;
	elements = 0, collisionCount = 0;

}

HashTable::~HashTable()
{
	//****************************
	// implement destructor here *
	//****************************
	
		delete hashTable;
	
}

int HashTable::hashValue(int item) {

	

	//******************************************
	// implement calculation of hashindex here *
	//******************************************
	int i = 0;
	
	int index = (item + i * i) % this->getSize(); //GUTE initializtation
	while (true)
	{
		if (hashTable->at(index) == -1) 
			break;
		else {
			i++;
			index = ((item + i * i) % this->getSize());

			collisionCount++;// Kollision erkannt
			
		}
	}
	return index;
}

int HashTable::insert(int item) {

	//******************************************
	// implement insertion of new element here *
	//******************************************
	int index = hashValue(item);
	hashTable->at(index) = item;
	elements++;

	return elements; //dummy return
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
