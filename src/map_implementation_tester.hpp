#include<iostream>
#include<map>
#include "map_implementation.hpp"

class map_implementation_teste
{
public:
    static void execute()
    {
        gautam::map<int,std::string> my_map;

        my_map.insert(10,"nikhilesh");
        my_map.insert(20,"kumar");
        my_map.insert(30,"gautam");


        std::cout << my_map[50] << std::endl;

        my_map[40] = "test1";
        my_map[10] = "Nick2";


        for(auto entry : my_map)
            std::cout << "{" << entry.first << ":" << entry.second << "} ";
        std::cout<<std::endl;

        for(auto itr = my_map.begin(); itr != my_map.end(); itr++)
            std::cout << "{" << (*itr).first << ":" << (*itr).second << "} ";
        std::cout<<std::endl;

        std::cout << "Executed" << std::endl;
    }
};