#include "BST.h"
#include "BSTNode.h"
#include "Person.h"
#include "time.h"
#include "MinHeap.h"
#include "Selection.h"
using namespace std;

Person * Input(int size);//get input from user
bool check_if_exists(Person* arr, int id, int size);//check if 2 id's exists

int main() {

	cout << "***Information***\n";
	cout << "The Program takes as input 'n' number of ID's which are the keys, and Names of these people ,  and a 'k' number \n";
	cout << " The Program finds out of all the 'n' ID's the 'k' ID in it size\n The program uses 3 diffrent approaches  to solve the problem,and compares between them(Selection Problem) , the approaches are :\n1.To build a BST and recursively find the kth number\n2.Build a MinHeap and preform k times DeleteMin function\n3.Classic recursive Slection algorithm which will be applied to an array , while the pivot is choosen  randomly\n  ";
	
	cout << "Example : if there are 3 id's which are\n  1,2,3 \n and say we want to find the second id in its size (means k=2) \n the output will be : 2 \n";

	srand(time(NULL));//initialize rand

	int array_size;
	cout << "Enter size of person array :\n";
	cin >> array_size;
	if (array_size == 0) {
		cout << "Invalid Input";
		exit(1);
	}
	cin.ignore();
	Person* arr = new Person[array_size];
	arr = Input(array_size);


	Selection SelectionProblem;
	int k;
	cout << "enter the k number you wish to find :\n";
	cin >> k;
	if (k > array_size)
		cout << "k number cant be more than the number of people ";
	cin.ignore();
	int NumComp = 0;
	Person *temp = new Person[array_size];
	memcpy(temp, arr, sizeof(Person)*array_size);
	Person res = SelectionProblem.RandSelection(temp, k, NumComp, 0, array_size);

	cout <<"k-th id : " <<res.GetId() << "  " <<"k-th name "<< res.GetName() << endl;

	cout << "RandSelection :  " << NumComp << " Comparrssions\n"<<"Run time, WorstCase : Theta(N^2)\n AverageCase : Theta(N)\n\n" ;

	NumComp = 0;
	memcpy(temp, arr, sizeof(Person)*array_size);
	res = SelectionProblem.selectHeap(temp, array_size, k, NumComp);
	cout << "SelectHeap:  " << NumComp << " Comparrssions\n" << "Run time, WorstCase : Theta(klogn+N)\n\n";

	NumComp = 0;
	memcpy(temp, arr, sizeof(Person)*array_size);
	res = SelectionProblem.BST(temp, array_size, k, NumComp);
	cout << "BST:  " << NumComp << " Comparrssions\n"<<"Run time, WorstCase : Theta(N^2)\n AverageCase : Theta(NLogN)\n\n";

}

Person * Input(int array_size) {
	char name[100];
	int id;

	Person* arr = new Person[array_size];
	for (int i = 0; i < array_size; i++)
	{
		cout << "Enter person number " << i << endl;
		cout << "Enter Id Please" << endl;
		cin >> id;
		if (check_if_exists(arr, id, array_size) || id == 0) {
			if (id == 0) 
				cout << "id cant be 0\n";
			if (check_if_exists(arr, id, array_size))
				cout << "this id already exists\n";
			exit(1);

			

			
		}

		cin.ignore();
		cout << "Enter Name Please" << endl;
		cin.getline(name, 100);
		Person temp(name, id);
		arr[i] = temp;
	}
	return arr;

}

bool check_if_exists(Person* arr, int id, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i].GetId() == id)
			return true;
	}
	return false;
}