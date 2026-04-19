#pragma once
class TreeNode {
private:
	int value;
	TreeNode* leftNode;
	TreeNode* rightNode;
public:
	TreeNode(int value);
	void addNode(TreeNode* node);
	TreeNode* findNode(int target);
	void findSingleValue(int target);

	bool isSubtree(TreeNode* subtree);
	bool subtreeCheck(TreeNode* subtree);

	int getValue();
	void printTree(int depth);
};

