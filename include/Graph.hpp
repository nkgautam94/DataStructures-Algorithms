#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<queue>

enum GraphType { Directed, Undirected};
enum State {visited, unvisited, current};
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

    void BFS()
    {
        std::queue<int> node_queue;
        std::vector<State> node_state(_nodes_,State::unvisited);
        std::vector<int> bfs_order;

        for(int current_node = 0; current_node < _nodes_; current_node++)
        {
            if(node_state[current_node] == State::unvisited)
            {
                node_queue.push(current_node);
                node_state[current_node] = State::current;
            }

            while (!node_queue.empty())
            {
                int node = node_queue.front();
                node_queue.pop();
                node_state[node] = State::visited;
                bfs_order.push_back(node);

                for(auto neighbours : _graph_list_[node])
                {
                    if(node_state[neighbours] != State::unvisited)
                        continue;
                    node_state[neighbours] = State::current;
                    node_queue.push(neighbours);
                }
            }
        }

        std::cout << "BFS Order : ";
        for(auto item : bfs_order)
            std::cout << item << " ";
        std::cout << std::endl;
        return;
    }

    friend std::ostream & operator << (std::ostream &output_stream, Graph &graph)
    {
        graph.DFS();
        return output_stream;
    }
};