#include "stdafx.h"
#include "MultiMap.h"
#include "Iterator.h"

//creates an empty MultiMap
MultiMap::MultiMap(int m)
{
	this->m = m;
	T = new Node*[m];
	for (int i = 0; i < m; i++)
		T[i] = NULL;
}


//destroys a MultiMap
MultiMap::~MultiMap()
{
	delete[] T;
}


//adds a new key-value pair to the MultiMap
void MultiMap::add(char key, Pair elem)
{
	Node* found = searchNode(key);
	int pos = h(key);
	if (found == NULL) {	//key not found
		Node* newNode = new Node;
		newNode->key = key;
		newNode->insertValue(elem);
		newNode->next = NULL;
		if (T[pos] == NULL) 
			T[pos] = newNode;
		else {
			newNode->next = T[pos];
			T[pos] = newNode;
		}
	}
	else {	//key already has some values
		found->insertValue(elem);
	}
}


//deletes a key-value pair from the MultiMap
void MultiMap::remove(char key, Pair elem)
{
	Node* found = searchNode(key);
	if (found != NULL) {
		found->removeValue(elem);
		if (found->headOfValues == NULL) {	//key has no more values
			int pos = h(key);
			if (T[pos] == found)		//Node is head of T[pos] list
				T[pos] = T[pos]->next; 
			else {
				Node* previous = T[pos];
				Node* current = previous->next;
				while (current != NULL && current->key != key) {
					previous = previous->next;
					current = current->next;
				}
				previous->next = current->next;
				delete current;
			}
		}
	}
}


//searches for the Node with specified key
Node* MultiMap::searchNode(char key)
{
	int position = h(key);
	Node* crt = T[position];
	while (crt != NULL && crt->key != key )
		crt = crt->next;
	return crt;
}


//searches the list of values belonging to the specified key
TValue* MultiMap::search(char key)
{
	int position = h(key);
	Node* crt = T[position];
	while (crt != NULL && crt->key != key)
		crt = crt->next;
	if (crt != NULL)
		return crt->headOfValues;
	else
		return NULL;
}


//gives the number of pairs in the MultiMap
int MultiMap::size()
{
	Iterator it(this);
	int count = 0;
	while (it.valid()) {
		count++;
		it.next();
	}
	return count;
}


//gives the number of keys in the MultiMap
int MultiMap::numberOfKeys()
{
	int keys = 0;
	Iterator it(this);
	if (it.valid()) {
		Tuple current = it.getCurrent();
		char prevKey = current.key;
		keys++;
		while (it.valid()) {
			current = it.getCurrent();
			if (current.key != prevKey) {
				keys++;
				prevKey = current.key;
			}
			it.next();
		}
	}
	return keys;	
}


//gives the set of keys in the MultiMap
KeyNode * MultiMap::keys()
{
	Iterator it(this);
	if (it.valid()) {
		Tuple current = it.getCurrent();
		KeyNode* knode = new KeyNode(current.key);
		KeyNode* head = knode;
		while (it.valid()) {
			current = it.getCurrent();
			if (current.key != knode->keyInfo) {
				knode->nextKey = new KeyNode(current.key);
				knode = knode->nextKey;
			}
			it.next();
		}
		return head;
	}
	return NULL;
}
