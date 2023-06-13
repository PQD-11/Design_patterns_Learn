#include "SeatBelt.h"

SeatBelt::SeatBelt(std::string brand)
{
	_brand = brand;
}

std::string SeatBelt::getBrand()
{
	return _brand;
}

void SeatBelt::setBrand(std::string brand)
{
	_brand = brand;
}
