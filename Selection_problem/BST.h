#pragma once
#ifndef _BST_
#define _BST_
#include <iostream>
#pragma warning(disable : 4996)
class BSTreenode;
class Person;
#include<string.h>


class BSTree {
private:
	BSTreenode* root;
public:
	BSTree(Person *arr, int size, int &numcomp);
	BSTree() { root = NULL; };
	~BSTree();
	BSTreenode* Find(int key);//find key in tree
	void Insert(int key, char* data, int &numcomp);//insert key and data to tree
	void Delete(int key);
	void PrintTree();
	void MakeEmpty();
	bool Isempty();

	void searchKey(BSTreenode*& curr, int key, BSTreenode*& parent);//find parent of key and him . 
	BSTreenode* maxsubtreekey(BSTreenode* curr, BSTreenode* &parent);//find max key in given subtree and his parent

	BSTreenode* Helperfunc(BSTreenode* root, int k);//Function recursively to find kth number

	BSTreenode *getroot() { return this->root; };




};

#endif