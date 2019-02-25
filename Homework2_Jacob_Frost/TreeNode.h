#pragma once
#include <string>

using namespace std;

class TreeNode
{
public:
public:
	TreeNode();
	~TreeNode();

	TreeNode * getLeft();
	TreeNode * getRight();
	void setLeft(TreeNode *);
	void setRight(TreeNode *);
	void setName(string);
	string getName();
	TreeNode * addLeft(string);
	TreeNode* addRight(string);

private:
	TreeNode * leftNode;
	TreeNode * rightNode;
	string name;
};

