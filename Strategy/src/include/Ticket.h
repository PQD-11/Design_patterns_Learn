#ifndef TICKET_H
#define TICKET_H

#pragma once
#include <string>
#include "IPromoteStrategy.h"

class Ticket
{
public:
    Ticket();
    Ticket(IPromoteStrategy* promoteStrategy);
    ~Ticket();
    IPromoteStrategy* GetPromoteStrategy();
    void SetPromoteStrategy(IPromoteStrategy* promoteStrategy);
    double GetPrice();
    void SetPrice(double value);
    std::string GetName();
    void SetName(std::string value);
    double GetPromotedPrice();
private:
    IPromoteStrategy* _promoteStrategy;
    double _price;
    std::string _name;
};

#endif