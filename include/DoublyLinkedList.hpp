#pragma once
#include "LinkedList.hpp"

class DoublyLinkedList
{
private:
protected:
    class Node
    {
    private:
        int _data_{int()};
        Node *_next_{nullptr};
        Node *_prev_{nullptr};
    public:
        Node(){}
        Node(int _data_value_):_data_(_data_value_){}
        ~Node(){}
        int & data(){return this->_data_;}
        Node * & next(){return this->_next_;}
        Node * & prev(){return this->_prev_;}
    };
    Node *_head_{nullptr};
    void _delete_(Node *current_node)
    {
        if(current_node == nullptr) return;
        _delete_(current_node->next());
        delete current_node;
    }
public:
    enum InsertPosition{Begin, End};
    DoublyLinkedList(){}
    DoublyLinkedList(const std::vector<int> &_vector_, InsertPosition _position_ = InsertPosition::End)
    {
        for(auto element : _vector_)
            this->insert(element,_position_);
    }
    ~DoublyLinkedList(){this->_delete_(this->_head_);}

    void insert(int _data_value_, InsertPosition _position_ = InsertPosition::End)
    {
        if(this->_head_ == nullptr)
        {
            this->_head_ = new Node(_data_value_);
            this->_head_->prev() = nullptr;
            return;
        }

        if(_position_ == InsertPosition::Begin)
        {
            Node *temp_node = new Node(_data_value_);
            temp_node->next() = this->_head_;
            temp_node->prev() = nullptr;
            this->_head_->prev() = temp_node;
            this->_head_ = temp_node;
        }

        if(_position_ == InsertPosition::End)
        {
            auto iterator = this->_head_;
            while (iterator && iterator->next() != nullptr)
                iterator = iterator->next();

            auto temp_node = new Node(_data_value_);
            temp_node->prev() = iterator;
            iterator->next() = temp_node;
        }
        return;
    }

    void traverse()
    {
        auto iterator = this->_head_;
        std::cout << "{Current} {next} {prev}" << std::endl;
        while (iterator)
        {
            std::cout << "{" << iterator->data() << "} ";

            if(iterator->next())
                std::cout << "{" << iterator->next()->data() << "} ";
            else
                std::cout << "nullptr ";

            if(iterator->prev())
                std::cout << "{" << iterator->prev()->data() << "} ";
            else
                std::cout << "nullptr ";


            std::cout << std::endl;
            iterator = iterator->next();
        }
        return;
    }

    friend std::ostream & operator << (std::ostream &output_stream,DoublyLinkedList &list)
    {
        list.traverse();
        return output_stream;
    }
};