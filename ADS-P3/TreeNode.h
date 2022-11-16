/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int NodeOrderID;
    int NodeChronologicalID;
    string Name;
    int Age;
    double Income;
    int PostCode;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    bool red;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int a, int b, string c, int d, double e, int f) {
        //NodeOrderID = a; NodeChronologicalID = 0; Name = c; Age = d; Income = e; PostCode = f;

        setNodeOrderID(a);
        setNodeChronologicalID(b);
        setName(c);
        setAge(d);
        setIncome(e);
        setPostCode(f);
        left = nullptr;
        right = nullptr;
        parent = nullptr;

    };
    void setParent(TreeNode* p) { parent = p; };
    TreeNode* getParent() { return parent; };
    void setRed(bool a) { red = a; };
    bool getRed() { return red; };
    string getName() { return Name; };
    void setName(string s) { Name = s; };
    int getNodeOrderID() { return Income + PostCode + Age; };
    void setNodeOrderID(int a) { NodeOrderID = a; };
    int getNodeChronologicalID() { return NodeChronologicalID; };
    void setNodeChronologicalID(int a) { NodeChronologicalID = a; };
    int getAge() { return Age; };
    void setAge(int a) { Age = a; };

    int getPostCode() { return PostCode; };
    void setPostCode(int a) { PostCode = a; };
    double getIncome() { return Income; };
    void setIncome(double a) { Income = a; };
    TreeNode* getLeft() { return left; };
    void setLeft(TreeNode* a) { left = a; };
    TreeNode* getRight() { return right; };
    void setRight(TreeNode* a) { right = a; };
    void printAll();// { cout << NodeChronologicalID << "   |" << Name << "   |" << Age << "   |" << Income << "   |" << PostCode << endl; };
    ////////////////////////////////////
};
