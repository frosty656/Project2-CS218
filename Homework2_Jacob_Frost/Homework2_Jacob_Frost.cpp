#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;

void displayTree(TreeNode * node, string parent, string side)
{
	if (node == nullptr)
	{
		return;
	}
	if (side != " ")
	{
		side += " of";
	}
	cout << "Displaying node: " << node->getName() << side << " Parent = " << parent << endl;
	displayTree(node->getLeft(), node->getName(), "  Left");
	displayTree(node->getRight(), node->getName(), "  Right");
}

int doTheTree(TreeNode * node) {
	if (!node)
		return 0;

	//if its a lead its an int
	if (!node->getLeft() && !node->getRight()) {
		cout << node->getName();
		return stoi(node->getName());
	}

	int goLeft = doTheTree(node->getLeft());

	int goRight = doTheTree(node->getRight());

	// Comapre Operand
	if (node->getName() == "+") {
		cout << "+";
		return goLeft + goRight;
	}

	if (node->getName() == "-") {
		cout << "-";
		return goLeft - goRight;
	}

	if (node->getName() == "*") {
		cout << "*";
		return goLeft * goRight;
	}
	if (node->getName() == "/") {
		cout << "/";
		return goLeft / goRight;
	}

	cout << "Error invalid char" << endl;
	return -1;
}


int main()
{
	//Set up the tree
	TreeNode * root = new TreeNode();
	root->setName("/");
	TreeNode * left = root->addLeft("*");
	TreeNode * right = root->addRight("D");
	left->addLeft("A");
	left = left->addRight("+");
	left->addLeft("B");
	left->addRight("C");


	displayTree(root, " ", " ");


	//update the tree with numberical values
	left = root->getLeft();
	left->getLeft()->setName("2");
	left = left->getRight();
	left->getLeft()->setName("7");
	left->getRight()->setName("3");
	right->setName("5");

	//Display coorisponding values
	cout << "A = " << root->getLeft()->getLeft()->getName() << endl;
	cout << "B = " << root->getLeft()->getRight()->getLeft()->getName() << endl;
	cout << "C = " << root->getLeft()->getRight()->getRight()->getName() << endl;
	cout << "D = " << right->getName() << endl;

	//Solve the tree
	cout << "Expression (postfix): ";
	cout << endl << "THE ANSWER: " << doTheTree(root) << endl;

	delete root;
}

