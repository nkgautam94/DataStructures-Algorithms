#include "SortingAlgorithms/quick_sort.hpp"
#include "Utilities.hpp"

class QuickSortTester
{
public:
    static void execute()
    {
        // auto _vector_ = UTILITY::get_random_vector(20,0,20);
        std::vector<int> _vector_{3,0,2,4,3,2,1,3,4,5,6,0,0,1,2};
        // std::vector<int> _vector_{5,4,3,2,1};

        QuickSort::quick_sort(_vector_);

        for(auto element : _vector_)
            std::cout << element << " ";
        std::cout<<std::endl;

        return;
    }
};