#include "BST.h"
#include "BSTNode.h"
#include <iostream>
#include "Person.h"
BSTree::~BSTree() {
	delete root;
	root = NULL;

}

void BSTree::PrintTree() {
	if (root != NULL)
		root->Inorder();
}
void BSTree::MakeEmpty() {
	if (Isempty()) {
		cout << "Already Empty";
		return;
	}
	delete root;
	root = NULL;
}
bool BSTree::Isempty() {
	if (root)
		return false;
	return true;

}

BSTree::BSTree(Person* arr, int size, int &numcomp) {
	this->root = NULL;
	for (int i = 0; i < size; i++) {
		Insert(arr[i].GetId(), arr[i].GetName(), numcomp);
	}
}




BSTreenode* BSTree::Helperfunc(BSTreenode* root, int k) {
	if (!root->getright() && !root->getleft()) {//leaf
		return root;

	}

	if (k <= root->getnumofkeys_left()) {
		Helperfunc(root->getleft(), k);
	}
	else if (k == root->getnumofkeys_left() + 1)
		return root;
	else
		Helperfunc(root->getright(), (k - root->getnumofkeys_left()) - 1);
}

BSTreenode* BSTree::Find(int key) {
	BSTreenode* temp = root;
	while (temp != NULL) {
		if (key == temp->getkey()) {
			return temp;
		}
		else if (key < temp->getkey())
			temp = temp->getleft();
		else
			temp = temp->getright();
	}
	return NULL;


}
void BSTree::Insert(int key, char* data, int &numcomp) {
	if (Find(key) != NULL)//shouldnt enter here anyways , because we check it in the main 
	{
		cout << "Key already exists";
		return;
	}
	BSTreenode* temp = root;
	BSTreenode* parent = NULL;

	//search key func 
	while (temp != NULL) {
		parent = temp;
		if (key < temp->getkey()) {
			numcomp++;
			temp->increment_numofleft();
			temp = temp->getleft();
		}
		else {
			numcomp++;
			temp->increment_numofright();
			temp = temp->getright();
		}

	}
	BSTreenode* newnode = new BSTreenode(key, data, NULL, NULL);

	if (parent == NULL)
		this->root = newnode;
	else if (key < parent->getkey()) {
		numcomp++;
		parent->setleft(newnode);
	}
	else {
		numcomp++;
		parent->setright(newnode);
	}





}

void BSTree::searchKey(BSTreenode*& curr, int key, BSTreenode*& parent)
{
	// traverse the tree and search for the key
	while (curr != NULL && curr->getkey() != key)
	{
		// update parent node as current node
		parent = curr;

		// if given key is less than the current node, go to left subtree
		// else go to right subtree
		if (key < curr->getkey())
			curr = curr->getleft();
		else
			curr = curr->getright();
	}
}

// Helper function to find max value node in subtree rooted at curr 
BSTreenode* BSTree::maxsubtreekey(BSTreenode* curr, BSTreenode* &parent)
{
	while (curr->getright() != NULL) {
		parent = curr;
		curr = curr->getright();
	}
	return curr;
}

void BSTree::Delete(int key) {

	BSTreenode* parenttemp = NULL;
	BSTreenode* curr = this->root;
	searchKey(curr, key, parenttemp);
	if (curr == NULL) {
		cout << "No Such key";
		return;
	}

	//leaf
	if (!curr->getleft() && !curr->getright()) {
		if (curr != root) {
			if (parenttemp->getright() == curr)
				parenttemp->setright(NULL);
			else
				parenttemp->setleft(NULL);
		}
		else
			root = NULL;
		delete[]curr;
		return;
	}


	//one child 
	if (curr->getright() == NULL) {
		parenttemp->setleft(curr->getleft());
		curr->setleft(NULL);
		delete curr;
		return;
	}
	else if (curr->getleft() == NULL) {
		parenttemp->setright(curr->getright());
		curr->setright(NULL);
		delete curr;
		return;

	}

	//2 children
	else if (curr->getright() && curr->getleft()) {
		BSTreenode* parent = NULL;
		BSTreenode* max_left = maxsubtreekey(curr->getleft(), parent);//fidns the max in left subtree and his parent
		//change curr with max_left
		curr->setkey(max_left->getkey());
		curr->setdata(max_left->getdata());



		if (max_left->getleft() == NULL)//delete leaf
		{
			if (parent->getright() == max_left)
				parent->setright(NULL);
			else
				parent->setleft(NULL);

			max_left->setright(NULL);
		}
		else {
			if (parent->getright() == max_left) {
				parent->setright(max_left->getleft());
			}
			else {
				parent->setleft(max_left->getleft());
			}
			max_left->setleft(NULL);
			max_left->setright(NULL);
			delete max_left;
		}






	}

}


