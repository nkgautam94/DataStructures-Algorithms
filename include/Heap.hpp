#pragma once
#include<iostream>
#include<vector>

enum HeapType{MaxHeap, MinHeap};
class Heap
{
private:
    int left_index(int _index_){return 2 * _index_ + 1;}
    int right_index(int _index_){return 2 * _index_ + 2;}
    int parent_index(int _index_){return (_index_%2==0)?((_index_-2)/2):((_index_-1)/2);}
    bool check_bounds(int _index_){return ((_index_ >= 0)&&(_index_ <= this->_current_index_)); }
    enum Populate{Up, Down};

    bool _compare_(int value1, int value2)
    {
        if(this->_type_ == HeapType::MaxHeap){return std::less<int>()(value1,value2);}
        if(this->_type_ == HeapType::MinHeap){return std::greater<int>()(value1,value2);}
        return false;
    }

    void heapify_data(int index, Populate direction)
    {
        bool _swap_ = false;
        int _index_ = index;
        int _swap_index_;
        while(true)
        {
            _swap_ = false;
            if(direction == Populate::Up)
            {
                int parent_index = this->parent_index(_index_);
                if(!check_bounds(parent_index)) break;
                if(this->_compare_(this->_heap_[parent_index], this->_heap_[_index_]))
                    _swap_ = true;_swap_index_ = parent_index;
            }

            if(direction == Populate::Down)
            {
                int swap_value = this->_heap_[_index_];
                if(check_bounds(left_index(_index_)))
                    if(this->_compare_(swap_value, this->_heap_[left_index(_index_)]))
                    {
                        _swap_ = true; _swap_index_ = left_index(_index_);
                        swap_value = this->_heap_[left_index(_index_)];
                    }
                if(check_bounds(right_index(_index_)))
                    if(this->_compare_(swap_value, this->_heap_[right_index(_index_)]))
                    {
                        _swap_ = true; _swap_index_ = right_index(_index_);
                        swap_value = this->_heap_[right_index(_index_)];
                    }
            }
            if(_swap_)
            {
                std::swap(this->_heap_[_swap_index_],this->_heap_[_index_]);
                _index_ = _swap_index_;
            }
            else
                break;
        }
    }
public:
    Heap(HeapType type = HeapType::MaxHeap):_type_(type),_max_size_(64){this->_heap_.resize(_max_size_);}
    void insert(int data_value)
    {
        this->_current_index_++;
        if(this->_current_index_ >= _max_size_)
        {
            this->_max_size_ = 2 * this->_max_size_;
            this->_heap_.resize(this->_max_size_);
        }
        this->_heap_[this->_current_index_] = data_value;
        this->heapify_data(this->_current_index_,Populate::Up);
    }
    int pop_top()
    {
        std::swap(this->_heap_[0],this->_heap_[this->_current_index_]);
        this->_current_index_--;
        this->heapify_data(0,Populate::Down);
        return this->_heap_[this->_current_index_ + 1];
    }
    int peek_top(){return this->_heap_[0];}
    bool empty(){return (this->_current_index_ >= 0)?(false):(true);}

protected:
    HeapType _type_{HeapType::MaxHeap};
    int _max_size_{0};
    int _current_index_{-1};
    std::vector<int> _heap_;
};