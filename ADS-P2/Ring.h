/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"

class Ring {

	private:
		
		RingNode* anker;
		int countNodes = 0;
	public:
		Ring();
		
		void addNewNode(std::string s1, std::string s2) ;
		bool search(std::string s) ;
		void print() ;
	
	////////////////////////////////////
	// friend Funktionen müssen unangetastet bleiben! 
	friend RingNode* get_anker(Ring& r);
	friend int get_countNodes(Ring& r);
};
