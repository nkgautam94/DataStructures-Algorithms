#pragma once
#include<iostream>
#include<vector>

class CircularQueue
{
private:
    int _max_size_{0};
    int _current_size_{0};
    int _front_{0};
    int _rear_{-1};
    std::vector<int> _buffer_;

public:
    CircularQueue() = delete;
    CircularQueue(int size):_max_size_(size)
    {
        _buffer_.resize(_max_size_);
    }
    ~CircularQueue(){ this->_buffer_.clear();}

    void insert(int data)
    {
        if(_current_size_ == _max_size_)
        {
            std::cout << "Queue is Full!" << std::endl;
            return;
        }

        if(_current_size_ < _max_size_)
        {
            if(this->_rear_ == _max_size_-1)
                this->_rear_ = 0;
            else
                this->_rear_++;

            this->_buffer_[this->_rear_] = data;
            this->_current_size_++;
        }
    }

    int pop_front()
    {
        if(this->_current_size_ == 0)
        {
            std::cout << "Queue is Empty!" << std::endl;
        }

        if(this->_current_size_ > 0)
        {
            int return_value = this->_buffer_[this->_front_];
            this->_buffer_[this->_front_] = 0;

            if(this->_front_ == _max_size_-1)
                this->_front_ = 0;
            else
                this->_front_++;

            this->_current_size_--;
            if(this->_current_size_ == 0)
            {
                this->_rear_ = -1;
                this->_rear_ = -1;
            }
            return return_value;
        }
        return -1;
    }

    int peek_front()
    {
        if(this->_current_size_ > 0)
            return this->_buffer_[this->_front_];
        else
            return -1;
    }

    int size()
    {
        return this->_current_size_;
    }

    bool empty()
    {
        return (this->_current_size_ == 0);
    }

};