#include<iostream>
#include<vector>
#include<thread>
#include<future>

class SleepSort
{
public:
    static void execute()
    {
        std::vector<int> _vector_{2,3,4,5,4,2,3,4,5,6};
        std::vector<std::future<void>> _future_;
        for(auto _number_ : _vector_)
        {
            _future_.push_back(std::async(std::launch::async,
                [](int _number_)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(_number_));
                    std::cout << _number_ << " ";
                }
                ,_number_));
        }
        std::cout<<std::endl;
    }
};