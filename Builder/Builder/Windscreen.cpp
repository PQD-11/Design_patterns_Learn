#include "Windscreen.h"

Windscreen::Windscreen(std::string name)
{
	_name = name;
}

std::string Windscreen::getName()
{
	return _name;
}

void Windscreen::setName(std::string name)
{
	_name = name;
}
