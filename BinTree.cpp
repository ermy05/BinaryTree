// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "headers/TreeNode.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TreeNode* createTreeFromFile(string file);

int main()
{
	std::string filePath = DATA_DIR;

	TreeNode* head = nullptr;
	TreeNode* subtree = nullptr;

	while (true) {
		std::string input;
		std::cout << std::endl;
		std::cout << "Tree Tool Ready. Commands:" << std::endl;
		std::cout << "1. treecheck <file> (check if file1 is avl tree)" << std::endl;
		std::cout << "2. treecheck <file1> <file2> (check if file1 contains file2)" << std::endl;
		std::cout << "3. search <file1> <value>(check if file1 contains value)" << std::endl;
		std::cout << "4. exit" << std::endl;
		std::cout << std::endl;
		if (!std::getline(std::cin, input) || input == "exit") break;

		std::stringstream ss(input);
		std::string command, file1, file2;
		int targetValue;

		ss >> command;

		if (command == "treecheck") {
			ss >> file1;
			head = createTreeFromFile(filePath + file1 + ".txt");
			if (head == nullptr) {
				continue;
			}
			if (ss >> file2) {
				subtree = createTreeFromFile(filePath + file2 + ".txt");
				if (subtree == nullptr) {
					continue;
				}
				std::cout << "Action: Checking subtree " << file1 << std::endl;
				if (head->isSubtree(subtree)) {
					cout << "SubTree found in tree" << std::endl;
				}
				else {
					cout << "SubTree not found in tree" << std::endl;
				}
			}
			else {
				std::cout << "Action: Checking tree " << file1 << std::endl;
				head->printTree(0);
				head->getBalanceFactor();
				std::cout <<  ((head->getIsAVLTree()) ?  "AVL: yes" : "AVL: no" ) << std::endl;
				std::cout << "min: " << head->getMinValue() << ", max: " << head->getMaxValue() << ", avg: " << static_cast<float>(head->getSum()) / static_cast<float>(head->getNodeCount()) << std::endl;
			}
		}
		else if (command == "search") {
			ss >> file1;
			head = createTreeFromFile(filePath + file1 + ".txt");
			if (head == nullptr) {
				continue;
			}
			if (ss >> targetValue) {
				std::cout << "Action: Searching for " << targetValue << " in " << file1 << std::endl;
				head->findSingleValue(targetValue, "");
			}
		}
		else {
			std::cout << "Unknown command. Try 'treecheck'." << std::endl;
		}
		delete head;
		delete subtree;
		head = nullptr;
		subtree = nullptr;
	}

	return 0;

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
