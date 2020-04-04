#include "Heap.hpp"
#include<vector>
#include<algorithm>
#include<random>

class MedianTracker
{
private:
    static Heap left_heap;
    static Heap right_heap;
public:

    static void insert(int element)
    {
        if(left_heap.empty()){left_heap.insert(element);return;}

        if(right_heap.empty())
        {
            if(element > left_heap.peek_top())
                right_heap.insert(element);
            else
            {
                right_heap.insert(left_heap.pop_top());
                left_heap.insert(element);
            }
            return;
        }

        if(left_heap.size() == right_heap.size())
        {
            if(element < left_heap.peek_top())
                left_heap.insert(element);
            else
                right_heap.insert(element);
            return;
        }

        if(left_heap.size() < right_heap.size())
        {
            if(element > right_heap.peek_top())
            {
                left_heap.insert(right_heap.pop_top());
                right_heap.insert(element);
            }
            else
                left_heap.insert(element);
            return;
        }

        if(right_heap.size() < left_heap.size())
        {
            if(element < left_heap.peek_top())
            {
                right_heap.insert(left_heap.pop_top());
                left_heap.insert(element);
            }
            else
                right_heap.insert(element);
            return;
        }
    }

    static int current_median()
    {
        if(left_heap.size() > right_heap.size())
            return left_heap.peek_top();
        else if(right_heap.size() > left_heap.size())
            return right_heap.peek_top();
        else
            return (left_heap.peek_top() + right_heap.peek_top())/2;
    }
};
Heap MedianTracker::left_heap{HeapType::MaxHeap};
Heap MedianTracker::right_heap{HeapType::MinHeap};

class MedianDataStream
{
public:

    static std::vector<int> get_random_vector()
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(-10,10);
        int size = 100;
        std::vector<int> random_vector;
        for(int i=0; i<size; i++)
            random_vector.push_back(distribution(generator));
        return random_vector;
    }

    static void exeute()
    {
        std::vector<int> _vector_ = get_random_vector();
        for(auto element : _vector_)
        {
            MedianTracker::insert(element);
            std::cout << element << " Inserted ";
            std::cout << "|";
            std:: cout << "{" << MedianTracker::current_median() << "} ";
            std:: cout << std::endl;
        }
    }
};