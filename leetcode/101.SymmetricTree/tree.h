#ifndef TREE_H
#define TREE_H
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

TreeNode *create_binary_tree(vector<int> &data);
TreeNode *Insert(TreeNode *root, int &data);

#endif