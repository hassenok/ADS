#include "List.h"

List::List()
{
    // Konstruktor für eine leere Liste
    head_tail       = new Node;
    list_size       = 0;
    temp            = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

List::List(const List& _List)
{
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen.
    list_form       = _List.list_form;
    head_tail       = new Node;
    list_size       = 0;
    temp            = _List.temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node* tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail)
    {
        head_tail->prev =
            new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List.temp)
        delete &_List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
}

List::~List()
{
    // Dekonstruktor
    // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht
    // wird.
    Node* tmp = head_tail->next;
    while (tmp != head_tail)
    {
        tmp = tmp->next;
        delete tmp->prev;
    }
    delete head_tail;
}


void List::insertFront(int key)
{
	// Einfuegen eines neuen Knotens am Anfang der Liste
/*
	Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einfügen
*/
    
        
        Node* n1 = new Node(key, head_tail->next, head_tail);// neuer Knoten erzeugen und initialisieren
        // head_tail anpassen:
        head_tail->next->prev = n1;
        head_tail->next = n1;
        list_size++;
    
}

void List::insertFront(List& _List)
{
	// Einfuegen der Liste _List am Anfang an einer vorhandenen Liste 
	/*	
	Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
	Die einzufuegende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden. 
	*/
	if (head_tail == _List.head_tail) return;// gleiches Objekt -> keine Aktion
    list_size += _List.list_size;//zuesrt list groesse anpassen
    Node* tmp = head_tail->next;
    _List.head_tail->next->prev = head_tail;
    head_tail->next = _List.head_tail->next;
    tmp->prev = head_tail->prev;
    _List.head_tail->prev->next = tmp;

   
    _List.list_size = 0;
    _List.head_tail->next = _List.head_tail;// HT auf sich selbst setzen
   

      
       
    
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	Die Liste _List ist danach leer, aber vorhanden.
*/
}

void List::insertBack(int key)
{
	// Einfuegen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Wert value wird am Ende der Liste einfügen
*/

    Node* n2 = new Node(key, head_tail, head_tail->prev);// neuer Knoten erzeugen und initialisieren
    //head_tail anpassen
    head_tail->prev = n2;
    head_tail->prev->prev->next = n2;
    list_size++;//listegroesse anpassen


}

void List::insertBack(List& _List)
{
	// Einfuegen der Liste _List am Ende einer vorhandenen Liste
	/*
	Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
	Die einzufuegende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden. 
	*/
	if (head_tail == _List.head_tail) return;		
    list_size += _List.list_size;// gleiches Objekt -> keine Aktion

    head_tail->prev->next = _List.head_tail->next;
    _List.head_tail->next->prev = head_tail->prev;
    _List.head_tail->prev->next = head_tail;
    head_tail->prev = _List.head_tail->prev;
   
    _List.list_size = 0;
    _List.head_tail->next = _List.head_tail;// HT auf sich selbst setzen
   
       


    
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Ende der Liste (this) übertragen ohne sie zu kopieren!
	Die Liste _List ist danach leer, aber vorhanden.
*/
}

bool List::getFront(int& key)
{
	// entnehmen des Knotens am Anfang der Liste
	// der Wert wird als Referenz Parameter zurueckgegeben
	// der Knoten wird entnommen
	// im Fehlerfall wird false zurückgegeben
	if (!list_size) return false;	// leere Liste -> kein Wert
	/*
		Der Wert des vorderen Knotens wird rückgegeben und der Knoten gelöscht.
		Die Methode del(key) darf nicht zum löschen benutzt werden.
	*/
    Node* temp = head_tail->next;
    key = head_tail->next->key;  //erster Knoten Zurückgeben
    head_tail->next = head_tail->next->next;
    head_tail->next->prev = head_tail;
    
    delete temp;// löschen des Knotens
    list_size--;
    return true;
    
}

