#include "headers/TreeNode.h"
#include <iostream>

TreeNode::TreeNode(int value) {
	this->leftNode = nullptr;
	this->rightNode = nullptr;
	this->value = value;
}

void TreeNode::addNode(TreeNode* node) {
	if (node->getValue() > this->getValue()) {
		if (this->rightNode == nullptr) {
			this->rightNode = node;
		}
		else {
			this->rightNode->addNode(node);
		}
	}
	else if (node->getValue() < this->getValue()) {
		if (this->leftNode == nullptr) {
			this->leftNode = node;
		}
		else {
			this->leftNode->addNode(node);
		}
	}
}

TreeNode* TreeNode::findNode(int target) {
	if (this->value == target) {
		return this;
	}

	if (target < this->getValue()) {
		if (this->leftNode == nullptr) {
			return nullptr;
		}
		return this->leftNode->findNode(target);
	}
	else {
		if (this->rightNode == nullptr) {
			return nullptr;
		}
		return this->rightNode->findNode(target);
	}
}

int TreeNode::getValue() {
	return this->value;
}

void TreeNode::printTree(int depth) {
	std::cout << std::string(depth, '|') << this->getValue() << std::endl;
	if (this->leftNode != nullptr) {
		this->leftNode->printTree(depth + 1);
	}
	if (this->rightNode != nullptr) {
		this->rightNode->printTree(depth + 1);
	}
}