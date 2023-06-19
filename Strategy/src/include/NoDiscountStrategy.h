#ifndef NODISCOUNTSTRATEGY_H
#define NODISCOUNTSTRATEGY_H

#pragma once

class NoDiscountStrategy : public DiscountStratery
{
public:
    double processDiscount(double price) override{
        return price;
    }
};

#endif