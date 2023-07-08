#include <iostream>
#include <list>
#include <string>

class Observer {
    public:
        ~Observer(){};
        virtual void notify() = 0;
};

class Subject {
    private:
        std::list<Observer *> observers;
    public:
        void RegisterObserver(Observer* observer) {
            observers.push_back(observer);
        }
        void UnregisterObserver(Observer* observer) {
        observers.remove(observer);
        }
        void NotifyObservers(){                        
            for (auto observer: observers) observer->notify();
        }
};

class Sensor : public Subject{
    private:
        bool _rainState;
    public:
        bool GetRainState()
        {
            return _rainState;
        }

        void SetRainState(bool value)
        {
            _rainState = value;
            NotifyObservers();
        }
};

class EmailNotifier : public Observer {
    private: 
        Subject* _subject;  
    public:
        EmailNotifier(Subject* subject) : _subject(subject) {
            _subject->RegisterObserver(this);
        }
        void notify() override {
            Sensor* sensor = static_cast<Sensor*>(_subject);
            if (sensor->GetRainState()){
                std::cout<<"\t=> Thông báo cho tất cả người đăng ký qua EMAIL sắp có mưa" <<std::endl;
            }
        }                              
};

class SMSNotifier : public Observer {
    private: 
        Subject* _subject; 
    public:
        SMSNotifier(Subject* subject) : _subject(subject) {
            _subject->RegisterObserver(this);
        }
        void notify() override {
            Sensor* sensor = static_cast<Sensor*>(_subject);
            if (sensor->GetRainState()){
                std::cout<<"\t=> Thông báo cho tất cả người đăng ký qua SMS sắp có mưa" <<std::endl;
            }
        }                                    
};


int main() {

    Sensor sensor;   
    EmailNotifier emailNotifier(&sensor);
    SMSNotifier smsNotifier(&sensor);
    std::cout <<"+ 1: Giả định tín hiệu mưa từ sensor"<<std::endl;
    sensor.SetRainState(true);
    std::cout << '\n';

    std::cout <<"+ 2: Giả định tính hiệu không có mưa từ sensor"<<std::endl;
    sensor.SetRainState(false);
    std::cout << '\n';

    std::cout <<"* UnregisterObserver: Email"<<std::endl;
    sensor.UnregisterObserver(&emailNotifier);
    std::cout <<"+ 3: Giả định tín hiệu mưa từ sensor"<<std::endl;
    sensor.SetRainState(true);
}