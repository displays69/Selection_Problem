#ifndef __SELECTION__
#define __SELECTION__
#pragma warning(disable : 4996)
#include<string.h>
class Person;
class BSTree;
class BSTreenode;



class Selection
{
public:

	int Partition(Person *arr, int left, int right, int &NumComp);//partition the pivot
	const Person  RandSelection(Person arr[], int k, int &NumComp, int left, int right);//selection problem with randomly choosen pivot	
	void PrintArr(Person *arr, int size);
	const Person  BST(Person arr[], int size, int k, int &NumComp);//selection problem in search tree
	const Person selectHeap(Person arr[], int size, int k, int &NumComp);//selection problem in heap


};







#endif
