#pragma once
#include "Value.h"


//saves the key with the corresponding list of values
class Node
{
public: 
	char key;
	TValue* headOfValues;	//head of vlues list
	Node* next;				//pointer to next node on the same slot

	Node();
	~Node();

	void insertValue(Pair elem);
	void removeValue(Pair elem);
};

