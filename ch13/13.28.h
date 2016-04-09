#ifndef TREE_H
#define TREE_H

#include <string>

class TreeNode
{
public:
	TreeNode(const std::string &s = std::string()) :
		value(s), count(new int(1)), left(nullptr), right(nullptr) { }
	TreeNode(const TreeNode &tn);
	TreeNode &operator(const TreeNode &tn);
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	BinStrTree();
	BinStrTree(const BinStrTree &bst);
	BinStrTree &operator= (const BinStrTree &bst);
private:
	TreeNode *root;
};

#endif