#include <iostream>
#include <string>

class Singleton{
    private:
        static Singleton *uniqueInstance;
        int _value;
        Singleton(){
            _value = 0;
        }
    public:
        static Singleton *getSingleton(){
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

int main(){
    Singleton *s = Singleton::getSingleton();
    std::cout << s->getValue() << std::endl;
    Singleton *s1 = Singleton::getSingleton();
    s1->setValue(4);
    std::cout << s->getValue() << std::endl;
    std::cout << s1->getValue() << std::endl;
    return 0;
}

/* result:
 - 0
 - 4
 - 4
*/