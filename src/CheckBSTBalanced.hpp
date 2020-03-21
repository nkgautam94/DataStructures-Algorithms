#include "BinarySearchTree.hpp"

class CheckBSTBalanced
{
public:
    class BST : public BinarySearchTree
    {
    public:
        BST(const std::vector<int> &_vector_):BinarySearchTree(_vector_){}

        bool traverse(Node *current_node, int &height)
        {
            if(current_node == nullptr)
            {
                height = 0;
                return true;
            }

            int left_height = 0;
            int right_height = 0;

            bool left_balanced = traverse(current_node->left(),left_height);
            bool right_balanced = traverse(current_node->right(),right_height);

            height = std::max(left_height,right_height) + 1;

            if(!left_balanced || !right_balanced)
            {
                std::cout << current_node->data() << " Sub Tree Not Balanced " << std::endl;
                return false;
            }
            
            if(std::abs(left_height - right_height) > 1)
            {
                std::cout << current_node->data() << " Height Diff > 1 " << left_height << " " << right_height << std::endl;
                return false;
            }
            
            std::cout << current_node->data() << " is balanced " << std::endl;
            return true;
        }

        bool check_if_balanced()
        {
            int current_height = 0;
            return traverse(this->_root_,current_height);
        }
    };

    static void execute()
    {
        std::vector<int> _vector_{5,3,7,20,25,19,15};
        BST tree(_vector_);

        std::cout << tree.check_if_balanced() << std::endl;

        std::cout << "Done" << std::endl;
    }
};