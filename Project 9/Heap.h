#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Heap
{
public:
	Heap() {}
	void HeapSort(int[], int, bool);
	void printHeap(int[], int);

private:
	void moveDown(int[], int, int, bool);
};