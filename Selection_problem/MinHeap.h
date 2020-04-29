#pragma once
#ifndef _MH_
#define _MH_
#include<string.h>
#include <iostream>
using namespace std;
class Person;
class MinHeap {
private:
	Person *data;
	int maxsize;
	int heapsize;
	int allocated;

	//get right ,left,parent
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

	//fix a heap where the root is not good
	void FixHeap(int node, int &numcomp);
public:
	MinHeap(int max);
	MinHeap(Person arr[], int size, int& numcomp);//build a heap using floyds algorithm
	~MinHeap();
	Person Min();//current min in hip
	Person DeleteMin(int &numcomp);
	void Insert(Person info);
	void MakeEmpty();
	bool Isempty();

};
#endif