#pragma once
#ifndef _BSTN_
#define _BSTN_
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
#include<string.h>


class BSTreenode {

private:
	int key;
	char* data;
	BSTreenode *left, *right;
	int numofkeys_right = 0;
	int numofkeys_left = 0;

public:
	BSTreenode();
	BSTreenode(int key, char* data, BSTreenode* left, BSTreenode* right);
	~BSTreenode();

	//Traversals
	void Inorder();
	void Preorder();
	void Postorder();

	//get funcs
	int getkey() { return key; };
	char* getdata() { return data; };
	int getnumofkeys_right() { return numofkeys_right; };
	int getnumofkeys_left() { return numofkeys_left; };


	BSTreenode* getleft() { return left; };
	BSTreenode* getright() { return right; };

	//set
	void setleft(BSTreenode* left) { this->left = left; };
	void setright(BSTreenode* right) { this->right = right; };

	void setkey(int key) { this->key = key; };
	void setdata(char*data) { this->data = strdup(data); };

	//count how many keys each side
	void increment_numofright() { this->numofkeys_right++; };
	void increment_numofleft() { this->numofkeys_left++; };



};


#endif#pragma once
