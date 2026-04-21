#pragma once

#include <string>

class TreeNode {
private:
	int value;
	TreeNode* leftNode;
	TreeNode* rightNode;
	static bool isAVLTree;
public:
	TreeNode(int value);
	~TreeNode();
	void addNode(TreeNode* node);
	TreeNode* findNode(int target);
	void findSingleValue(int target, std::string path);

	bool isSubtree(TreeNode* subtree);
	bool subtreeCheck(TreeNode* subtree);

	int getHeigth();
	int getBalanceFactor();

	int getSum();
	int getNodeCount();
	int getMinValue();
	int getMaxValue();

	int getValue();
	void printTree(int depth);

	void setIsAVLTreeFalse();
	bool getIsAVLTree();
};

