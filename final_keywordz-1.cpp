#include <iostream>

class Base {
public:
    virtual void print()  {
        std::cout << "Base::print()" << std::endl;
    }

    virtual void process() {
        std::cout << "Base::process()" << std::endl;
    }
};

class Derived : public Base {
public:
    // Correctly overrides a virtual function from the base class
    void print()   {
        std::cout << "Derived::print()" << std::endl;
    }

    //Error: Intended to override, but the signature doesn't match the base class
    void process()  override {
        std::cout << "Derived::process()" << std::endl;
    }
};

int main() {
    Base base;
    Derived derived;

    base.print();   // Calls Base::print()
    base.process(); // Calls Base::process()

    derived.print();   // Calls Derived::print()
    derived.process(); // Calls Base::process() because Derived::process is commented out

    return 0;
}
