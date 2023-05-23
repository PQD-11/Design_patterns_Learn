#ifndef NODISCOUNTSTRATEGY_H
#define NODISCOUNTSTRATEGY_H

#pragma once
#include "IPromoteStrategy.h"

class NoDiscountStrategy : public IPromoteStrategy
{
public:
    double DoDiscount(double price) override;
private:

};

#endif