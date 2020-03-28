#include <iostream>
#include "BinaryTree.hpp"

class CommonAncestor
{
public:
    class tree : public BinaryTree
    {
    public:
        tree(const std::vector<int> &_vector_) : BinaryTree(_vector_) {}

        void traverse(Node *current_node, int first, int &first_ancestor, int second, int &second_ancestor, int &common_ancestor)
        {
            if(current_node)
            {
                std::cout << "check " << current_node->data() << std::endl;
                traverse(current_node->left(),first,first_ancestor,second,second_ancestor,common_ancestor);
                traverse(current_node->right(),first,first_ancestor,second,second_ancestor,common_ancestor);

                if(current_node->data() == first) {first_ancestor = current_node->data();}
                if(current_node->data() == second) {second_ancestor = current_node->data();}

                if(current_node->left())
                {
                    if(current_node->left()->data() == first_ancestor)
                        first_ancestor = current_node->data();

                    if(current_node->left()->data() == second_ancestor)
                        second_ancestor = current_node->data();
                }

                if(current_node->right())
                {
                    if(current_node->right()->data() == first_ancestor)
                        first_ancestor = current_node->data();

                    if(current_node->right()->data() == second_ancestor)
                        second_ancestor = current_node->data();
                }


                if(current_node->data() == first_ancestor && current_node->data() == second_ancestor)
                {
                    if(current_node->data() != first && current_node->data() != second)
                    {
                        common_ancestor = current_node->data();
                        first_ancestor = second_ancestor = 0;
                    }
                }
            }
        }

        void GetCommonAncestor(int first_node, int second_node)
        {
            int first_ancestor = 0;
            int second_ancestor = 0;
            int common_ancestor = 0;
            traverse(_root_,first_node,first_ancestor,second_node,second_ancestor,common_ancestor);
            if(common_ancestor)
                std::cout << "Common Ancestor : " << common_ancestor << std::endl;
            else
                std::cout << "Common Ancestor Does Not Exists! " << std::endl;
        }

    };

    static void execute()
    {
        std::vector<int> _vector_{60,20,70,10,5,65,90};
        tree _tree_(_vector_);
        std::cout<< _tree_ << std::endl;
        _tree_.GetCommonAncestor(10,20);
        return;
    };
};