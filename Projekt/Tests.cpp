#include "stdafx.h"
#include "Tests.h"


void Tests::testMultiMap()
{
	MultiMap m(11);
	assert(m.size() == 0);

	//test add
	m.add(1, Pair(12, 25));
	assert(m.size() == 1);
	m.add(14, Pair(1, 34));
	m.add(1, Pair(5, 50));
	m.add(12, Pair(1, 43));
	assert(m.size() == 4);
	m.add(14, Pair(1, 34));
	assert(m.size() == 4);

	//test search
	TValue* found = m.search(1);
	TValue* found2 = m.search(2);
	TValue* found3 = m.search(12);
	assert(found != NULL);
	assert(found2 == NULL);
	assert(found3->info == Pair(1, 43));

	//test searchNode
	Node* foundNode = m.searchNode(12);
	Node* foundNode2 = m.searchNode(15);
	assert(foundNode != NULL);
	assert(foundNode2 == NULL);

	//test numberOfKeys
	int nr = m.numberOfKeys();
	assert(nr == 3);

	//test keys
	KeyNode* keys = m.keys();
	assert(keys->nextKey->nextKey->nextKey == NULL);

	//test remove
	m.remove(1, Pair(12, 25));
	assert(m.size() == 3);
	m.remove(1, Pair(100, 25));
	assert(m.size() == 3);

	//test iterator
	Iterator it(&m);
	assert(it.valid());
	it.next();
	it.next();
	it.next();
	assert(!it.valid());
	
}
