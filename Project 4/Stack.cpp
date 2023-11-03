#include "Stack.h"


Stack::Stack() {
	top = nullptr;
}

char Stack::getTop() {
	return top->value;
}

void Stack::pop_back() {
	Node* temp = top;
	top = top->next;
	delete temp;
}

void Stack::push_back(char value) {
	Node* temp = new Node(value);
	temp->next = top;
	top = temp;
}

bool Stack::isEmpty() {
	return top == nullptr;
}