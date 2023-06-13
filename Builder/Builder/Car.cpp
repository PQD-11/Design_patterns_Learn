#include "Car.h"

Car::Car(int numberOfWheels, SeatBelt *seatBelt, std::string color, Windscreen *windscreen, Engine *engine)
{
	_numberOfWheels = numberOfWheels;
	_seatBelt = seatBelt;
	_color = color;
	_windscreen = windscreen;
	_engine = engine;
}

int Car::getNumberOfWheels()
{
	return _numberOfWheels;
}

void Car::setNumberOfWheels(int numberOfWheels)
{
	_numberOfWheels = numberOfWheels;
}

SeatBelt* Car::getSeatBelt()
{
	return _seatBelt;
}

void Car::setSeatBelt(SeatBelt* seatBelt)
{
	_seatBelt = seatBelt;
}

std::string Car::getColor()
{
	return _color;
}

void Car::setColor(std::string color)
{
	_color = color;
}

Windscreen* Car::getWindscreen()
{
	return _windscreen;
}

void Car::setWindscreen(Windscreen* windscreen)
{
	_windscreen = windscreen;
}

Engine* Car::getEngine()
{
	return _engine;
}

void Car::setEngine(Engine* engine)
{
	_engine = engine;
}

std::string Car::printLog()
{ 
	std::string content= "";
	content += "Number of wheels:    \t" + std::to_string(_numberOfWheels) + "\n";
	content += "Brand of seat belts: \t" + _seatBelt->getBrand() + "\n";
	content += "Color:               \t" + _color + "\n";
	content += "Windscreen brand:    \t" + _windscreen->getName() + "\n";
	content += "Engine:              \t" + _engine->getName() + "\n";

	return content;
}

//string to_string() const {
//	stringstream stream;
//	stream << "from: " << m_from
//		<< "\nto: " << m_to
//		<< "\nsubject: " << m_subject
//		<< "\nbody: " << m_body;
//	return stream.str();
