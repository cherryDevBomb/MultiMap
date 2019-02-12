#include "stdafx.h"
#include "Iterator.h"



Iterator::Iterator(MultiMap* map)
{
	this->m = map;
	this->currentPos = 0;
	while (currentPos < map->m && map->T[currentPos] == NULL)
		currentPos++;
	if (currentPos < map->m) {
		currentNode = map->T[currentPos];
		currentElem = currentNode->headOfValues;
	}
	else
		currentNode = NULL;
}



Tuple Iterator::getCurrent()
{
	return Tuple(currentNode->key, currentElem->info);
}



void Iterator::next()
{
	if (currentElem->nextVal != NULL)	//go to next value in the headOfValues list
		currentElem = currentElem->nextVal;
	else {
		if (currentNode->next != NULL) {	//go to next pair on the same slot
			currentNode = currentNode->next;
			currentElem = currentNode->headOfValues;
		}
		else {
			currentPos++;
			while (currentPos < m->m && m->T[currentPos] == NULL)
				currentPos++;
			if (currentPos < m->m) {
				currentNode = m->T[currentPos];
				currentElem = currentNode->headOfValues;
			}
			else {
				currentElem = NULL;
			}
		}
	}
}


bool Iterator::valid()
{
	if (currentElem == NULL)
		return false;
	else
		return true;
}



Iterator::~Iterator()
{
}

