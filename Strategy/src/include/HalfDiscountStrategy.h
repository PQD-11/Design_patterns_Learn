#ifndef HALFDISCOUNTSTRATEGY_H
#define HALFDISCOUNTSTRATEGY_H

#pragma once

class HalfDiscountStrategy : public DiscountStratery
{
public:
    double processDiscount(double price) override{
        return price * 0.5;
    }
};

#endif