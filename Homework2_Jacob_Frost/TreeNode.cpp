#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode()
{
	leftNode = nullptr;
	rightNode = nullptr;
	name = "";
}

TreeNode::~TreeNode()
{
	if (rightNode != nullptr)
	{
		delete rightNode;
	}
	if (leftNode != nullptr)
	{
		delete leftNode;
	}
}

TreeNode * TreeNode::getLeft()
{
	return leftNode;
}

TreeNode * TreeNode::getRight()
{
	return rightNode;
}

void TreeNode::setLeft(TreeNode * node)
{
	leftNode = node;
}

void TreeNode::setRight(TreeNode * node)
{
	rightNode = node;
}

void TreeNode::setName(string n)
{
	name = n;
}

string TreeNode::getName()
{
	return name;
}

TreeNode * TreeNode::addLeft(string n)
{
	if (leftNode != nullptr)
	{
		throw "Left node already exists" + leftNode->getName();
	}
	leftNode = new TreeNode();
	leftNode->setName(n);
	return leftNode;
}

TreeNode * TreeNode::addRight(string n)
{
	if (rightNode != nullptr)
	{
		throw "Right node already exists for node: " + rightNode->getName();
	}
	rightNode = new TreeNode();
	rightNode->setName(n);
	return rightNode;
}
