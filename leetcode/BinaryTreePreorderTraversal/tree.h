#ifndef TREE_H
#define TREE_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

TreeNode create_binary_tree(vector<int> data);
TreeNode addNodeToTree(int data);

#endif