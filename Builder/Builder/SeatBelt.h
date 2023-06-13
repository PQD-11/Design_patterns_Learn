#include <string>
#pragma once
class SeatBelt
{
public:
	SeatBelt() = default;
	SeatBelt(std::string brand);
	std::string getBrand();
	void setBrand(std::string brand);
private:
	std::string _brand;
};

