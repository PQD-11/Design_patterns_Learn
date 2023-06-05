#include <iostream>
#include <string>
#include <time.h>
#include <thread>
#include <mutex>

class Singleton{
    private:
        static Singleton *uniqueInstance;
        static std::mutex mtx;
        int _value;
        Singleton(){
            srand(time(NULL));
            _value =  1 + (rand()%100);
            std::cout << _value << std::endl;
        }
    public:
        static Singleton *getSingleton(){
            std::lock_guard<std::mutex> lock(mtx);
            if (uniqueInstance == nullptr){
                uniqueInstance = new Singleton();
                return uniqueInstance;
            }
        }
        int getValue(){
            return _value;
        }
        void setValue(int value){
            _value = value;
        }
};

Singleton *Singleton::uniqueInstance = nullptr;
std::mutex Singleton::mtx;

void Thread1(){
    Singleton *s = Singleton::getSingleton();
}

void Thread2(){
    Singleton *s = Singleton::getSingleton();
}

int main(){
    std::thread t1(Thread1);
    std::thread t2(Thread2);
    t1.join();
    t2.join();
    return 0;
}

/* result:
 - 0
 - 4
 - 4
*/