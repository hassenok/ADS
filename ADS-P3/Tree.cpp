#include"Tree.h"
#include<iostream>
#include"TreeNode.h"
#include<iomanip>
#include<queue>

bool Tree::split4Node(TreeNode* t) {
	TreeNode* ptr = t;
	if (ptr!=0&&ptr->getRight()!=0&&ptr->getLeft()!=0) {
		if (ptr->getRight()->getRed() && ptr->getLeft()->getRed()) {
			ptr->getRight()->setRed(false);
			ptr->getLeft()->setRed(false);
			if (ptr != anker) {
				ptr->setRed(true);
			}
			return true;
		}
		return false;
	}
}
bool Tree::addNode(string neu_n, int neu_age, double neu_income, int neu_postcode) {
	int id = neu_age + neu_income + neu_postcode;
	TreeNode* ptr = anker;
	TreeNode* temp = 0;
	TreeNode* neu = new TreeNode(id, currentNodeChronologicalID++, neu_n, neu_age, neu_income, neu_postcode);
	neu->setRed(true);
	if (anker == 0) {
		anker = neu;
		neu->setRed(false);
		return true;
	}
	else {
		
		do {
			bool test = split4Node(ptr);
			if (ptr->getNodeOrderID() < id) {
				if (ptr->getRight() != 0) {
					temp = ptr;
					ptr = ptr->getRight();
				}
				else if (ptr->getRight() == 0) {
					ptr->setRight(neu);
					neu->setParent(ptr);
					//currentNodeChronologicalID++;
					break;
				}
			}
			else if (ptr->getNodeOrderID() > id) {
				if (ptr->getLeft() != 0) {
					temp = ptr;
					ptr = ptr->getLeft();
				}
				else if (ptr->getLeft() == 0) {
					ptr->setLeft(neu);
					neu->setParent(ptr);
					//currentNodeChronologicalID++;
					break;
				}

			}
			else
				return false;
			
			
		} while (ptr != 0);
		// Jetzt Bottom-Up
		ptr = neu;
		while (ptr!=0 && ptr->getParent() != anker) {

			if (ptr->getRed() && ptr->getParent()->getRed())
			{
				balance(ptr->getParent());
			}
			ptr = ptr->getParent();
		}
		

	}

	return true;
}
void Tree:: balance(TreeNode* t) {
	//4 Fälle hier :
	//RechtsRotation
	if (t == t->getParent()->getLeft() && t->getLeft()!=0 &&t->getLeft()->getRed())
	{
		rotateTreeRight(t->getParent(),t);
	}
	//LR
	else if (t == t->getParent()->getRight() && t->getRight() != 0&& t->getRight()->getRed()) {
		rotateTreeLeft(t->getParent(), t);
	}
	//doppelRotation:
	//LR dann RR
	else if (t == t->getParent()->getLeft() && t->getRight()->getRed()) {
		rotateTreeLeft(t, t->getRight());
		rotateTreeRight(t->getParent()->getParent(),t->getParent());
	}
	//RR dann LR
	else if (t == t->getParent()->getRight() && t->getLeft()->getRed()) {
		rotateTreeRight(t, t->getLeft());
		rotateTreeLeft(t->getParent()->getParent(), t->getParent());
	}

}
bool Tree::rotateTreeLeft(TreeNode* a, TreeNode* b) {
	if (a == 0 || b == 0) {
		return false;
	}
	else
	{
		a->setRight(b->getLeft());
		if (b->getLeft() != 0)
		{
			
			b->getLeft()->setParent(a);
		}
		
		b->setLeft(a);
		
		//parent von parent setzen
		if (a == anker) {
			anker = b;
			b->setParent(0);
		}
		else {
			b->setParent(a->getParent());
			if (b->getParent()->getLeft() == a) {
				b->getParent()->setLeft(b);
			}
			else if(b->getParent()->getRight() == a){
				b->getParent()->setRight(b);
			}
		}
		
		a->setParent(b);
		//umfärben
		bool x = b->getRed();
		b->setRed(a->getRed());
		a->setRed(x);
		return true;
	}
}
bool Tree:: rotateTreeRight(TreeNode* a, TreeNode* b) {
	if (a == 0 || b == 0) {
		return false;
	}
	else
	{
		a->setLeft(b->getRight());
		if (b->getRight() != 0)
		{
			b->getRight()->setParent(a);
		}
		b->setRight(a);
		//parent von parent setzen
		if (a == anker) {
			anker = b;
			b->setParent(0);
		}
		else {
			b->setParent(a->getParent());
			if (b->getParent()->getLeft() == a) {
				b->getParent()->setLeft(b);
			}
			else if(b->getParent()->getRight() == a){
				b->getParent()->setRight(b);
			}
		}
		
		a->setParent(b);

		//umfärben
		bool x = b->getRed();
		b->setRed(a->getRed());
		a->setRed(x);
		return true;
	}
}
int Tree::proofRBCriterion(TreeNode* t) {
	int wertlinks;
	int wertrechts;
	if(t->getLeft()!=0){
		wertlinks = proofRBCriterion(t->getLeft());
	}
	if (t->getRight() != 0) {
		wertrechts = proofRBCriterion(t->getRight());
	}
	if (wertlinks == -1 || wertrechts == -1)
		return -1;
	else if (t->getLeft() == 0 && t->getRight() == 0) {// 2 Nachfolger gleich null
		return 0;
	}
	else if (t->getLeft()->getRed() && t->getRight()->getRed()) {// 2 Nachfolger sind ROT
		return (wertlinks!=wertrechts) ? -1 : wertlinks;
	}
	else if (t->getLeft()->getRed() || t->getRight()->getRed()) {// eine der beiden ist Rot und der ander schwarz
		if (t->getLeft()->getRed() && !t->getRight()->getRed()) {
			if (wertlinks = wertrechts + 1)
				return wertlinks;
			else
				return -1;
		}
		else if (!t->getLeft()->getRed() && t->getRight()->getRed()) {
			if (wertrechts = wertlinks + 1)
				return wertrechts;
			else
				return -1;
		}
	}
	else if (!t->getLeft()->getRed() && !t->getRight()->getRed()) {//beide sind schwarz
		if (wertlinks == wertrechts)
			return wertlinks + 1;
		else
			return -1;
		
	}
	else if (t->getLeft() == 0 || t->getRight() == 0) {//einer der beiden existiert nicht 
		if (t->getLeft() == 0 && t->getRight() != 0) {
			if (t->getRight()->getRed())
				return wertrechts ;
			else if (!t->getRight()->getRed())
				return wertrechts+1;
		}
		else if (t->getLeft() != 0 && t->getRight() == 0) {
			if (t->getLeft()->getRed())
				return wertlinks ;
			else if (!t->getLeft()->getRed())
				return wertlinks+1;
		}
	}
	
}


