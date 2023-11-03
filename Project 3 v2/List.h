#pragma once
#include "Node.h"

template<typename T> class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int length = 0;
public:
	List();
	List(T value);
	~List();
	T returnValueAtIndex(int index);

	Node<T>* getNode(int index);
	//void swapIndex(int index1, int index2);
	void swapNode(Node<T>* node1, Node<T>* Node2);
	void sort(bool reverseOrder);
	void printList();
	void append(T value);
	void removeLast();
	void removeIndex(int index);
	T getHead();
	T getTail();
	int getLength();
};

#include "List.cpp"

