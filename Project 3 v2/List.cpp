#pragma once
#include "List.h"
#include <iostream>

using namespace std;

// Constructor/Destructor:
template<typename T> List<T>::List() {
	head = tail = nullptr;
}
template<typename T> List<T>::List(T value) {
	Node<T>* newNode = new Node<T>(value);
	head = newNode;
	tail = newNode;
	length = 1;
}
template<typename T> List<T>::~List() {
	Node<T>* temp = head;
	while (head) {
		head = head->next;
		delete temp;        //NOTE: The delete keyword deletes the object that the pointer points to, NOT the actual pointer
		temp = head;
	}
}

//-------------------WORKING-------------------//

/// <summary>
/// Returns pointer
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
/// <returns></returns>
template<typename T> Node<T>* List<T>::getNode(int index) {
	Node<T>* temp = head;
	for (; index > 0; --index) {
		if (temp == nullptr) break;
		temp = temp->next;
	}
	return temp;
}
template<typename T> T List<T>::returnValueAtIndex(int index) {
	Node<T>* temp = getNode(index);
	if (!temp) {
		return NULL;
	}
	return temp->value;
}
template<typename T> void List<T>::printList() {
	Node<T>* temp = head;
	while (temp) {
		std::cout << temp->value << ",";
		temp = temp->next;
	}
	std::cout << std::endl;
}
template<typename T> void List<T>::append(T value) {
	Node<T>* newNode = new Node<T>(value);
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	++length;
}
template<typename T> void List<T>::removeLast() {
	Node<T>* temp = head;
	if (length >= 2) {
		while (temp->next != tail) {
			temp = temp->next;
		}
		tail = temp;
		temp = temp->next;
		delete temp;
		tail->next = nullptr;
		--length;
	}
	if (length == 1) {
		delete head;
		--length;
	}
	if (length == 0) {
		std::cout << "Nothing to remove." << std::endl;
	}
}
template<typename T> void List<T>::removeIndex(int index) {
	Node<T>* temp = head;
	Node<T>* temp2 = head;
	for (int i = 1; i < index - 1; ++i) {
		if (temp->next == nullptr) {
			std::cout << "fail" << std::endl;
			return;
		}
		temp = temp->next;
	}
	if (temp->next == tail) {
		delete tail;
		--length;
		tail = temp;
		return;
	}
	if (index == 1) {
		temp = head;
		head = head->next;
		delete temp;
		--length;
		return;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
	--length;
	return;
}
template<typename T> void List<T>::swapNode(Node<T>* node1, Node<T>* node2) {
	T temp;
	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}
/*template<typename T> void List<T>::swapIndex(int index1, int index2) {
	Node<T>* node2 = getNode(index2);
	Node<T>* node1 = getNode(index1);
	Node<T>* temp;
	temp->value = node1->value;
	node1->value = node2->value;
	node2->value = node1->value;
}*/
template<typename T> void List<T>::sort(bool reverseOrder) {
	Node<T>* obj1 = nullptr;
	Node<T>* obj2 = nullptr;
	bool swapMade = true;
	while (swapMade) {
		obj1 = head;
		obj2 = head->next;
		swapMade = false;
		for (int i = 0; obj2 != nullptr; ++i) {
			if (obj1->value < obj2->value && reverseOrder || obj1->value > obj2->value && !reverseOrder) {
				swapNode(obj1, obj2);
				swapMade = true;
			}
			obj1 = obj2;
			obj2 = obj2->next;
		}
		if (!swapMade) {
			return;
		}
	}
}



// Getters:
template<typename T> T List<T>::getHead() {
	return head->value;
}
template<typename T> T List<T>::getTail() {
	return tail->value;
}
template<typename T> int List<T>::getLength() {
	return length;
}
