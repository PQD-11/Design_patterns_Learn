//#include "Engine.h"
#include <iostream>
#include <string>
#include "Car.h"
#include "Engine.h"
#include "SeatBelt.h"
#include "Windscreen.h"
#include "CarBuilder.h"
int main()
{
    Car car(5, new SeatBelt("seat"), "red", new Windscreen("screen"), new Engine("motor"));
    std::cout << car.printLog();
    std::cout << "-------------------------------------\n";
    Car carbuilder = CarBuilder()
        .BuildWheels(4)
        .BuildSeatBelt(new SeatBelt("Seat Belt"))
        .BuiidColor("black")
        .BuildWindscreen(new Windscreen("Windscreen"))
        .BuildEngine(new Engine("Engine"))
        .Build();
    std::cout << carbuilder.printLog();
}

