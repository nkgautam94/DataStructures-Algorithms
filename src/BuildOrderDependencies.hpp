#include<iostream>
#include "Graph.hpp"

class BuildOrder
{
public:

    class DependencyGraph : public Graph
    {
    private:
        enum State {visited, unvisited, current};
        std::vector<int> _build_order_;
    public:
        DependencyGraph(int node_count, GraphType type = GraphType::Undirected) : Graph(node_count,type){}

        bool _traverse_(int current_node, std::vector<State> &node_state)
        {
            if(node_state[current_node] == State::unvisited)
                node_state[current_node] = State::current;
            else
            {
                if(node_state[current_node] == State::current)
                    return false;
                if(node_state[current_node] == State::visited)
                    return true;
            }

            for(auto &neighbour : _graph_list_[current_node])
            {
                if(!_traverse_(neighbour, node_state))
                    return false;
            }

            node_state[current_node] = State::visited;
            _build_order_.insert(_build_order_.begin(),current_node);

            return true;
        }

        void get_build_order()
        {
            std::vector<State> node_state(_nodes_, State::unvisited);

            for(int current_node = 0; current_node < _nodes_ ; current_node++)
            {
                bool cycle_present = _traverse_(current_node, node_state);
                if(!cycle_present)
                {
                    std::cout << "Build Order Not Possible, Cycle Present! " << std::endl;
                    return;
                }
            }
            std::cout << "Build Order : ";
            for(auto item : _build_order_)
                std::cout << item << " ";
            std::cout<<std::endl;
        }
    };

    static void execute()
    {
        // DependencyGraph _graph_(8, GraphType::Directed);
        // _graph_.insert(0,1);
        // _graph_.insert(0,2);
        // _graph_.insert(1,3);
        // _graph_.insert(2,3);
        // _graph_.insert(2,5);
        // _graph_.insert(2,4);
        // _graph_.insert(3,4);
        // _graph_.insert(6,7);

        DependencyGraph _graph_(6, GraphType::Directed);
        _graph_.insert(0,1);
        _graph_.insert(1,4);
        _graph_.insert(1,5);
        // _graph_.insert(5,1);
        _graph_.insert(4,5);
        _graph_.insert(2,0);
        _graph_.insert(3,2);

        std::cout << _graph_ << std::endl;
        _graph_.get_build_order();
    }
};