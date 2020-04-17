#pragma once
#include<iostream>
#include<vector>

class QuickSort
{
private:
    static int partition(std::vector<int> &_vector_,int _low_, int _high_)
    {
        int pivot_index = (_low_ + _high_)/2;
        std::swap(_vector_[pivot_index],_vector_[_high_]);
        pivot_index = _high_;
        _high_--;

        while(_low_ <= _high_)
        {
            if(_vector_[_low_] <= _vector_[pivot_index])
                _low_++;

            if(_vector_[_high_] > _vector_[pivot_index])
                _high_--;

            if(_low_ < _high_)
                std::swap(_vector_[_low_],_vector_[_high_]);
        }

        std::swap(_vector_[_low_],_vector_[pivot_index]);
        return _low_;
    }

    static void quick_sort_recur(std::vector<int> &_vector_, int _low_, int _high_)
    {
        if(_low_ < _high_)
        {
            int partition_index = partition(_vector_,_low_,_high_);
            quick_sort_recur(_vector_,_low_,partition_index-1);
            quick_sort_recur(_vector_,partition_index+1,_high_);
        }
    }

public:
    static void quick_sort(std::vector<int> &_vector_)
    {
        quick_sort_recur(_vector_,0,_vector_.size()-1);
    }
};