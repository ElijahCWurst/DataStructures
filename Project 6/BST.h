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
protected:
	BSTNode* root;
	void inOrder(BSTNode*);

};

