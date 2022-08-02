#include "tree.h"
#include <iostream>

using namespace std;

TreeNode::TreeNode()
{
    val = 0;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int x)
{
    val = x;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)
{
    val = x;
    this -> left=left;
    this -> right=right;
}

TreeNode *create_new_node(int data){
    TreeNode *newNode = new TreeNode();
    newNode -> val = data;
    return newNode;
}

TreeNode *Insert(TreeNode *root, int data)
{
    if(root == NULL){
        root = create_new_node(data);
    }
    else if(data <= root -> val){
        root -> left = Insert(root->left, data);
    }else{
        root -> right = Insert(root->right, data);
    }

    return root;
}

TreeNode *create_binary_tree(vector<int> &data)
{
    TreeNode *root = create_new_node(data[0]);

    for(int i = 1; i< data.size(); i++){
        // cout << "data: " << i << " , " << data[i] << endl;
        if (data.at(i) == 0){
            continue;
        }
        Insert(root, data[i]);
    }
    return root;
}

