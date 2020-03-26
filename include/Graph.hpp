#pragma once
#include<iostream>
#include<list>
#include<vector>
enum GraphType { Directed, Undirected};
class Graph
{
private:
    void _dfs_(int current_node, std::vector<bool> &visited)
    {
        if(visited[current_node] == true)
            return;
        std::cout << current_node << " ";
        visited[current_node] = true;
        for(auto &neighbour : _graph_list_[current_node])
            _dfs_(neighbour,visited);
    }
protected:
    GraphType _type_{GraphType::Undirected};
    int _nodes_{0};
    std::list<int> *_graph_list_{nullptr};
public:
    Graph(int node_count, GraphType type = GraphType::Undirected):_type_(type),_nodes_(node_count)
    {
        this->_graph_list_ = new std::list<int>[this->_nodes_];
    }

    void insert(int source, int destination)
    {
        this->_graph_list_[source].push_back(destination);
        if(this->_type_ == GraphType::Undirected)
            this->_graph_list_[destination].push_back(source);
        return;
    }

    void DFS()
    {
        std::vector<bool> visited(this->_nodes_,false);
        for(int current_node = 0; current_node < _nodes_; current_node++)
            _dfs_(current_node, visited);
    }

    friend std::ostream & operator << (std::ostream &output_stream, Graph &graph)
    {
        graph.DFS();
        return output_stream;
    }
};