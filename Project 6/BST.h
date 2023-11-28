#pragma once
#include "BSTNode.h"
#include "Word.h"
#include <fstream>

// Based off of the book for this course
class BST
{
public:
	BST();
	bool isEmpty() const;
	//Prints out the entire wordlist
	void inOrder();
	void inOrder(ofstream&);
	void insert(Word*, int);

	//Created by Tim Zink
	void PrintStructure(void (*func) (Word*, int, int, vector<int>*)) { root->PrintStructure(0, func, 0, new vector<int>()); }
protected:
	BSTNode* root;
	void inOrder(BSTNode*);
	void inOrder(BSTNode*, ofstream&);

};

