#pragma once
#include "Node.h"

class Stack
{
private:
	Node* top;

public:
	Stack();
	char getTop();
	void push_back(char value);
	void pop_back();
	bool isEmpty();

};

