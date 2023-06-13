#include <string>
#include "Engine.h"
#include "SeatBelt.h"
#include "Windscreen.h"

#pragma once
class Car
{
public:
	Car() = default;
	Car(int numberOfWheels, SeatBelt* seatBelt, std::string color, Windscreen* windscreen, Engine* engine);
	int getNumberOfWheels();
	void setNumberOfWheels(int numberOfWheels);
	SeatBelt* getSeatBelt();
	void setSeatBelt(SeatBelt* seatBelt);
	std::string getColor();
	void setColor(std::string color);
	Windscreen* getWindscreen();
	void setWindscreen(Windscreen* windscreen);
	Engine* getEngine();
	void setEngine(Engine* engine);
	std::string printLog();
private:
	int _numberOfWheels;
	SeatBelt *_seatBelt;
	std::string _color;
	Windscreen* _windscreen;
	Engine* _engine;
};

