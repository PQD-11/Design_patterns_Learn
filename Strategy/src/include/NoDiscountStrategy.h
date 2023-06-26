#ifndef NODISCOUNTSTRATEGY_H
#define NODISCOUNTSTRATEGY_H

#pragma once

class NoDiscountStrategy : public DiscountStrategy
{
public:
    double processDiscount(double price) override{
        return price;
    }
};

#endif