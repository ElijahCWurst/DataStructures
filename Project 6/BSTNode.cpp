#include "BSTNode.h"

BSTNode::BSTNode() {
	this->info = nullptr;
	left = right = nullptr;
}
BSTNode::BSTNode(Word* info) {
	this->info = info; 
	left = nullptr; 
	right = nullptr;
}

