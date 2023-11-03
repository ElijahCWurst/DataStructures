#pragma once
#include "Node.h"

template<typename T> Node<T>::Node(T value) {
	this->value = value;
	next = nullptr;
}
