#ifndef QUARTERDISCOUNTSTRATEGY_H
#define QUARTERDISCOUNTSTRATEGY_H

#pragma once

class QuarterDiscountStrategy : public DiscountStratery
{
public:
    double processDiscount(double price) override{
        return price * 0.75;
    }
};

#endif