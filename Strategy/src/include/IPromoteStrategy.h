#ifndef IPROMOTESTRATEGY_H
#define IPROMOTESTRATEGY_H

#pragma once

class IPromoteStrategy
{
public:
    IPromoteStrategy();
    ~IPromoteStrategy();
    virtual double DoDiscount(double price) = 0;

private:

};

#endif