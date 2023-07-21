#include <iostream>

class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};

class Truck : public Transport {
public:
    void deliver() override {
        std::cout << "Vận chuyển hàng hóa bằng xe tải." << std::endl;
    }
};

class Airplane : public Transport {
public:
    void deliver() override {
        std::cout << "Vận chuyển hàng hóa bằng máy bay." << std::endl;
    }
};

class Ship : public Transport {
public:
    void deliver() override {
        std::cout << "Vận chuyển hàng hóa bằng tàu chở hàng." << std::endl;
    }
};

enum class TransportType {
    Truck,
    Airplane,
    Ship
};

class TransportFactory {
public:
    virtual Transport* createTransport(TransportType transportType) = 0;
    virtual ~TransportFactory() {}
};

class NormalTransport : public TransportFactory{
public:
    Transport* createTransport(TransportType transportType) override{
        switch (transportType) {
            case TransportType::Truck:
                return new Truck();
            case TransportType::Airplane:
                return new Airplane();
            case TransportType::Ship:
                return new Ship();
            default:
                throw std::invalid_argument("Loại phương tiện không hợp lệ.");
        }
    }
};

int main() {
    TransportFactory* factory = new NormalTransport();

    Transport* truck  = factory->createTransport(TransportType::Truck);
    truck->deliver();

    Transport* airplane  = factory->createTransport(TransportType::Airplane);
    airplane->deliver();

    Transport* ship  = factory->createTransport(TransportType::Ship);
    ship->deliver();

    delete truck;
    delete airplane;
    delete ship;

    return 0;
}
