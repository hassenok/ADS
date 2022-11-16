#pragma once
#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
//#include "catch.hpp"
#include <iostream>
#include <string>
template <typename T>
class List
{
    /*
    Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse
    List kann ein Stapel oder Warteschlange realisiert werden.
    */
private:
    struct form
    {
        std::string start = "<< ";
        std::string zwischen = ", ";
        std::string ende = " >>\n";
    } list_form;
    Node<T>* head_tail; // Zeiger auf Kopf- und End-Element -> next der 1. Knoten;
                     // -> prev der letzte Knoten
    int  list_size;  // Länge der Kette
    bool temp; // normalerweise false; ist true, wenn es sich um eine temor�re
               // Liste handelt die innerhalb der überladenen Operatoren
               // angelegt wird
public:
    List() {
        // Konstruktor für eine leere Liste
        head_tail = new Node<T>;
        list_size = 0;
        temp = false;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    List(const List<T>& _List) {

        // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
        // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
        // sollen.
        list_form = _List.list_form;
        head_tail = new Node<T>;
        list_size = 0;
        temp = _List.temp;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
        Node<T>* tmp_node;
        tmp_node = _List.head_tail->next;
        while (tmp_node != _List.head_tail)
        {
            head_tail->prev =
                new Node<T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
            head_tail->prev->prev->next = head_tail->prev;
            list_size++;
            tmp_node = tmp_node->next;
        }
        if (_List.temp)
            delete& _List; // ist die übergebene Liste eine temporäre Liste? -> aus
                           // Operator +};
    }

    ~List() {

        // Dekonstruktor
        // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht
        // wird.
        Node<T>* tmp = head_tail->next;
        while (tmp != head_tail)
        {
            tmp = tmp->next;
            delete tmp->prev;
        }
        delete head_tail;


    }

    void insertFront(T key) {
        // Einfuegen eines neuen Knotens am Anfang der Liste
    /*
        Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einfügen
    */
        if (head_tail->next == head_tail)
        {
            Node<T>* n1 = new Node<T>(key, head_tail, this->head_tail);
            head_tail->next = n1;
            head_tail->prev = n1;
            list_size++;
        }
        else {
            Node<T>* n1 = new Node<T>(key, head_tail->next, this->head_tail);
            head_tail->next->prev = n1;
            head_tail->next = n1;
            list_size++;
        }
    }    // Einfügen eines Knotens am Anfang
    void insertFront(List<T>& _List) {
        // Einfuegen der Liste _List am Anfang an einer vorhandenen Liste 
        /*
        Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
        Die einzufuegende Liste _List ist anschließend leer.
        Es darf keine Schleife und kein new benutzt werden.
        */
        if (head_tail == _List.head_tail) return;// gleiches Objekt -> keine Aktion
     //   list_size += _List.list_size;
     //   Node* tmp = head_tail->next;
     //   _List.head_tail->next->prev = head_tail;
     //   head_tail->next = _List.head_tail->next;
     //   //head_tail->next->prev = head_tail;
     //   tmp->prev = head_tail->prev;
     //   _List.head_tail->prev->next = tmp;

     //  
     //   _List.list_size = 0;
     //   _List.head_tail->next = _List.head_tail;// HT auf sich selbst setzen
     //   //_List.head_tail->prev = _List.head_tail;
        list_size += _List.list_size;//Größe der Liste aktualisieren
        head_tail->next->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = head_tail->next;
        head_tail->next = _List.head_tail->next;
        _List.head_tail->next->prev = head_tail;
        _List.head_tail->prev = _List.head_tail;//_List wird nicht mehr benutzt
        _List.head_tail->next = _List.head_tail;
        _List.list_size = 0;




        /*
            Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
            Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
            Die Liste _List ist danach leer, aber vorhanden.
        */
    } // Einfügen einer vorhandenen Liste am Anfang
    void insertBack(T key) {
        // Einfuegen eines neuen Knotens am Ende der Liste
    /*
        Einen neuen Knoten mit dem Wert value wird am Ende der Liste einfügen
    */if (head_tail->next == head_tail)
    {
        Node<T>* n2 = new Node<T>(key, head_tail, head_tail);
        head_tail->prev = n2;
        head_tail->next = n2;
        list_size++;
    }
    else {
        Node<T>* n2 = new Node<T>(key, head_tail, head_tail->prev);
        head_tail->prev = n2;
        head_tail->prev->prev->next = n2;
        list_size++;
    }

    }      // Einfügen eines Knotesn am Ende
    void insertBack(List<T>& _List) {
        // Einfuegen der Liste _List am Ende einer vorhandenen Liste
        /*
        Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
        Die einzufuegende Liste _List ist anschließend leer.
        Es darf keine Schleife und kein new benutzt werden.
        */
        if (head_tail == _List.head_tail) return;
        // list_size += _List.list_size;// gleiches Objekt -> keine Aktion

        // head_tail->prev->next = _List.head_tail->next;
        // _List.head_tail->next->prev = head_tail->prev;
        // _List.head_tail->prev->next = head_tail;
        // head_tail->prev = _List.head_tail->prev;
        //
        // _List.list_size = 0;
        // _List.head_tail->next = _List.head_tail;// HT auf sich selbst setzen
        //// _List.head_tail->prev = _List.head_tail;
        list_size += _List.list_size;//Größe der Liste aktualisieren
        head_tail->prev->next = _List.head_tail->next;
        _List.head_tail->next->prev = head_tail->prev;
        head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = head_tail;
        _List.head_tail->prev = _List.head_tail;//_List wird nicht mehr benutzt
        _List.head_tail->next = _List.head_tail;
        _List.list_size = 0;





        /*
            Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
            Diese Knoten (koplette Kette) werden an den Ende der Liste (this) übertragen ohne sie zu kopieren!
            Die Liste _List ist danach leer, aber vorhanden.
        */
    }
    // Einfügen einer vorhandenen Liste am Ende
    bool getFront(T& key) {
        // entnehmen des Knotens am Anfang der Liste
        // der Wert wird als Parameter zurueckgegeben
        // der Knoten wird entnommen
        // im Fehlerfall wird false zurückgegeben
        if (!list_size) return false;	// leere Liste -> kein Wert
        /*
            Der Wert des vorderen Knotens wird rückgegeben und der Knoten gelöscht.
            Die Methode del(key) darf nicht zum löschen benutzt werden.
        */
        Node<T>* temp = head_tail->next;
        key = head_tail->next->key;//Zurückgeben
        head_tail->next = head_tail->next->next;
        head_tail->next->prev = head_tail;

        delete temp;
        list_size--;
        return true;
        //key = head_tail->next->key;//Zurückgeben
        //head_tail->next = head_tail->next->next;
        //delete(head_tail->next->prev);//Löschen
        //head_tail->next->prev = head_tail;

        //list_size--;
        //return true;
    }
    // Entnehmen eines Knoten am Anfang
    bool getBack(T& key) { // entnehmen des Knotens am Ende der Liste
    // der Wert wird als Parameter zurueckgegeben
    // der Knoten wird entnommen
    // im Fehlerfall wird false zurückgegeben
        if (!list_size) return false;	// leere Liste -> kein Wert
        /*
            Der Wert des letzten Knotens wird rückgegeben und der Knoten gelöscht.
            Die Methode del(key) darf nicht zum löschen benutzt werden.
        */
        Node<T>* temp = head_tail->prev;
        key = head_tail->prev->key;//Zurückgeben
        head_tail->prev = head_tail->prev->prev;
        head_tail->prev->next = head_tail;
        delete temp;
        list_size--;
        return true;
        //key = head_tail->prev->key;//Zurückgeben
        //head_tail->prev = head_tail->prev->prev;
        //delete(head_tail->prev->next);//Löschen
        //head_tail->prev->next = head_tail;

        //list_size--;//Die Listgröße um 1 vermindern
        //return true;
    }
    // Entnehmen eines Knoten am Ende
    bool del(T key) {
        // Loeschen eines gegebenen Knotens
        // im Fehlerfall wird false zurückgegeben
        if (!list_size) return false; // leere Liste -> keine Aktion
    /*
        Löschen des Knotens mit dem Wert value
    */

        if (head_tail->next == head_tail->prev) //Ein einziges Element

        {
            delete head_tail->next;
            list_size--;
            return true;
        }
        else
        {
            Node<T>* ptr = head_tail->next;
            while (ptr != head_tail) {//die Liste durchlaufen
                if (ptr->key == key) {//zu lösende Knoten merken
                    ptr->next->prev = ptr->prev;
                    ptr->prev->next = ptr->next;
                    delete ptr;// Löschen
                    list_size--;// Listgröße anpassen
                    return true;
                }
                ptr = ptr->next;
            }
            return false;//die ganze liste ist durch gelaufen und die knoten ist Nicht gefunden
        }
    }             // löschen eines Knotens [key]
    bool search(T key) {
        // suchen eines Knotens
        // nicht gefunden -> Rueckgabe: false
        if (!list_size) return false; // leere Liste -> keine Aktion
        /*Node* ptr = head_tail;
        while (ptr->next != head_tail && ptr->next->key != key)
            ptr = ptr->next;
        if (ptr->next == head_tail && ptr->next->key != key)
            return false;
        else
            return true;*/
        Node<T>* ptr = head_tail->next;
        while (ptr/*->next*/ != head_tail) {//Kreis
            if (ptr->key == key) {//Gefunden
                return true;
            }
            ptr = ptr->next;
        }
        return false;//Nicht gefunden





    /*
        suchen ob ein Knoten mit dem Wert value existiert.
    */
    }
    // Suchen eines Knoten
    bool swap(T key1, T key2) {
        // Vertauschen von zwei Knoten
        // Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.
        // im Fehlerfall wird false zurueckgegeben
        if (list_size < 2) return false; // leere oder einer Liste -> keine Aktion
    /*
        Vertauschen von zwei Knoten mit dem Wert value1 und dem Wert value2.
        Es duerfen nicht nur einfach die Werte in den Knoten getauscht werden!
        Die Knoten sind in der Kette umzuhaengen.
    */
        Node<T>* ptr1 = head_tail->next;
        while (ptr1->key != key1)
            ptr1 = ptr1->next;// erste 
       // Node* tmp1 = ptr1;

        Node<T>* ptr2 = head_tail->next;
        while (ptr2->key != key2)
            ptr2 = ptr2->next;
        //Node* tmp2 = ptr2;
        Node<T>* neu = new Node<T>;// new Node erstellen um die koordination von ptr2 zu bewahren
        neu->next = ptr2->next;
        ptr2->next->prev = neu;
        neu->prev = ptr2->prev;
        ptr2->prev->next = neu;
        //knoten 2 zu knoten 1 tauschen
        ptr2->next = ptr1->next;
        ptr1->next->prev = ptr2;
        ptr2->prev = ptr1->prev;
        ptr1->prev->next = ptr2;

        //Knoten 1 zu neu tauschen
        ptr1->next = neu->next;
        neu->next->prev = ptr1;
        ptr1->prev = neu->prev;
        neu->prev->next = ptr1;
        delete neu;//neu löschen 
        return true;




    }
    // Knoten in der Liste vertauschen
    int  size(void) {
        // Rueckgabe der Anzahl der Knoten in der Liste mit O(1)
    /*
        Anzahl der Knoten in der Liste zurückgeben.
    */
    //int k = 0;
    //Node* ptr = head_tail;
    //while (ptr->next != head_tail) {
    //    ptr = ptr->next;
    //    k++;
    //}
    //return k;	// Hier richtiges Ergebnis zurückgeben
        return list_size;
        return 0;
    }
    // Größe der Lise (Anzahl der Knoten)
    bool test(void) {
        // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und
        // zurück Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
        // der Knoten überein liefert die Methode true
        Node<T>* tmp = head_tail->next;
        int   i_next = 0, i_prev = 0;
        while (tmp != head_tail)
        {
            tmp = tmp->next;
            if (i_next > list_size)
                return false;
            i_next++;
        }
        if (i_next != list_size)
            return false;
        tmp = head_tail->prev;
        while (tmp != head_tail)
        {
            tmp = tmp->prev;
            if (i_prev > list_size)
                return false;
            i_prev++;
        }
        return i_prev == i_next;
    }               // Überprüfen der Zeigerstruktur der Liste
    void format(const std::string& start,
        const std::string& zwischen,
        const std::string& ende) {
        // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
        // das Format wird für den überladenen Operator << verwendet
        list_form.start = start;
        list_form.zwischen = zwischen;
        list_form.ende = ende;
    }

    // Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
    // start: stirng vor der Ausgabe der Liste
    // zwischen: string zwischen Listenknoten
    // ende: string am Ende der Liste
    List& operator=(const List<T>& _List) {
        // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
        // sollen. Kopiert wird in das Objekt "this"
        if (this == &_List)
            return *this; //  !! keine Aktion notwendig
        list_form = _List.list_form;
        Node<T>* tmp_node;
        if (list_size)
        {
            Node<T>* tmp_del;
            tmp_node = head_tail->next;
            while (tmp_node !=
                head_tail) // Alle eventuell vorhandenen Knoten in this löschen
            {
                tmp_del = tmp_node;
                tmp_node = tmp_node->next;
                delete tmp_del;
            }
            list_size = 0;
            head_tail->next = head_tail;
            head_tail->prev = head_tail;
        }
        tmp_node = _List.head_tail->next; // Die Listen-Knotenwerte werden kopiert
        while (tmp_node != _List.head_tail)
        {
            insertBack(tmp_node->key);
            tmp_node = tmp_node->next;
        }
        if (_List.temp)
            delete& _List; // ist die übergebene Liste eine temporäre Liste? -> aus
                           // Operator +
        return *this;
    } // Zuweisungsoperator definieren
    List&
        operator+(const List<T>& List_Append) {
        // Die Methode +
        // Es werden zwei Listen aneinander gehangen.
        // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue
        // Ergebnisliste.
        Node<T>* tmp_node;
        List<T>* tmp;
        if (temp)
        { // this ist eine temporäre Liste und kann verändert werden
            tmp = this;
        }
        else
        {
            tmp =
                new List<T>(*this); // this ist keine temporäre Liste -> Kopie erzeugen
            tmp->temp = true;    // Merker setzten, dass es sich um eine temporäre
                                 // Liste handelt
        }
        if (List_Append.list_size)
        { // anhängen der übergebenen Liste an tmp
            tmp_node = List_Append.head_tail->next;
            while (tmp_node != List_Append.head_tail)
            {
                tmp->insertBack(tmp_node->key);
                tmp_node = tmp_node->next;
            }
        }
        if (List_Append.temp)
            delete& List_Append; // wurde eine temporäre Liste übergeben, dann wird
                                 // diese gelöscht
        return *tmp;
    } // Listen zusammenführen zu einer Liste
    friend std::ostream&
        operator<<(std::ostream& stream,
            List<T> const& Liste) {
        // Ausgabe der Liste mit cout
        stream << Liste.list_form.start;
        for (Node<T>* tmp = Liste.head_tail->next; tmp != Liste.head_tail;
            tmp = tmp->next)
            stream << tmp->key
            << (tmp->next == Liste.head_tail ? Liste.list_form.ende :
                Liste.list_form.zwischen);
        if (Liste.temp)
            delete& Liste; // wurde eine temporäre Liste übergeben, dann wird diese
                           // gelöscht
        return stream;
    } // Ausgabeoperator überladen
    friend Node<T>* get_anker(List<T>& l);
    friend int   get_AnzahlNodes(List<T>& l);
};
//template <typename Tf>
//friend std::ostream& operator << (std::ostream& stream, const List<Tf>& Liste);
#endif