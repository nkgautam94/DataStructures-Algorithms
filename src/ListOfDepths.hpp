#include "BinarySearchTree.hpp"
#include "LinkedList.hpp"

class BST : public BinarySearchTree
{
public:
    BST():BinarySearchTree(){}
    BST(const std::vector<int> &_vector_):BinarySearchTree(_vector_){}

    void traverse(Node *current_node, int level, std::vector<LinkedList> &_vector_)
    {
        if(current_node)
        {
            traverse(current_node->left(),level + 1,_vector_);
            _vector_[level].insert(current_node->data(),InsertPosition::End);
            traverse(current_node->right(),level + 1,_vector_);
        }
    }

    void create_list_of_depths()
    {
        int tree_depth = this->get_depth();
        std::cout << "Tree Depth : " << tree_depth << std::endl;
        std::vector<LinkedList> _vector_(tree_depth);
        traverse(this->_root_,0,_vector_);
        for(auto element : _vector_)
            std::cout << element << std::endl;
        return;
    }
};

class ListOfDepths
{
public:
    static void execute()
    {
        std::vector<int> _vector_{1,3,2,5,4,8,7};
        BST tree(_vector_);
        tree.create_list_of_depths();
        std::cout << "Done" << std::endl;
    }
};