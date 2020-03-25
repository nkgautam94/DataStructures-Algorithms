#include<iostream>
#include<vector>
#include<limits>

#include "BinaryTree.hpp"

class CheckBSTinBinaryTree
{
public:

    class BT : public BinaryTree
    {
    public:
        int absolute_max_size = std::numeric_limits<int>::min();
        int absolute_min = -1;
        int absolute_max = 1;
        BT(const std::vector<int> &_vector_):BinaryTree(_vector_){}

        int restrict_tree(Node *current_node, int &_min_, int &_max_)
        {
            if(current_node == nullptr)
                return 0;

            if(current_node->data() > _min_ && current_node->data() < _max_)
            {
                int max_size = 0;

                int left_min = _min_;
                int left_max = current_node->data();
                max_size += restrict_tree(current_node->left(),left_min, left_max);
                if(max_size == 0)
                    left_min = left_max = current_node->data();

                int right_min = current_node->data();
                int right_max = _max_;
                max_size += restrict_tree(current_node->right(),right_min,right_max);
                if(max_size == 0)
                    right_min = right_max = current_node->data();

                _min_ = std::min(current_node->data(),left_min);
                _max_ = std::max(current_node->data(),right_max);

                return max_size + 1;
            }
            return 0;
        }
        void check_if_BST(Node *current_node, int &max_size, int &_min_, int &_max_)
        {
            if(current_node->left() == nullptr && current_node->right() == nullptr)
            {
                max_size = 1;
                _min_ = _max_ = current_node->data();
                return;
            }

            int current_max = 0;
            int current_min = 0;
            int current_max_size = 0;

            int left_subtree_size = 0;
            int left_subtree_min = current_node->data();
            int left_subtree_max = current_node->data();
            if(current_node->left())
            {
                check_if_BST(current_node->left(),current_max_size,current_min,current_max);
                if(current_node->data() > current_max)
                {
                    left_subtree_size =  current_max_size;
                    left_subtree_min = current_min;
                    left_subtree_max = current_max;
                }
                else
                {
                    left_subtree_min = std::numeric_limits<int>::min();
                    left_subtree_max = current_node->data();
                    left_subtree_size = restrict_tree(current_node->left(),left_subtree_min,left_subtree_max);
                    if(left_subtree_size == 0)
                        left_subtree_max = left_subtree_min = current_node->data();
                }
                std::cout << "checking left subtree of " << current_node->data() << " : ";
                std::cout << left_subtree_size << "|" << left_subtree_min << "|" << left_subtree_max << std::endl;
            }

            int right_subtree_size = 0;
            int right_subtree_min = current_node->data();
            int right_subtree_max = current_node->data();
            if(current_node->right())
            {
                check_if_BST(current_node->right(),current_max_size,current_min,current_max);
                if(current_node->data() < current_min)
                {
                    right_subtree_size =  current_max_size;
                    right_subtree_min = current_min;
                    right_subtree_max = current_max;
                }
                else
                {
                    right_subtree_min = current_node->data();
                    right_subtree_max = std::numeric_limits<int>::max();
                    right_subtree_size = restrict_tree(current_node->right(),right_subtree_min,right_subtree_max);
                    if(right_subtree_size == 0)
                        right_subtree_max = right_subtree_min = current_node->data();
                }
                std::cout << "checking right subtree of " << current_node->data() << " : ";
                std::cout << right_subtree_size << "|" << right_subtree_min << "|" << right_subtree_max << std::endl;
            }
            max_size = left_subtree_size + right_subtree_size + 1;
            _min_ = std::min(current_node->data(),left_subtree_min);
            _max_ = std::max(current_node->data(),right_subtree_max);

            if(max_size > absolute_max_size)
            {
                absolute_max_size = max_size;
                absolute_min = _min_;
                absolute_max = _max_;
            }

            std::cout <<"{"<<current_node->data()<<"}" << max_size << "|" << _min_ << "|" << _max_ << std::endl;
            return;
        }

        void check_if_BST()
        {
            int _min_ = std::numeric_limits<int>::min();
            int _max_ = std::numeric_limits<int>::max();
            int max_size = 0;
            check_if_BST(this->_root_, max_size, _min_, _max_);
            std::cout << std::endl;
            std::cout << "Largest BST : " << absolute_max_size << "|" << absolute_min << "|" << absolute_max << std::endl;
            return;
        }
    };

    static void execute()
    {
        // std::vector<int> _vector_{50,30,70,40,0,60,90,0,0,0,0,55,100,0,0};
        // std::vector<int> _vector_{20,10,30,50,15};
        std::vector<int> _vector_{60,0,70,0,0,65,90};
        BT tree(_vector_);
        std::cout<< tree << std::endl;
        tree.check_if_BST();
        return;
    }
};