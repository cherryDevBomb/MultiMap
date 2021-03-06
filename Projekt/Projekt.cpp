// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MultiMap.h"
#include "Tests.h"
#include <climits>


struct GraphNode
{
	char city;
	unsigned distanceFromSource;
	GraphNode* parent;
	bool visited;

	GraphNode() {
		this->city = 0;
		distanceFromSource = UINT_MAX;
		parent = NULL;
		visited = false;
	}
};



GraphNode* findMin(GraphNode** queue, int size)
{
	GraphNode* min = new GraphNode;
	for (int i = 0; i < size; i++) {
		if (!queue[i]->visited) {
			if (queue[i]->distanceFromSource < min->distanceFromSource)
				min = queue[i];
		}
	}
	return min;
}


GraphNode* findNode(GraphNode** queue, Pair city, int size)
{
	for (int i = 0; i < size; i++) {
		if (queue[i]->city == city.neighbourCity)
			return queue[i];
	}
	return NULL;
}


int shortestPath(MultiMap& graph, char start, char end)
{
	KeyNode* keys = graph.keys();
	int numberOfNodes = graph.numberOfKeys();
	GraphNode** unvisited = new GraphNode*[numberOfNodes];	//create queue of nodes to visit
	for (int i = 0; i < numberOfNodes; i++) {
		unvisited[i] = new GraphNode;
		unvisited[i]->city = keys->keyInfo;
		if (keys->keyInfo == start)
			unvisited[i]->distanceFromSource = 0;
		keys = keys->nextKey;
	}
	GraphNode* v;
	while (true) { 
		v = findMin(unvisited, numberOfNodes);
		v->visited = true;
		if (v->city == end)
			break;
		else {
			TValue* neighbours = graph.search(v->city);		//find neighbour nodes
			while (neighbours != NULL) {
				GraphNode* u = findNode(unvisited, neighbours->info, numberOfNodes);
				if ((!u->visited) && (u->distanceFromSource > (v->distanceFromSource + neighbours->info.distance))) {
					u->distanceFromSource = v->distanceFromSource + neighbours->info.distance;
					u->parent = v;
				}
				neighbours = neighbours->nextVal;
			}
		}
	}

	int distance = v->distanceFromSource;

	char* path = new char[numberOfNodes];
	path[0] = v->city;
	int i = 1;
	while (v->parent != NULL) {
		path[i] = v->parent->city;
		i++;
		v = v->parent;
	}
	
	std::cout << "Shortest path from " << start << " to " << end << " is: ";
	i--;
	for (i; i > 0; i--) {
		std::cout << path[i] << " --> ";
	}
	std::cout << path[0];

	std::cout << std::endl << "Distance = " << distance << std::endl;

	return distance;
}


void print(MultiMap& m)
{
	std::cout << "The following keys are nodes in a graph.\n[] indicates the list of neighbour nodes for each node and distances to them." << std::endl << std::endl;
	Iterator it(&m);
	if (it.valid()) {
		Tuple current = it.getCurrent();
		std::cout << "Key " << current.key << ":  [ ";
		char prevKey = current.key;
		std::cout << "(" << current.elem.neighbourCity;
		std::cout << ", " << current.elem.distance << ")";
		it.next();
		while (it.valid()) {
			current = it.getCurrent();
			if (current.key != prevKey) {
				std::cout << " ]" << std::endl;
				std::cout << "Key " << current.key << ":  [ ";
				prevKey = current.key;
				std::cout << "(" << current.elem.neighbourCity;
				std::cout << ", " << current.elem.distance << ")";
			}
			else {
				std::cout << ", (" << current.elem.neighbourCity;
				std::cout << ", " << current.elem.distance << ")";
			}
			it.next();
		}
		std::cout << " ]" << std::endl;
		std::cout << std::endl << std::endl;
	}



	while (it.valid()) {
		
		std::cout << (it.getCurrent().key) << " " << (it.getCurrent().elem.neighbourCity);
		std::cout << "\n";
		it.next();
	}
}


int main()
{
	Tests::testMultiMap();

	MultiMap m(19);
	m.add('a', Pair('b', 2));
	m.add('a', Pair('r', 3));
	m.add('b', Pair('a', 2));
	m.add('b', Pair('z', 7));
	m.add('b', Pair('f', 1));
	m.add('z', Pair('b', 7));
	m.add('z', Pair('t', 9));
	m.add('z', Pair('f', 4));
	m.add('t', Pair('z', 9));
	m.add('t', Pair('r', 8));
	m.add('t', Pair('f', 4));
	m.add('r', Pair('a', 3));
	m.add('r', Pair('t', 8));
	m.add('f', Pair('b', 1));
	m.add('f', Pair('z', 4));
	m.add('f', Pair('t', 4));
	
	int option;

	while (true)
	{
		print(m);

		char start;
		char end;
		std::cout << std::endl;
		std::cout << "Calculate shortest distance " << std::endl;
		std::cout << "From: ";
		std::cin >> start;
		std::cout << "to: ";
		std::cin >> end;
		std::cout << std::endl;
		shortestPath(m, start, end);
		std::cout << std::endl;
		system("pause");
		system("cls");
	}

    return 0;
}





