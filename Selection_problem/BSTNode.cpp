#include"BSTNode.h"



BSTreenode::BSTreenode() {
	left = right = NULL;
	key = 0;
	data = 0;

}


BSTreenode::BSTreenode(int key, char* data, BSTreenode* left, BSTreenode* right) {
	this->left = left;
	this->right = right;
	this->key = key;
	this->data = strdup(data);

}

BSTreenode::~BSTreenode() {
	delete[]data;

	if (left != NULL)
		delete left;
	if (right != NULL)
		delete right;
}

void BSTreenode::Inorder() {
	if (left != NULL)
		left->Inorder();

	cout << data;
	if (right != NULL)
		right->Inorder();
}

void BSTreenode::Postorder() {
	if (left != NULL)
		left->Postorder();


	if (right != NULL)
		right->Postorder();

	cout << data;
}
void BSTreenode::Preorder() {

	cout << data;
	if (left != NULL)
		left->Preorder();
	if (right != NULL)
		right->Preorder();


}