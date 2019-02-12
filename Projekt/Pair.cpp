#include "stdafx.h"
#include "Pair.h"

bool Pair::operator==(const Pair & other)
{
	if (this->neighbourCity == other.neighbourCity && this->distance == other.distance)
		return true;
	return false;
}

bool Pair::operator!=(const Pair & other)
{
	if (this->neighbourCity == other.neighbourCity && this->distance == other.distance)
		return false;
	return true;
}
