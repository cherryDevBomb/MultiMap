#pragma once
#include "MultiMap.h"


struct Tuple 
{
	char key;
	Pair elem;
	Tuple(char k, Pair e) { key = k; elem = e; }
};


class Iterator
{
public:
	MultiMap* m;
	int currentPos;
	Node* currentNode;
	TValue* currentElem;

	Iterator(MultiMap* m);
	Tuple getCurrent();
	void next();
	bool valid();

	~Iterator();
};

