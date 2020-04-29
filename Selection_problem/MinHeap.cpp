#include "MinHeap.h"
#include "Person.h"

MinHeap::MinHeap(int max) {
	data = new Person[max];
	maxsize = max;
	heapsize = 0;
	allocated = 1;
}

MinHeap::MinHeap(Person arr[], int size, int &numcomp) {
	heapsize = size;
	maxsize = size;

	data = arr;
	allocated = 0;
	for (int i = size / 2 - 1; i >= 0; i--)
		FixHeap(i, numcomp);
}

MinHeap::~MinHeap() {
	if (allocated)
		delete[]data;
	data = NULL;
}

void MinHeap::MakeEmpty() {
	if (Isempty()) {
		cout << "Heap Already Empty";
		return;
	}
	if (allocated)
		delete[]data;
	data = NULL;
}

bool MinHeap::Isempty() {
	if (heapsize == 0)
		return true;
	return false;
}

Person MinHeap::Min() {
	if (heapsize != 0)
		return data[0];
	else {
		cout << "Heap Empty\n";
		exit(1);
	}
}

int MinHeap::Parent(int node) {
	return (node - 1) / 2;
}
int MinHeap::Left(int node) {
	return (2 * node + 1);
}
int MinHeap::Right(int node) {
	return (2 * node + 2);
}

void MinHeap::FixHeap(int node, int &numcomp) {
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapsize) && (data[left].GetId() < data[node].GetId()))
	{
		min = left;
		numcomp++;
	}
	else {
		numcomp++;
		min = node;
	}

	if ((right < heapsize) && (data[right].GetId() < data[min].GetId()))
	{
		min = right;

	}
	numcomp++;

	if (min != node) {
		swap(data[min], data[node]);
		FixHeap(min, numcomp);
	}
}
Person MinHeap::DeleteMin(int &numcomp) {
	if (heapsize < 1) {
		cout << "Empty Heap\n";
		exit(1);
	}
	Person min = data[0];
	data[0] = data[--heapsize];
	FixHeap(0, numcomp);
	return min;
}
void MinHeap::Insert(Person info) {
	if (heapsize == maxsize) {
		cout << "Heap Is Full\n";
		exit(1);
	}
	int i = heapsize++;

	while (i > 0 && data[Parent(i)].GetId() > info.GetId()) {
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = info;
}


