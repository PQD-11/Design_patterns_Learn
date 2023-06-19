#ifndef TICKET_H
#define TICKET_H

#pragma once
// #include <string>
#include "DiscountStratery.h"

class Ticket
{
public:
    Ticket() {}
    Ticket(DiscountStratery* discountStrategy){
        _discountStrategy = discountStrategy;
    }
    ~Ticket() {}

    DiscountStratery* GetDiscountStrategy(){
        return _discountStrategy;
    }
    void SetDiscountStrategy(DiscountStratery* discountStrategy){
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
    double DoDiscount(){
        return _discountStrategy->processDiscount(_price);
    }
private:
    DiscountStratery* _discountStrategy;
    double _price;
    std::string _name;
};

#endif