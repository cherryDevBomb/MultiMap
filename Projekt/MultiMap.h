#pragma once
#include "Node.h"
#include <iostream>


class MultiMap
{
public:
	int m;							//array length
	Node ** T;						//an array of pointers to nodes
	int h(char k) { return k % m; }	//hash function

	MultiMap(int m);
	~MultiMap();

	void add(char key, Pair elem);
	void remove(char key, Pair elem);
	Node* searchNode(char key);
	TValue* search(char key);
	int size();
	int numberOfKeys();
	KeyNode* keys();
};