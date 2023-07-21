#include <iostream>
#include <memory>

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
    Transport* createTransport(TransportType transportType) {
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
    TransportFactory factory;
    Transport* transport = factory.createTransport(TransportType::Truck);
    transport->deliver();
    transport = factory.createTransport(TransportType::Ship);
    transport->deliver();

    return 0;
}
