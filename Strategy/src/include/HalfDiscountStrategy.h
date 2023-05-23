#ifndef HALFDISCOUNTSTRATEGY_H
#define HALFDISCOUNTSTRATEGY_H

#pragma once
#include "IPromoteStrategy.h"

class HalfDiscountStrategy : public IPromoteStrategy
{
public:
    double DoDiscount(double price) override;
private:

};

#endif