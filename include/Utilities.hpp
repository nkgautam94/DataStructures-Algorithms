#pragma once
#include<vector>
#include<random>

namespace UTILITY
{
    std::vector<int> get_random_vector(int _size_, int _min_, int _max_)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(_min_,_max_);
        std::vector<int> random_vector;
        for(int i=0; i<_size_; i++)
            random_vector.push_back(distribution(generator));
        return random_vector;
    }
}

