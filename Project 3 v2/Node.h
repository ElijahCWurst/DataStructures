#pragma once

template<typename T> class Node
{
public:
	T value;
	Node* next;
	Node(T value);
};

#include "Node.cpp"