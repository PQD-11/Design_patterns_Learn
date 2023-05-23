#include "Ticket.h"

Ticket::Ticket()
{

}

Ticket::Ticket(IPromoteStrategy* promoteStrategy)
{
    _promoteStrategy = promoteStrategy;
}

Ticket::~Ticket()
{

}

IPromoteStrategy* Ticket::GetPromoteStrategy()
{
    return _promoteStrategy;
}

void Ticket::SetPromoteStrategy(IPromoteStrategy* promoteStrategy)
{
    _promoteStrategy = promoteStrategy;
}

double Ticket::GetPrice()
{
    return _price;
}

void Ticket::SetPrice(double value)
{
    _price = value;
}

std::string Ticket::GetName()
{
    return _name;
}

void Ticket::SetName(std::string value)
{
    _name = value;
}

double Ticket::GetPromotedPrice()
{
    return _promoteStrategy->DoDiscount(_price);
}
