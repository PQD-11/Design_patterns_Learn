#include "CarBuilder.h"

ICarBuilder& CarBuilder::BuildWheels(int numberOfWheels)
{
	car.setNumberOfWheels(numberOfWheels);
	return *this;
}

ICarBuilder& CarBuilder::BuildSeatBelt(SeatBelt* seatBelt)
{
	car.setSeatBelt(seatBelt);
	return *this;
}

ICarBuilder& CarBuilder::BuiidColor(std::string color)
{
	car.setColor(color);
	return *this;
}

ICarBuilder& CarBuilder::BuildWindscreen(Windscreen* windscreen)
{
	car.setWindscreen(windscreen);
	return *this;
}

ICarBuilder& CarBuilder::BuildEngine(Engine* engine)
{
	car.setEngine(engine);
	return *this;
}

Car CarBuilder::Build()
{
	return car;
}
