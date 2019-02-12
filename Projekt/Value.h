#pragma once
#include "Pair.h"


//value corresponding to a key
struct TValue
{
public:
	Pair info;		//data
	TValue* nextVal; //pointer to next value
	
	TValue() {}
	TValue(Pair info) {
		this->info = info;
		this->nextVal = NULL;
	}
	~TValue() { delete nextVal; }
};

