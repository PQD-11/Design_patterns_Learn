#include <string>
#include "Engine.h"
#include "SeatBelt.h"
#include "Windscreen.h"
#include "Car.h"
#include "ICarBuilder.h"
#pragma once
class CarBuilder : ICarBuilder
{
private:
	Car car;
public:
	// Inherited via ICarBuilder
	virtual ICarBuilder& BuildWheels(int numberOfWheels) override;
	virtual ICarBuilder& BuildSeatBelt(SeatBelt* seatBelt) override;
	virtual ICarBuilder& BuiidColor(std::string color) override;
	virtual ICarBuilder& BuildWindscreen(Windscreen* windscreen) override;
	virtual ICarBuilder& BuildEngine(Engine* engine) override;
	virtual Car Build() override;
};

