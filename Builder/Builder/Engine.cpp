#include "Engine.h"


Engine::Engine(std::string name)
{
	_name = name;
}

std::string Engine::getName()
{
	return _name;
}

void Engine::setName(std::string name)
{
	_name = name;
}
