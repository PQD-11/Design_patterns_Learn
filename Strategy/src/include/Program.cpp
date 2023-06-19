#include <iostream>
#include <time.h>
#include <string>
#include "Ticket.h"
#include "DiscountStratery.h"
#include "HalfDiscountStrategy.h"
#include "NoDiscountStrategy.h"
#include "QuarterDiscountStrategy.h"

using namespace std;

int main()
{
    Ticket ticketA;
    ticketA.SetName("TicketA");
    ticketA.SetPrice(100.000);
    ticketA.SetDiscountStrategy(new NoDiscountStrategy());
    cout << "The price of " + ticketA.GetName() + " is " + to_string(ticketA.DoDiscount()) + " with NoDiscount" <<endl;
    ticketA.SetDiscountStrategy(new HalfDiscountStrategy());
    cout << "The price of " + ticketA.GetName() + " is " + to_string(ticketA.DoDiscount()) + " with HalfDiscount" <<endl;
    ticketA.SetDiscountStrategy(new QuarterDiscountStrategy());
    cout << "The price of " + ticketA.GetName() + " is " + to_string(ticketA.DoDiscount()) + " with QuarterDiscount" <<endl;

    cout << "\n------------------------------------------------------- \n";

    Ticket ticketB;
    ticketB.SetName("TicketB");
    ticketB.SetPrice(20.000);
    ticketB.SetDiscountStrategy(new NoDiscountStrategy());
    cout << "The price of " + ticketB.GetName() + " is " + to_string(ticketB.DoDiscount()) + " with NoDiscount" <<endl;
    ticketB.SetDiscountStrategy(new HalfDiscountStrategy());
    cout << "The price of " + ticketB.GetName() + " is " + to_string(ticketB.DoDiscount()) + " with HalfDiscount" <<endl;
    ticketB.SetDiscountStrategy(new QuarterDiscountStrategy());
    cout << "The price of " + ticketB.GetName() + " is " + to_string(ticketB.DoDiscount()) + " with QuarterDiscount" <<endl;
    return 0;
}