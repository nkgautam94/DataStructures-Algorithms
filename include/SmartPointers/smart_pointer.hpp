#pragma once
#include<iostream>

template<typename _class_>
class smart_pointer
{
private:
    _class_ *_pointer_{nullptr};
    bool _free_memory_{false};
public:
    smart_pointer()
    {
        this->_pointer_ = new _class_();
        this->_free_memory_ = true;
    }


    _class_ * operator -> () {return this->_pointer_;}
    _class_ & operator * () {return *(this->_pointer_);}

    ~smart_pointer()
    {
        if(this->_free_memory_)
        {
            delete this->_pointer_;
        }
    };
};

template<typename _class_>
smart_pointer<_class_> make_smart_pointer()
{
    return smart_pointer<_class_>();
}