#pragma once
#include<iostream>
#include<vector>

class BinaryTree
{
protected:
    enum TraversalOrder{PreOrder, Inorder, PostOrder};
    class Node
    {
    private:
        int _data_{int()};
        Node *_left_{nullptr};
        Node *_right_{nullptr};
    public:
        Node(){}
        Node(int _data_value_):_data_(_data_value_){}
        int &data(){return this->_data_;}
        Node * & left(){return this->_left_;}
        Node * & right(){return this->_right_;}
    };
    Node *_root_{nullptr};

    Node *generate_node(const std::vector<int> &_vector_, size_t index)
    {
        if(_vector_[index] == 0 || index >= _vector_.size())
            return nullptr;
        Node *current_node = new Node(_vector_[index]);
        current_node->left() = generate_node(_vector_, 2*index+1);
        current_node->right() = generate_node(_vector_, 2*index+2);
        return current_node;
    }

public:
    BinaryTree(){}
    BinaryTree(const std::vector<int> &_vector_)
    {
        this->_root_ = generate_node(_vector_,0);
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

    friend std::ostream & operator << (std::ostream &output_stream,BinaryTree &tree)
    {
        tree.traverse(tree._root_,TraversalOrder::Inorder);
        return output_stream;
    }
};