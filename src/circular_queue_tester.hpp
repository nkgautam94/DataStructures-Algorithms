#pragma once
#include<vector>
#include "CircularQueue.hpp"

class circular_queue_tester
{
public:
    static void execute()
    {
        std::vector<int> _vector_{1,2,3,4,3,5,6,7,6,5,4,5,6,7,5};
        CircularQueue _queue_(6);

        int insert_index = 0;
        for(int i = 0; i < 5; i++)
        {
            _queue_.insert(_vector_[insert_index++]);
        }

        for(int i = 0; i < 3; i++)
        {
            std::cout << _queue_.pop_front() << " ";
        }

        for(int i = 0; i < 4; i++)
        {
            _queue_.insert(_vector_[insert_index++]);
        }

        while (_queue_.empty() == false)
        {
            _queue_.pop_front();
        }
    }
};