//void Tree:: printLevelOrder(){
//	queue<TreeNode*> q1;
//	queue<int>q2;
//	TreeNode* ptr = anker;
//	int level = -1;
//	TreeNode* node;
//	if (ptr != 0) {
//		q1.push(ptr);
//		while (!q1.empty()) {
//			node = q1.front();
//			q1.pop();
//			cout << node->getNodeOrderID() << ", ";
//			if (node->getLeft() != 0 )
//			{
//				if (node->getLeft()->getRed() == false)
//				{
//					q1.push(node->getLeft());
//				}
//				//überprüfen   Nachfolger von Nachfolger 
//				/*else
//				{
//					if (node->getLeft()->getLeft()->getRed() == false) {
//						q1.push(node->getLeft()->getLeft());
//					}
//					else if (!(node->getLeft()->getRight()->getRed())) {
//						q1.push(node->getLeft()->getRight());
//					}
//				}*/
//			}
//			if (node->getRight() != 0&& node->getRight()->getRed() == false) q1.push(node->getRight());
//			level++;
//			q2.push(level);
//		}
//	}
//}
//
//void Tree::printLevelOrder(int niv) {
//	cout << "Niv. " << niv << " : ";
//	this->printLevelOrder();
//}






bool Tree::searchNode(string parameter_1) {
	bool yn = false;
	if (anker == nullptr) {
		return false;
	}
	else {
		TreeNode* ptr = anker;
		printPreorder(ptr, parameter_1, yn);
		if (yn == false) {//Ausgabe falls NICHT gefunden
			cout << "+ Der zu suchende Datensatz existiert nicht" << endl;
		}
		return yn;
	}
}
void Tree::printInorder(TreeNode* k, string Name, bool& yn) {
	// Ausgabe in Inorder
	if (k != nullptr) {
		if (k->getName() == Name) {
			cout << "ID: " << k->getNodeChronologicalID() << " , " << "Name: " << k->getName() << " , " << "Age: " << k->getAge() << " , " << "Income: " << k->getIncome() << " , " << "PostCode: " << k->getPostCode() << " , " << "OrderID: " << k->getNodeOrderID() << endl;
			yn = true;
			return;
		}
		printInorder(k->getLeft(), Name, yn);

		printInorder(k->getRight(), Name, yn);
	}
}
void Tree::printPreorder(TreeNode* k, string Name, bool& yn) {
	// Ausgabe in Preorder
	if (k != nullptr) {
		if (k->getName() == Name) {
			cout << "ID: " << k->getNodeChronologicalID() << " , " << "Name: " << k->getName() << " , " << "Age: " << k->getAge() << " , " << "Income: " << k->getIncome() << " , " << "PostCode: " << k->getPostCode() << " , " << "OrderID: " << k->getNodeOrderID() << endl;
			yn = true;
		}
		printInorder(k->getLeft(), Name, yn);
		printInorder(k->getRight(), Name, yn);
	}
}

