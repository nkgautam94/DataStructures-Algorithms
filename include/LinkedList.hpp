#pragma once
#include<iostream>
#include<vector>

enum InsertPosition{Begin, End};

class LinkedList
{
private:
    class Node
    {
    private:
        int _data_{int()};
        Node *_next_{nullptr};
    public:
        Node(){}
        Node(int _data_value_):_data_(_data_value_){}
        int & data(){return this->_data_;}
        Node * & next(){return this->_next_;}
    };
    Node *_head_{nullptr};
public:
    LinkedList(){}
    LinkedList(const std::vector<int> &_vector_, InsertPosition _position_ = InsertPosition::End)
    {
        for(auto element : _vector_)
            this->insert(element,_position_);
    }

    void insert(int _data_value_, InsertPosition _position_ = InsertPosition::End)
    {
        if(this->_head_ == nullptr)
        {
            this->_head_ = new Node(_data_value_);
            return;
        }

        if(_position_ == InsertPosition::Begin)
        {
            Node *temp_node = new Node(_data_value_);
            temp_node->next() = this->_head_;
            this->_head_ = temp_node;
        }

        if(_position_ == InsertPosition::End)
        {
            auto iterator = this->_head_;
            while (iterator && iterator->next() != nullptr)
                iterator = iterator->next();
            iterator->next() = new Node(_data_value_);
        }
        return;
    }

    void traverse()
    {
        auto iterator = this->_head_;
        while (iterator)
        {
            std::cout<< iterator->data() << " ";
            iterator = iterator->next();
        }
        return;
    }

    friend std::ostream & operator << (std::ostream &output_stream,LinkedList &list)
    {
        list.traverse();
        return output_stream;
    }

};