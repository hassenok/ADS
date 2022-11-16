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
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int a, int b, string c, int d, double e, int f) {
        NodeOrderID = a; NodeChronologicalID = b; Name = c; Age = d; Income = e; PostCode = f; left = nullptr; right = nullptr;
        };
    string get_Name() { return Name; };
    void set_Name(string s) { Name = s; };
    int get_NodeOrderID() { return NodeOrderID; };
    void set_NodeOrderID(int a) { NodeOrderID = a; };
    int get_NodeChronologicalID() { return NodeChronologicalID; };
    void set_NodeChronologicalID(int a) { NodeChronologicalID = a; };
    int get_Age() { return Age; };
    void set_Age(int a) { Age= a; };
    int get_PostCode() { return PostCode; };
    void set_PostCode(int a) { PostCode = a; };
    double get_Income() { return Income; };
    void set_Income(double a) { Income = a; };
    TreeNode* get_left() { return left; };
    void set_left(TreeNode* a) { left = a; };
    TreeNode* get_right() { return right; };
    void set_right(TreeNode* a) { right = a; };
    ////////////////////////////////////
};
