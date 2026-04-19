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

void TreeNode::findSingleValue(int target, std::string path) {
	path += std::to_string(this->value);

	if (this->value == target) {
		std::cout << "Target found: " << target << ", with path: " << path << std::endl;
		return;
	}

	path += " -> ";

	if (this->value > target) {
		if (this->leftNode == nullptr) {
			std::cout << "Target not found " << std::endl;
			return;
		}
		else {
			this->leftNode->findSingleValue(target, path);
		}
	}
	if (this->value < target) {
		if (this->rightNode == nullptr) {
			std::cout << "Target not found " << std::endl;
			return;
		}
		else {
			this->rightNode->findSingleValue(target, path);
		}
	}
}

bool TreeNode::isSubtree(TreeNode* subtree) {
	if (this == nullptr && subtree == nullptr) {
		return true;
	}
	if (this != nullptr && subtree == nullptr) {
		return true;
	}
	if (this == nullptr || subtree == nullptr) {
		return false;
	}
	if (this->getValue() != subtree->getValue()) {
		return this->leftNode->isSubtree(subtree) || this->rightNode->isSubtree(subtree);
	}

	return (this->getValue() == subtree->getValue()) &&
		this->leftNode->isSubtree(subtree->leftNode) &&
		this->rightNode->isSubtree(subtree->rightNode);
}

bool TreeNode::subtreeCheck(TreeNode* subtree) {
	if (subtree == nullptr) {
		return true;
	}
	if (this == nullptr) {
		return false;
	}

	if (this->isSubtree(subtree)) {
		return true;
	}

	return this->leftNode->subtreeCheck(subtree) || this->rightNode->subtreeCheck(subtree);
}