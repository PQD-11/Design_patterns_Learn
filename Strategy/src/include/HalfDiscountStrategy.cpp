#include "HalfDiscountStrategy.h"

double HalfDiscountStrategy::DoDiscount(double price)
{
    return price * 0.5;
}
