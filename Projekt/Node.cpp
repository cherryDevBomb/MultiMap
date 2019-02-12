#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	key = 0;
	headOfValues = NULL;
	next = NULL;
}


Node::~Node()
{
	delete headOfValues;
	delete next;
}


void Node::insertValue(Pair elem)
{
	TValue* crt = headOfValues;
	while (crt != NULL && crt->info != elem)
		crt = crt->nextVal;
	if (crt == NULL) {
		TValue* toInsert = new TValue;
		toInsert->info = elem;
		toInsert->nextVal = headOfValues;
		headOfValues = toInsert;
	}
}

void Node::removeValue(Pair elem)
{
	TValue* crt = headOfValues;
	if (crt->info == elem) {
		headOfValues = crt->nextVal;
		delete crt;
	}
	else {
		TValue* prev = crt;
		crt = prev->nextVal;
		while (crt != NULL && crt->info != elem) {
			prev = prev->nextVal;
			crt = crt->nextVal;
		}
		if (crt != NULL) {
			prev->nextVal = crt->nextVal;
			delete crt;
		}
	}

}
