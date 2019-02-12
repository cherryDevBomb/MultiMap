#pragma once


//Tuple user as TElem for a value info
struct Pair
{
	char neighbourCity;
	int distance;

	Pair() {}
	Pair(char city, int d) {
		this->neighbourCity = city;
		this->distance = d;
	}

	bool operator==(const Pair& other);
	bool operator!=(const Pair& other);
};



//used for "keys" function
struct KeyNode 
{
	char keyInfo;
	KeyNode* nextKey;
	KeyNode(char k) {
		keyInfo = k;
		nextKey = NULL;
	}
};