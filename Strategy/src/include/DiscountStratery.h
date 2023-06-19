#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#pragma once

class DiscountStratery
{
public:
    virtual double processDiscount(double price) = 0;
};

#endif