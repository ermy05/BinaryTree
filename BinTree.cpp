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
	std::string path = DATA_DIR;

	TreeNode* head;
	head = createTreeFromFile(path + "tree.txt");

	head->printTree(0);
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
