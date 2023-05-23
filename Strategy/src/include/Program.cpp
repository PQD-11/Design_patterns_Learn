#include<iostream>
#include<time.h>
#include "Ticket.h"
#include "IPromoteStrategy.h"
#include "HalfDiscountStrategy.h"
#include "NoDiscountStrategy.h"

using namespace std;

void GeneratePromoteStrategy(Ticket ticket, NoDiscountStrategy noDiscount, HalfDiscountStrategy halfDiscount)
{
    int strategyIndex = rand() % 2; //[0,1]
    switch (strategyIndex)
    {
    case 0:
        ticket.SetPromoteStrategy(&noDiscount);
        break;
    case 1:
        ticket.SetPromoteStrategy(&halfDiscount);
    default:
        break;
    }
    cout << "Promoted price of " + ticket.GetName() + " is " + to_string(ticket.GetPromotedPrice()) + " strategyIndex " + to_string(strategyIndex) <<endl;
}

int main()
{
    srand(time(NULL));
    cout <<"Start getting tickets!"<<endl;
    NoDiscountStrategy noDiscount;
    HalfDiscountStrategy halfDiscount;
    for (int i = 1; i  <= 5; i++)
    {
        Ticket ticket;
        ticket.SetName("Ticket" + to_string(i));
        ticket.SetPrice(50.0 * i);

        GeneratePromoteStrategy(ticket, noDiscount, halfDiscount);
    
        GeneratePromoteStrategy(ticket, noDiscount, halfDiscount);
    }
    return 0;
}