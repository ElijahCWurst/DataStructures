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

//Created by Tim Zink
void BSTNode::PrintStructure(int depth, void (*func)(Word*, int, int, vector<int>*), int position, vector<int> *also)
{
	if (left != nullptr) {
		vector<int>* c = new vector<int>(*also);
		if (position != 1 && position != 0) {
			c->push_back(depth);
		}
		left->PrintStructure(depth + 1, func, 1, c);
	}
	func(info, depth, position, also);
	if (right != nullptr) {
		vector<int>* c = new vector<int>(*also);
		if (position != -1 && position != 0) {
			c->push_back(depth);
		}
		right->PrintStructure(depth + 1, func, -1, c);
	}
}
