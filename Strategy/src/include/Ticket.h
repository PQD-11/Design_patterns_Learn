#ifndef TICKET_H
#define TICKET_H

#pragma once
#include "DiscountStrategy.h"

class Ticket
{
public:
    Ticket() {}
    Ticket(DiscountStrategy* discountStrategy){
        _discountStrategy = discountStrategy;
    }
    ~Ticket() {}

    DiscountStrategy* GetDiscountStrategy(){
        return _discountStrategy;
    }
    void SetDiscountStrategy(DiscountStrategy* discountStrategy){
        _discountStrategy = discountStrategy;
    }
    double GetPrice(){
        return _price;
    }
    void SetPrice(double value){
        _price = value;
    }
    std::string GetName(){
        return _name;
    }
    void SetName(std::string value){
        _name = value;
    }
    double processDiscount(){
        return _discountStrategy->processDiscount(_price);
    }
private:
    DiscountStrategy* _discountStrategy;
    double _price;
    std::string _name;
};

#endif