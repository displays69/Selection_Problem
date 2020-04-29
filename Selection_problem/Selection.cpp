#pragma warning(disable : 4996)
#include "Selection.h"
#include <iostream>
using namespace std;
#include "Person.h"
#include "BST.h"
#include "BSTNode.h"
#include "MinHeap.h"
#include <string.h>


void Selection::PrintArr(Person *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].GetId() << "   ";
	}
	cout << "\n";
}

int Selection::Partition(Person *arr, int left, int right, int &NumComp)

{

	int pivot_index = (rand() % (right - left)) + left;
	swap(arr[right - 1], arr[pivot_index]);
	pivot_index = right - 1;
	int pivot = arr[pivot_index].GetId();
	int index_left = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i].GetId() < pivot) {

			swap(arr[index_left], arr[i]);
			index_left++;
		}
		NumComp++;
	}
	swap(arr[pivot_index], arr[index_left]);


	return index_left;
}


const Person Selection::RandSelection(Person arr[], int k, int &NumComp, int left, int right) // at start left will be set to 0 , right to array size-1

//Complexity:Worst Case:Teta(n^2)
//			 Average Case:Teta(n)


{
	int leftPart;
	int pivot_index = Partition(arr, left, right, NumComp);
	leftPart = pivot_index - left + 1;


	if (k == leftPart)
		return arr[pivot_index];


	if (k < leftPart)
		return RandSelection(arr, k, NumComp, left, pivot_index);

	else
		return RandSelection(arr, k - leftPart, NumComp, pivot_index + 1, right);
}






const Person Selection::BST(Person arr[], int size, int k, int &NumComp) {


	//worst case:teta(n^2)(taking into consideration building the search tree)
   //average case: teta(nlogn)(taking into consideration building the search tree)



	BSTree T(arr, size, NumComp);

	BSTreenode* res;
	res = T.Helperfunc(T.getroot(), k);
	Person info = *new Person(res->getdata(), res->getkey());
	return info;


}


const Person Selection::selectHeap(Person arr[], int size, int k, int &NumComp) {

	// worst case: teta(klogn+N)
	//(taking the building of the heap into consideration , which is teta(n), doing according to Floyd's algorithm)
	MinHeap H(arr, size, NumComp);
	int count = 0;
	Person temp;
	while (count != k) {

		temp = H.DeleteMin(NumComp);
		count++;
	}
	return temp;
}


