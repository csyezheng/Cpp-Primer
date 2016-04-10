#include <string>
#include "13.28.h"

TreeNode::TreeNode(const TreeNode &rhs) :
	value(rhs.value), count(new int(1)), left(nullptr), right(nullptr) { }

TreeNode &TreeNode::operator= (const TreeNode &rhs)
{
	++*rhs.count;
	if (--*count == 0)
	{
		if (left)
		{
			delete left;
			left = nullptr;
		}
		if (right)
		{
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;
}

TreeNode::~TreeNode()
{
	if (--*count == 0)
	{
		if (left)
		{
			delete left;
			left = nullptr;
		}
		if (right)
		{
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
}

BinStrTree::BinStrTree() : root(new TreeNode()) { }

BinStrTree::BinStrTree(const BinStrTree &rhs) :
	root(new TreeNode(*rhs.root)) { }

BinStrTree &BinStrTree::operator= (const BinStrTree &rhs)
{
	auto temp = new TreeNode(*rhs.root);
	delete root;
	root = temp;
	return *this;
}

BinStrTree::~BinStrTree()
{
	delete root;
}
