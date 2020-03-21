#include "BinarySearchTree.hpp"

class InOrderSuccessor
{
public:
    class BST : public BinarySearchTree
    {
    public:
        BST(const std::vector<int> &_vector_):BinarySearchTree(_vector_){}

        void find_inorder_successor(Node *parent_node, Node *current_node , Node **inorder_successor)
        {
            if(parent_node == current_node)
            {
                if(current_node->right() == nullptr)
                    return;
                else
                {
                    *inorder_successor = current_node->right();
                    while ((*inorder_successor)->left())
                        *inorder_successor = (*inorder_successor)->left();
                    return;
                }
            }

            if(current_node->data() > parent_node->data())
            {
                find_inorder_successor(parent_node->right(),current_node,inorder_successor);
            }

            if(current_node->data() < parent_node->data())
            {
                *inorder_successor = parent_node;
                find_inorder_successor(parent_node->left(),current_node,inorder_successor);
            }
        }

        void traverse_and_find_inorder_successor(Node *current_node)
        {
            if(current_node)
            {
                traverse_and_find_inorder_successor(current_node->left());
                Node *inorder_successor = nullptr;
                std::cout << "Finding for : " << current_node->data() << " => ";
                find_inorder_successor(this->_root_, current_node, &inorder_successor);
                (inorder_successor == nullptr)?(std::cout << "nullptr" << std::endl):(std::cout << inorder_successor->data() << std::endl);
                traverse_and_find_inorder_successor(current_node->right());
            }
        }

        void traverse_and_find_inorder_successor()
        {
            traverse_and_find_inorder_successor(this->_root_);
            return;
        }
        
    };
 
    static void execute()
    {
        std::vector<int> _vector_{20, 10, 30, 5, 15, 25};
        BST tree(_vector_);
        tree.traverse_and_find_inorder_successor();
        return;
    }
};