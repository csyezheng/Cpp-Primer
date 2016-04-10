#ifndef TREE_H
#define TREE_H

#include <string>

class TreeNode
{
public:
	TreeNode(const std::string &s = std::string()) :
		value(s), count(new int(1)), left(nullptr), right(nullptr) { }
	TreeNode(const TreeNode&);
	TreeNode &operator= (const TreeNode&);
	~TreeNode();
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
	BinStrTree();
	BinStrTree(const BinStrTree&);
	BinStrTree &operator= (const BinStrTree&);
	~BinStrTree();
private:
	TreeNode *root;
};

#endif