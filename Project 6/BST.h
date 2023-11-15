#pragma once
#include "BSTNode.h"
#include "Word.h"

// Based off of the book for this course
class BST
{
public:
	BST();
	bool isEmpty() const;
	void inOrder();
	void insert(Word*, int);

	void PrintStructure(void (*func) (Word*, int, int, vector<int>*)) { root->PrintStructure(0, func, 0, new vector<int>()); }
protected:
	BSTNode* root;
	void inOrder(BSTNode*);

};

