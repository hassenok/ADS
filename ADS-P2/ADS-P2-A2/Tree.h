/*************************************************
 * ADS Praktikum 2.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* anker;
    int currentNodeChronologicalID;

    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree() { anker = nullptr; };
    ~Tree();
    void addNode(string a, int b, double c, int d);
    bool deleteNode(int a);
    bool searchNode(string s);
    void printAll();
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
