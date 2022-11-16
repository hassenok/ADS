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
    void balance(TreeNode* t);
    bool split4Node(TreeNode* t);
    int proofRBCriterion(TreeNode* t);
    bool rotateTreeRight(TreeNode* a, TreeNode* b);
    bool rotateTreeLeft(TreeNode* a, TreeNode* b);


    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree() {
        anker = 0;
        currentNodeChronologicalID=0;
    };
    ~Tree() {};
    //TreeNode* get_anker() { return anker; };
    void printLevelOrder();
    void printLevelOrder(int k);

    TreeNode* get_anker() { return anker; };
    void printInorder(TreeNode* k, string Name, bool& yn);
    void printPreorder(TreeNode* k, string Name, bool& yn);
    bool addNode(string a, int b, double c, int d);
    bool deleteNode(int a);
    bool searchNode(string s);
    void printAll();
    void printAll1();
    void print(TreeNode* tmp);
    TreeNode* MinimumTreeSearch(TreeNode* x);
    TreeNode* MaximumTreeSearch(TreeNode* x);
    TreeNode* finde(TreeNode* k, int parameter_1);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