void Tree::printAll() {
	if (anker == 0) {
		//Tree is empty
		cout << "The Tree is empty , please fill it and print again" << endl;
	}
	else {
		cout << "ID | Name       | Age | Income |  PostCode  | OrderID | RED  " << endl
			<< "---+------------+-------+-----------+-------+------+------" << endl;
		cout << setw(3) << anker->getNodeChronologicalID() <<
			setw(12) << anker->getName() <<
			setw(6) << anker->getAge() <<
			setw(12) << anker->getIncome() <<
			setw(9) << anker->getPostCode() <<
			setw(9) << anker->getNodeOrderID();
			if(anker->getRed())
				cout<<setw(6) <<"1"<<endl;
			else
				cout << setw(6) << "0" << endl;


		if (anker->getLeft() != nullptr)//rekursive Aufruf
			print(anker->getLeft());
		if (anker->getRight() != nullptr)
			print(anker->getRight());
	}
}

void Tree::print(TreeNode* tmp) {
	if (tmp != nullptr) {
		cout << setw(3) << tmp->getNodeChronologicalID() <<
			setw(12) << tmp->getName() <<
			setw(6) << tmp->getAge() <<
			setw(12) << tmp->getIncome() <<
			setw(9) << tmp->getPostCode() <<
			setw(9) << tmp->getNodeOrderID() ;
		if (tmp->getRed())
			cout << setw(6) << "1" << endl;
		else
			cout << setw(6) << "0" << endl;
		print(tmp->getLeft());
		print(tmp->getRight());
	}
}

