#include "headers/TreeNode.h"
#include <iostream>

bool TreeNode::isAVLTree = true;

TreeNode::TreeNode(int value) {
	this->leftNode = nullptr;
	this->rightNode = nullptr;
	this->value = value;
}

TreeNode::~TreeNode() {
	delete this->leftNode;
	delete this->rightNode;
}

/*
O(log(n))
*/
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

/*
O(log(n)) -> Pro Durchlauf wird der Suchumfang halbiert
*/
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

/*
O(1)
*/
int TreeNode::getValue() {
	return this->value;
}

/*
O(n) -> Pro Durchlauf wird der Suchumfang halbiert
*/
void TreeNode::printTree(int depth) {
	std::cout << std::string(depth, '|') << this->getValue() << std::endl;
	if (this->leftNode != nullptr) {
		this->leftNode->printTree(depth + 1);
	}
	if (this->rightNode != nullptr) {
		this->rightNode->printTree(depth + 1);
	}
}

/*
O(log(n)) -> Pro Durchlauf wird der Suchumfang halbiert
*/
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

/*
O(n * m) -> n = this tree size, m = subtree size
*/
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

/*
Worst Case: O(n^2 * m) -> Mit balanced Tree: O(n*m*log(n))
*/
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

/*
O(n) -> Es wird über jeden node gegangen und die Height wird aufgerufen
*/
int TreeNode::getHeigth() {
	if (this == nullptr) { return 0; }

	int leftHeight = (this->leftNode == nullptr) ? 0 : this->leftNode->getHeigth();
	int rightHeight = (this->rightNode == nullptr) ? 0 : this->rightNode->getHeigth();

	return 1 + std::max(leftHeight, rightHeight);
}

/*
O(n^2) -> für jeden Node muss rekursiv die Höhe geprüft (height könnte gecached werden)
*/
int TreeNode::getBalanceFactor() {
	if (this == nullptr) { return 0; }

	int leftHeight = (this->leftNode == nullptr) ? 0 : this->leftNode->getHeigth();
	int rightHeight = (this->rightNode == nullptr) ? 0 : this->rightNode->getHeigth();

	(this->rightNode == nullptr) ? 0 : this->rightNode->getBalanceFactor();
	(this->leftNode == nullptr) ? 0 : this->leftNode->getBalanceFactor();
	std::cout << "bal(" << this->getValue() << ") = " << leftHeight - rightHeight << ((std::abs(leftHeight - rightHeight)>1) ? " (AVL violation!)" : "") << std::endl;

	if (std::abs(leftHeight - rightHeight) > 1) {
		setIsAVLTreeFalse();
	}

	return leftHeight - rightHeight;
}

/*
O(n) -> in jedem Fall wird der gesamte Baum durchgegangen
*/
int TreeNode::getSum() {
	if (this == nullptr) return 0;
	int sum = this->value;
	if (this->leftNode != nullptr) sum += this->leftNode->getSum();
	if (this->rightNode != nullptr) sum += this->rightNode->getSum();
	return sum;
}

/*
O(n) -> in jedem Fall wird der gesamte Baum durchgegangen
*/
int TreeNode::getNodeCount() {
	if (this == nullptr) return 0;
	int count = 1;
	if (this->leftNode != nullptr) count += this->leftNode->getNodeCount();
	if (this->rightNode != nullptr) count += this->rightNode->getNodeCount();
	return count;
}

/*
O(log(n)) -> Pro Durchlauf wird der Suchumfang halbiert
*/
int TreeNode::getMinValue() {
	TreeNode* current = this;

	while (current->leftNode != nullptr) { current = current->leftNode; }
	return current->getValue();
}

/*
log(n) -> Pro Durchlauf wird der Suchumfang halbiert
*/
int TreeNode::getMaxValue() {
	TreeNode* current = this;
	while (current->rightNode != nullptr) { current = current->rightNode; }
	return current->getValue();
}

void TreeNode::setIsAVLTreeFalse() {
	isAVLTree = false;
}

bool TreeNode::getIsAVLTree() {
	return isAVLTree;
}