bool List::getBack(int& key)
{ // entnehmen des Knotens am Ende der Liste
	// der Wert wird als Parameter zurueckgegeben
	// der Knoten wird entnommen
	// im Fehlerfall wird false zurückgegeben
	if (!list_size) return false;	// leere Liste -> kein Wert
	/*
		Der Wert des letzten Knotens wird rückgegeben und der Knoten gelöscht.
		Die Methode del(key) darf nicht zum löschen benutzt werden.
	*/
    Node* temp = head_tail->prev;
    key = head_tail->prev->key;//letzter Knoten Zurückgeben
    head_tail->prev = head_tail->prev->prev;
    head_tail->prev->next = head_tail;

    delete temp;
    list_size--;
    return true;
    
}

bool List::del(int key)
{
	// Loeschen eines gegebenen Knotens
	// im Fehlerfall wird false zurückgegeben
	if (!list_size) return false; // leere Liste -> keine Aktion
/*
	Löschen des Knotens mit dem Wert value 
*/
   
    
    
            Node* ptr = head_tail->next;
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

bool List::search(int key)
{
	// suchen eines Knotens
	// nicht gefunden -> Rueckgabe: false
	if (!list_size) return false; // leere Liste -> keine Aktion
    
    Node* ptr = head_tail->next;
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

bool List::swap(int key1, int key2)
{
	// Vertauschen von zwei Knoten
	// Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.
	// im Fehlerfall wird false zurueckgegeben
	if (list_size < 2) return false; // leere oder einer Liste -> keine Aktion
/*
	Vertauschen von zwei Knoten mit dem Wert value1 und dem Wert value2.
	Es duerfen nicht nur einfach die Werte in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhaengen.
*/
    Node* ptr1 = head_tail->next;
    while (ptr1->key != key1)
        ptr1 = ptr1->next;// erste Knoten
   // Node* tmp1 = ptr1;

    Node* ptr2 = head_tail->next;
    while (ptr2->key != key2)
        ptr2 = ptr2->next;
    //Node* tmp2 = ptr2;
    Node*neu = new Node;// new Node erstellen um die koordination von ptr2 zu bewahren
    neu->next = ptr2->next;
    ptr2->next->prev=neu;
    neu->prev = ptr2->prev;
    ptr2->prev->next=neu;
    //knoten 2 zu knoten 1 umwandeln
    ptr2->next = ptr1->next;
    ptr1->next->prev = ptr2;
    ptr2->prev = ptr1->prev;
    ptr1->prev->next = ptr2;
   
    //Knoten 1 zu neu umwandeln
    ptr1->next = neu->next;
    neu->next->prev = ptr1;
    ptr1->prev = neu->prev;
    neu->prev->next = ptr1;
    delete neu;//neu löschen 
    return true;
   


	
}

int List::size(void)
{
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
    
}

bool List::test(void)
{
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und
    // zurück Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
    // der Knoten überein liefert die Methode true
    Node* tmp    = head_tail->next;
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
}

List& List::operator=(const List& _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen. Kopiert wird in das Objekt "this"
    if (this == &_List)
        return *this; //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node* tmp_node;
    if (list_size)
    {
        Node* tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node !=
               head_tail) // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del  = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size       = 0;
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
        delete &_List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
    return *this;
}

List& List::operator+(const List& List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue
    // Ergebnisliste.
    Node* tmp_node;
    List* tmp;
    if (temp)
    { // this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    }
    else
    {
        tmp =
            new List(*this); // this ist keine temporäre Liste -> Kopie erzeugen
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
        delete &List_Append; // wurde eine temporäre Liste übergeben, dann wird
                             // diese gelöscht
    return *tmp;
}

void List::format(const std::string& start,
                  const std::string& zwischen,
                  const std::string& ende)
{
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start    = start;
    list_form.zwischen = zwischen;
    list_form.ende     = ende;
}

std::ostream& operator<<(std::ostream& stream, List const& Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node* tmp = Liste.head_tail->next; tmp != Liste.head_tail;
         tmp       = tmp->next)
        stream << tmp->key
               << (tmp->next == Liste.head_tail ? Liste.list_form.ende :
                                                  Liste.list_form.zwischen);
    if (Liste.temp)
        delete &Liste; // wurde eine temporäre Liste übergeben, dann wird diese
                       // gelöscht
    return stream;
}
