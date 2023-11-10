#pragma once
#include "Word.h"

// Based off of the book for this course
class BSTNode
{
public:
	BSTNode();
	BSTNode(Word* info);
	Word* info;
	BSTNode* left, * right;
};


