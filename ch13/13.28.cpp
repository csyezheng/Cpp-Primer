#include <string>
#include "13.28.h"

TreeNode::TreeNode(const TreeNode &tn) :
	value(tn.value), count(new int(*tn.count)),
	left(new TreeNode(*tn.left)), right(new TreeNode(*tn.right))
{
	++*count;
}

TreeNode &TreeNode::operator= (const TreeNode &tn)
{
	++*tn.count;
	if (--*count == 0)
	{
		delete count;
		delete left;
		delete right;
	}
	value = tn.value;
	count = tn.count;
	left = tn.left;
	right = tn.right;
}

BinStrTree::BinStrTree() : root(nullptr) { }

BinStrTree::BinStrTree(const BinStrTree &bst) :
	root(new TreeNode(*root)) { }

BinStrTree &BinStrTree::operator= (const BinStrTree &bst)
{
	
}