#include "Heap.h"
//This function was adapted from the book.
void Heap::HeapSort(int data[], int size, bool maxHeap) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		moveDown(data, i, size - 1, maxHeap);
	}
	for (int i = size - 1; i >= 1; --i) {
		swap(data[0], data[i]);
		moveDown(data, 0, size - 1, maxHeap);
	}
}

void Heap::moveDown(int data[], int i, int size, bool maxHeap) {
	const int L_CHILD = 2 * i + 1;
	const int R_CHILD = 2 * i + 2;
	int biggerChild = -1;
	int smallerChild = -1;

	if (data[L_CHILD] > data[R_CHILD]) { //Finding which child is bigger.
		biggerChild = L_CHILD;
		smallerChild = R_CHILD;
	}
	else {
		biggerChild = R_CHILD;
		smallerChild = L_CHILD;
	}
	if (L_CHILD >= size) {
		return;
	}

	if (maxHeap) { //Max heap
		if (R_CHILD >= size) { //Checking the possibility of only one child
			if (data[L_CHILD] <= data[i]) return;
			swap(data[i], data[L_CHILD]);
			moveDown(data, L_CHILD, size, maxHeap);
		}
		else if (data[i] > data[biggerChild]) { //Checking if one of the children are greater than their parent.
			swap(data[i], data[biggerChild]);
			moveDown(data, biggerChild, size, maxHeap);
		}
	}
	else { //Min heap
		if (R_CHILD >= size) { //Checking the possibility of only one child
			if (data[L_CHILD] >= data[i]) return;
			swap(data[i], data[L_CHILD]);
			moveDown(data, L_CHILD, size, maxHeap);
		}
		else if (data[i] < data[smallerChild]) { //Checking if one of the children are smaller than their parent.
			swap(data[i], data[smallerChild]);
			moveDown(data, smallerChild, size, maxHeap);
		}
	}
}

void Heap::printHeap(int data[], int size) { for (int i = 0; i < size; ++i) cout << data[i] << " "; }