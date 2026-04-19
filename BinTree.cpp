// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "headers/TreeNode.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

TreeNode* createTreeFromFile(string file);

int main()
{
	std::string filePath = DATA_DIR;

	TreeNode* head;
	head = createTreeFromFile(filePath + "search-tree.txt");

	TreeNode* subtree;
	subtree = createTreeFromFile(filePath + "subtree.txt");

	//head->printTree(0);
	head->findSingleValue(30, "");
	head->findSingleValue(22, "");
	//subtree->printTree(0);


	std::cout << std::endl;
	if (head->subtreeCheck(subtree)) {
		std::cout << "Subtree found" << std::endl;
	}
	else {
		std::cout << "Subtree NOT found" << std::endl;
	}
	return 0;
}

TreeNode* createTreeFromFile(string file)
{
	std::ifstream inputFile(file);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file" << std::endl;
		return nullptr;
	}

	TreeNode* head;
	int number;
	if (inputFile >> number) {
		head = new TreeNode(number);
	}
	else
	{
		return nullptr;
	}

	while (inputFile >> number) {
		head->addNode(new TreeNode(number));
	}

	return head;
}
