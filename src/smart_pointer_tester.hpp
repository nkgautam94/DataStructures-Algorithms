#include "SmartPointers/smart_pointer.hpp"
#include<memory>

class smatr_pointer_tester
{
public:

    class test
    {
    public:
        int var{0};
        test(){std::cout << "test created " << std::endl;}
        ~test(){std::cout << "test destroyed " << std::endl;}
    };

    static void execute()
    {
        test t;
        smart_pointer<test> ptr1 = make_smart_pointer<test>();
        std::unique_ptr<test> ptr2 = std::make_unique<test>();
    }
};