void Tree::printLevelOrder(void) {
	// Q for Nodes
	queue<TreeNode*> nodeQueue;
	// Q for Lvl
	queue<int> niveauQueue;
	// folge Lvl
	int initialLevel = 0;

	//wurzel rein
	nodeQueue.push(anker);
	// und erste Lvl -> 0 rein.
	niveauQueue.push(0);


	while (!nodeQueue.empty() )
	{
		// Pointer auf Anfang des Queues
		TreeNode* tmp = nodeQueue.front();//!

		// levelWechesel
		if (niveauQueue.front() == 0 || niveauQueue.front() > initialLevel)
		{
			cout << endl << "Niv. " << niveauQueue.front() << ": ";
			if (niveauQueue.front() > initialLevel)
				initialLevel++;
		}

		cout << "(";

		// Linker Nachfolger
		if (tmp->getLeft() != nullptr) // left if not leer
		{
			if (tmp->getLeft()->getRed() == false) // bei Blackfall Linker Nachfolger
			{
				nodeQueue.push(tmp->getLeft());
				niveauQueue.push(initialLevel + 1);

			}
			else                                    // bei Rotfall Linker Nachfolger
			{

				cout << tmp->getLeft()->getNodeOrderID() << ", ";

				// Prufe ob Rote Nachfolger linken Nachfolger hat
				if (tmp->getLeft()->getLeft() != nullptr)
				{
					nodeQueue.push(tmp->getLeft()->getLeft());
					niveauQueue.push(initialLevel + 1);
				}
				// Prufe ob Rote Nachfolger rechten Nachfolger hat
				if (tmp->getLeft()->getRight() != nullptr)
				{
					nodeQueue.push(tmp->getLeft()->getRight());
					niveauQueue.push(initialLevel + 1);
				}

			}//end else
		}//end left if not leer


		// man muss das aktuelle Node Beachten
		cout << tmp->getNodeOrderID();


		if (tmp->getRight() != nullptr) // right if not leer
		{
			if (tmp->getRight()->getRed() == false) // bei Blackfall Rechter Nachfolger
			{
				nodeQueue.push(tmp->getRight());
				niveauQueue.push(initialLevel + 1);

			}
			else                                    // bei Rotfall Rechter Nachfolger
			{

				cout << ", " << tmp->getRight()->getNodeOrderID();

				// Prufe ob Rote Nachfolger linekn Nachfolger hat
				if (tmp->getRight()->getLeft() != nullptr)
				{
					nodeQueue.push(tmp->getRight()->getLeft());
					niveauQueue.push(initialLevel + 1);
				}
				// Prufe ob Rote Nachfolger rechten Nachfolger hat
				if (tmp->getRight()->getRight() != nullptr)
				{
					nodeQueue.push(tmp->getRight()->getRight());
					niveauQueue.push(initialLevel + 1);
				}

			}//end else
		}//end if right if not leer

		cout << ")";

		// the first El. weg, wegen naechst Lvl
		niveauQueue.pop();
		nodeQueue.pop();

	} // end while
}
void Tree::printLevelOrder(int pos) {
	// Q for Nodes
	queue<TreeNode*> nodeQueue;
	// Q for Lvl
	queue<int> niveauQueue;
	// folge Lvl
	int initialLevel = 0;

	//wurzel rein
	nodeQueue.push(anker);
	// und erste Lvl -> 0 rein.
	niveauQueue.push(0);


	while (!nodeQueue.empty() )
	{
		// Pointer auf Anfang des Queues
		TreeNode* tmp = nodeQueue.front();//!

		// levelWechesel
		if (niveauQueue.front() == 0 || niveauQueue.front() > initialLevel)
		{
			if (niveauQueue.front() > pos) {
				return;
			}
			if (niveauQueue.front() == pos) {
				cout << endl << "Niv. " << niveauQueue.front() << ": ";
			}
			//cout << endl << "Niv. " << niveauQueue.front() << ": ";
			if (niveauQueue.front() > initialLevel)
				initialLevel++;
		}
		if (niveauQueue.front() == pos) {
			cout << "(";
		}

		// Linker Nachfolger
		if (tmp->getLeft() != nullptr) // left if not leer
		{
			if (tmp->getLeft()->getRed() == false) // bei Blackfall Linker Nachfolger
			{
				nodeQueue.push(tmp->getLeft());
				niveauQueue.push(initialLevel + 1);

			}
			else                                    // bei Rotfall Linker Nachfolger
			{
				if (niveauQueue.front() == pos) {
					cout << tmp->getLeft()->getNodeOrderID() << ", ";
				}
				// Prufe ob Rote Nachfolger linken Nachfolger hat
				if (tmp->getLeft()->getLeft() != nullptr)
				{
					nodeQueue.push(tmp->getLeft()->getLeft());
					niveauQueue.push(initialLevel + 1);
				}
				// Prufe ob Rote Nachfolger rechten Nachfolger hat
				if (tmp->getLeft()->getRight() != nullptr)
				{
					nodeQueue.push(tmp->getLeft()->getRight());
					niveauQueue.push(initialLevel + 1);
				}

			}//end else
		}//end left if not leer


		// man muss das aktuelle Node Beachten
		if (niveauQueue.front() == pos) {
			cout << tmp->getNodeOrderID();
		}

		if (tmp->getRight() != nullptr) // right if not leer
		{
			if (tmp->getRight()->getRed() == false) // bei Blackfall Rechter Nachfolger
			{
				nodeQueue.push(tmp->getRight());
				niveauQueue.push(initialLevel + 1);

			}
			else                                    // bei Rotfall Rechter Nachfolger
			{
				if (niveauQueue.front() == pos) {
					cout << ", " << tmp->getRight()->getNodeOrderID();
				}
				// Prufe ob Rote Nachfolger linekn Nachfolger hat
				if (tmp->getRight()->getLeft() != nullptr)
				{
					nodeQueue.push(tmp->getRight()->getLeft());
					niveauQueue.push(initialLevel + 1);
				}
				// Prufe ob Rote Nachfolger rechten Nachfolger hat
				if (tmp->getRight()->getRight() != nullptr)
				{
					nodeQueue.push(tmp->getRight()->getRight());
					niveauQueue.push(initialLevel + 1);
				}

			}//end else
		}//end if right if not leer
		if (niveauQueue.front() == pos) {
			cout << ")";
		}
		// the first El. weg, wegen naechst Lvl
		niveauQueue.pop();
		nodeQueue.pop();
	} // end while
}