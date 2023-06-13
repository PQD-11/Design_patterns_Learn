#include <string>
#include "Engine.h"
#include "SeatBelt.h"
#include "Windscreen.h"
#include "Car.h"
#pragma once
class ICarBuilder
{
public:
	virtual ICarBuilder& BuildWheels(int numberOfWheels) = 0;
	virtual ICarBuilder& BuildSeatBelt(SeatBelt* seatBelt) = 0;
	virtual ICarBuilder& BuiidColor(std::string color) = 0;
	virtual ICarBuilder& BuildWindscreen(Windscreen* windscreen) = 0;
	virtual ICarBuilder& BuildEngine(Engine* engine) = 0;
	virtual Car Build() = 0;
};

