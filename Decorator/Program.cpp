#include <iostream>

class IMilkTea{
public:
    virtual double Cost() = 0;
};

class MilkTea : public IMilkTea{
public:
    double Cost() override{
        return 5.0;
    }
};

class MilkTeaDecorator : public IMilkTea{
public:
    MilkTeaDecorator(IMilkTea *inner) : _milkTea(inner){
    }
    double Cost() override{
        return _milkTea->Cost();
    }
protected:
    IMilkTea *_milkTea;
};

class Pearl : public MilkTeaDecorator{
public: 
    Pearl(IMilkTea *inner) : MilkTeaDecorator(inner){ 
    }
    double Cost() override {
        return 1.0 + MilkTeaDecorator::Cost();
    }
};

class EggPudding : public MilkTeaDecorator{
public: 
    EggPudding(IMilkTea *inner) : MilkTeaDecorator(inner){ 
    }
    double Cost() override {
        return 1.5 + MilkTeaDecorator::Cost();
    }
};

class FruitPudding : public MilkTeaDecorator{
public: 
    FruitPudding(IMilkTea *inner) : MilkTeaDecorator(inner){ 
    }
    double Cost() override {
        return 2.0 + MilkTeaDecorator::Cost();
    }
};

int main(){
    IMilkTea *ourMilkTea = new EggPudding(new Pearl(new FruitPudding(new MilkTea)));
    std::cout << ourMilkTea->Cost();
}