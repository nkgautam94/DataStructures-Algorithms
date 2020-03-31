#pragma once
#include<iostream>

namespace gautam
{
    template<typename KeyType,typename ValueType>
    class map
    {
    private:
        class node;
        node *_entry_point_{nullptr};
        enum Position{Begin,End};

        node * insert(node *current_node, KeyType key, ValueType value)
        {
            if(current_node == nullptr)
                return new node(key,value);
            if(key > current_node->key())
                current_node->right() = insert(current_node->right(),key,value);
            if(key < current_node->key())
                current_node->left() = insert(current_node->left(),key,value);
            return current_node;
        }

        void _inorder_(node *current_node)
        {
            if(current_node)
            {
                _inorder_(current_node->left());
                std::cout << "{" << current_node->key() << ":" << current_node->value() << "} ";
                _inorder_(current_node->right());
            }
        }

        node *_find_or_insert_(node *current_node, KeyType _key_, node * &required_node)
        {
            if(current_node == nullptr)
            {
                required_node = new node(_key_,ValueType());
                return required_node;
            }
            if(current_node->key() == _key_)
            {
                required_node = current_node;
                return current_node;
            }
            if(_key_ > current_node->key())
                current_node->right() = _find_or_insert_(current_node->right(),_key_,required_node);
            if(_key_ < current_node->key())
                current_node->left() = _find_or_insert_(current_node->left(),_key_,required_node);
            return current_node;
        }

        node * find_min(node *entry_point)
        {
            auto current_node = entry_point;
            while (current_node && current_node->left())
                current_node = current_node->left();
            return current_node;
        }

        void get_inorder_successor(node *current_node, node*_node_, node * &inorder_successor)
        {
            if(current_node == _node_)
                return;
            if(_node_->key() > current_node->key())
                get_inorder_successor(current_node->right(),_node_,inorder_successor);
            if(_node_->key() < current_node->key())
            {
                inorder_successor = current_node;
                get_inorder_successor(current_node->left(),_node_,inorder_successor);
            }
        }

        node * get_inorder_successor(node *_node_)
        {
            node *inorder_successor = nullptr;
            if(_node_->right())
                inorder_successor =  find_min(_node_->right());
            else
                get_inorder_successor(_entry_point_,_node_,inorder_successor);
            return inorder_successor;
        }

        void delete_node(node *current_node)
        {
            if(current_node)
            {
                delete_node(current_node->left());
                delete_node(current_node->right());
                delete current_node;
            }
        }

    public:
        map(){}
        class iterator;

        node & operator[](KeyType _key_)
        {
            node *required_node = nullptr;
            _entry_point_ =  _find_or_insert_(_entry_point_,_key_,required_node);
            return *required_node;
        }

        ~map(){this->delete_node(this->_entry_point_);}
        void insert(KeyType key, ValueType value){this->_entry_point_ = this->insert(this->_entry_point_,key,value);}
        friend std::ostream & operator << (std::ostream &output_stream,map &_map_){_map_._inorder_(_map_._entry_point_);return output_stream;}
        iterator begin() { return iterator(Position::Begin,*this); }
        iterator end() { return iterator(Position::End,*this); }
    };

    template<typename KeyType,typename ValueType>
    class map<KeyType,ValueType>::node
    {
    private:
        KeyType _key_{KeyType()};
        ValueType _value_{ValueType()};
        node * _left_{nullptr};
        node *_right_{nullptr};
    public:
        node(){}
        ~node(){}
        node(KeyType key,ValueType value):_key_(key),_value_(value){}
        node(std::pair<KeyType,ValueType> _pair_):node(_pair_.first,_pair_.second){}
        KeyType & key() {return this->_key_;}
        ValueType & value() {return this->_value_;}
        node * & left() {return this->_left_;}
        node * & right() {return this->_right_;}
        friend std::ostream & operator << (std::ostream &output_stream,node &_node_) {output_stream << _node_.value(); return output_stream;}
        void operator = (ValueType value) {this->value() = value;}
    };

    template<typename KeyType,typename ValueType>
    class map<KeyType,ValueType>::iterator
    {
    private:
        node *current_node{nullptr};
        map *current_map{nullptr};
    public:
        iterator(){}
        ~iterator(){this->current_map = nullptr; this->current_node = nullptr;}
        iterator(Position _position_,map &_map_):current_map(&_map_)
        {
            if(_position_ == Position::Begin)
                current_node = _map_.find_min(_map_._entry_point_);
            if(_position_ == Position::End)
                current_node = nullptr;
        }
        std::pair<KeyType,ValueType> operator * () {return std::make_pair(current_node->key(),current_node->value());}
        std::pair<KeyType,ValueType> operator -> () {return this->operator*();}
        iterator & operator ++ () {this->current_node = this->current_map->get_inorder_successor(this->current_node);return *this;}
        iterator & operator ++ (int) {return this->operator++();}
        bool operator == (const iterator &other_iterator) const {return this->current_node == other_iterator.current_node;}
        bool operator != (const iterator &other_iterator) const {return this->current_node != other_iterator.current_node;}
    };
}