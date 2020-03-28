#pragma once
#include<iostream>
#include<vector>

enum TraversalOrder{PreOrder, Inorder, PostOrder};

class BinarySearchTree
{
protected:
    class Node
    {
    private:
        int _data_{int()};
        Node *_left_{nullptr};
        Node *_right_{nullptr};
    public:
        Node(){}
        Node(int _data_value_):_data_(_data_value_){}
        int & data(){return this->_data_;}
        Node * & left(){return this->_left_;}
        Node * & right(){return this->_right_;}
    };
    Node *_root_{nullptr};

    Node * insert(Node *current_node,int _data_value_)
    {
        if(current_node == nullptr)
            return new Node(_data_value_);
        if(_data_value_ > current_node->data())
            current_node->right() = insert(current_node->right(),_data_value_);
        if(_data_value_ < current_node->data())
            current_node->left() = insert(current_node->left(),_data_value_);
        return current_node;
    }

    int get_depth(Node *current_node)
    {
        if(current_node == nullptr)
            return 0;
        return std::max(get_depth(current_node->left()), get_depth(current_node->right())) + 1;
    }

public:
    BinarySearchTree(){}
    BinarySearchTree(const std::vector<int> &_vector_)
    {
        for(auto element : _vector_)
            this->insert(element);
    }

    void insert(int _data_value_)
    {
        this->_root_ = this->insert(this->_root_,_data_value_);
    }

    void traverse(Node *current_node, TraversalOrder _torder_ = TraversalOrder::Inorder)
    {
        if(current_node == nullptr)
            return;

        if(_torder_ == TraversalOrder::PreOrder)
        {
            std::cout<< current_node->data() << " ";
            traverse(current_node->left(),_torder_);
            traverse(current_node->right(),_torder_);
        }
        if(_torder_ == TraversalOrder::Inorder)
        {
            traverse(current_node->left(),_torder_);
            std::cout<< current_node->data() << " ";
            traverse(current_node->right(),_torder_);
        }
        if(_torder_ == TraversalOrder::PostOrder)
        {
            traverse(current_node->left(),_torder_);
            traverse(current_node->right(),_torder_);
            std::cout<< current_node->data() << " ";
        }
    }

    friend std::ostream & operator << (std::ostream &output_stream,BinarySearchTree &tree)
    {
        tree.traverse(tree._root_,TraversalOrder::Inorder);
        return output_stream;
    }

    int get_depth()
    {
        return this->get_depth(this->_root_);
    }
};