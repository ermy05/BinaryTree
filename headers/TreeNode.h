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
	//bool isSubTree(TreeNode* mainTree);
	int getValue();
	void printTree(int depth);
};

