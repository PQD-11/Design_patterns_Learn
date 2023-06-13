#include <string>
#pragma once

class Engine
{
public:
	Engine() = default;
	Engine(std::string name);
	std::string getName();
	void setName(std::string name);
private:
	std::string _name;
};

