/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

Ring::Ring()
{
    anker = nullptr;
}

// Ihr Code hier:


void Ring::addNewNode(std::string s1, std::string s2) {
    RingNode* neu = new RingNode;
    neu->setDescription(s1);
    neu->setData(s2);
    neu->setAge(0);
    if (anker == 0) {
        anker=neu;
        anker->setNext(anker);
    }
    
    
    else if(countNodes<6){
        RingNode* ptr = anker;
        while (ptr->getNext() != anker)
        {
            ptr->setAge(ptr->getAge() + 1);//die Liste durch laufen und Age incrementieren
            ptr=ptr->getNext();
           
        }
        ptr->setAge(ptr->getAge() + 1);
        neu->setNext(anker->getNext());
        anker->setNext (neu);
        anker = neu;
    }
    
    else {
        
        RingNode* ptr = anker;
        while (ptr->getNext() != anker)
        {
            ptr->setAge(ptr->getAge() + 1);
            ptr = (ptr->getNext());

        }
        ptr->setAge(ptr->getAge() + 1);

        neu->setNext(anker->getNext()->getNext());
        delete anker->getNext();
        anker->setNext(neu);
        anker = neu;
        countNodes--; // Groesse anpassen
       
        
       
    }
    countNodes++;

};
bool Ring:: search(std::string s) {
    RingNode* ptr = anker;
    if (anker == 0) {// Ring ist leer
        std::cout << "+ Datensatz konnte nicht gefunden werden." << std::endl;
        return false;
    }
    
    do {
        if (ptr->getData() == s) {
            std::cout<<" Alter: " << ptr->getAge() << ", Beschreibung : " << ptr->getDescription() << ", Daten : " << ptr->getData()<<std::endl;
            return true;// Ausgabe und Ruas falls gefunden
        }
        ptr=(ptr->getNext());
       
        
    } while (ptr != anker);
    std::cout << "+ Datensatz konnte nicht gefunden werden." << std::endl;
    return false;
};
void Ring::print() {
    RingNode* ptr=anker;
    if (anker == 0) //Ring ist leer
        std::cout << "liste ist leer" << std::endl;
    else {// die Liste durchlaufen und die Daten ausgeben
        while (ptr->getNext() != anker) {
            std::cout << " Alter: " << ptr->getAge() << ", Beschreibung: " << ptr->getDescription() << " , Daten: " << ptr->getData() << std::endl;
            ptr = (ptr->getNext());

        }
        std::cout << " Alter: " << ptr->getAge() << ", Beschreibung: " << ptr->getDescription() << " , Daten: " << ptr->getData() << std::endl;
        

    }

};
//
////////////////////////////////////
