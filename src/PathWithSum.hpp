#include "BinaryTree.hpp"
#include <map>

class PathWithSum
{
public:
    class Tree : public BinaryTree
    {
    public:
        Tree(const std::vector<int> &_vector_):BinaryTree(_vector_){}

        std::map<int,int> running_sum_map;

        int path_count;
        std::vector<std::pair<Node*,Node*>> paths;

        void compute_running_sum(Node *current_node, std::map<int,int> current_sum_map, int current_sum, int target_sum, std::map<int,std::vector<Node*>> source)
        {
            if(current_node == nullptr)
                return;

            current_sum += current_node->data();
            current_sum_map[current_sum]++;
            source[current_sum].push_back(current_node);

            int required_sum = current_sum - target_sum;

            if(current_sum_map[required_sum] > 0)
            {
                this->path_count += current_sum_map[required_sum];
                for(auto _source_ : source[required_sum])
                    paths.push_back(std::make_pair(_source_,current_node));
            }

            compute_running_sum(current_node->left(), current_sum_map, current_sum, target_sum, source);
            compute_running_sum(current_node->right(), current_sum_map, current_sum, target_sum, source);
        }

        void count_path_with_sum(int target_sum)
        {
            std::map<int,int> current_sum_map;
            int current_sum = 0;
            this->path_count = 0;
            std::map<int,std::vector<Node*>> source;
            compute_running_sum(this->_root_, current_sum_map, current_sum, target_sum, source);
            std::cout << path_count << " path found with sum : " << target_sum << std::endl;
            // for(auto _path_ : paths)
            //     std::cout << _path_.first->data() << "->" << _path_.second->data() << std::endl;
        }
    };

    static void execute()
    {
        int target_sum = 7;
        std::vector<int> _vector_{10,5,-3,3,2,0,11,3,-2,0,1,0,0};
        Tree _tree_(_vector_);
        std::cout << _tree_ << std::endl;
        _tree_.count_path_with_sum(target_sum);
        return;
    }
};