#include <iostream>

class Beverage{
public:
    virtual std::string getDescription() = 0;
    virtual double Cost() = 0;
};

class MilkTea : public Beverage{
public:
    std::string getDescription() override{
        return "MilkTea"; 
    }
    double Cost() override{
        return 15000;
    }
};

class MilkTeaDecorator : public Beverage{
public:
    MilkTeaDecorator(Beverage *beverage) : _beverage(beverage) {}
    double Cost() override{
        return _beverage->Cost();
    }
    std::string getDescription() override{
        return _beverage->getDescription();
    }
protected:
    Beverage *_beverage;
};

class Pearl : public MilkTeaDecorator{
public: 
    Pearl(Beverage *beverage) : MilkTeaDecorator(beverage){ 
    }
    std::string getDescription() override{
        return _beverage->getDescription() + " + Pearl";
    }
    double Cost() override {
        return 5000 + _beverage->Cost();
    }
};

class EggPudding : public MilkTeaDecorator{
public: 
    EggPudding(Beverage *beverage) : MilkTeaDecorator(beverage){ 
    }
    std::string getDescription() override{
        return _beverage->getDescription() + " + EggPudding";
    }
    double Cost() override {
        return 7000 + _beverage->Cost();
    }
};

class FruitPudding : public MilkTeaDecorator{
public: 
    FruitPudding(Beverage *beverage) : MilkTeaDecorator(beverage){ 
    }
    std::string getDescription() override{
        return _beverage->getDescription() + " + FruitPudding";
    }
    double Cost() override {
        return 10000 + _beverage->Cost();
    }
};

class Cheese : public MilkTeaDecorator{
public: 
    Cheese(Beverage *beverage) : MilkTeaDecorator(beverage){ 
    }
    std::string getDescription() override{
        return _beverage->getDescription() + " + Cheese";
    }
    double Cost() override {
        return 15000 + _beverage->Cost();
    }
};

int main(){
    Beverage *milkTea_1 = new EggPudding(new Pearl(new FruitPudding(new MilkTea)));
    std::cout << "Order 1:" << std:: endl;
    std::cout << "\tDescription: "  << milkTea_1->getDescription() << std::endl;
    std::cout << "\tCost: "  <<milkTea_1->Cost() << std::endl;

    Beverage *milkTea_2 = new EggPudding(new Pearl(new Cheese(new MilkTea)));
    std::cout << "Order 2:" << std:: endl;
    std::cout << "\tDescription: "  << milkTea_2->getDescription() << std::endl;
    std::cout << "\tCost: "  <<milkTea_2->Cost() << std::endl;
}