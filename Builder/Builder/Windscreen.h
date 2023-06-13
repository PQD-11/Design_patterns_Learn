#include <string>
#pragma once
class Windscreen
{
public:
	Windscreen() = default;
	Windscreen(std::string name);
	std::string getName();
	void setName(std::string name);
private:
	std::string _name;
};

