/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode {
private:
	int oldAge;
	std::string description;
	std::string symbolicData;
	RingNode* next;
public:
	RingNode();
	RingNode(int a, std::string str1, std::string str2) {
		oldAge = a;
		description = str1;
		symbolicData = str2;
	};
	int getAge() { return oldAge; };
	void setAge(int a) { oldAge = a; };
	std::string getDescription() { return description; };
	void setDescription(std::string str) { description = str; };
	std::string getData() { return symbolicData; };
	void setData(std::string str) { symbolicData = str; };
	RingNode* getNext() { return next; };
	void setNext(RingNode* p) { next = p; };

};