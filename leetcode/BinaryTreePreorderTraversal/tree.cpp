#include "tree.h"

TreeNode addNodeToTree(TreeNode &root_node, TreeNode &node, bool left, bool right)
{
    if (left == true)
    {
        root_node.left = &node;
    }
    if (right == true)
    {
        root_node.right = &node;
    }
    return node;
}