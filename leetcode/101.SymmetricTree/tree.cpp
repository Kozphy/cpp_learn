#include "tree.h"
#include <iostream>
#include <queue>
#include <vector>

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

vector<vector<int>> LevelOrderTraversal(TreeNode *root)
{
    vector<vector<int>> res{};
    if(root == nullptr){
        return res;
    }
    queue<TreeNode*> qu;

    qu.push(root);
    while(qu.size()){
        int level_size = qu.size();
        vector<int> temp{};
        for(int i = 0; i< level_size; i++){
            root = qu.front();
            qu.pop();
            temp.push_back(root -> val);
            if(root -> left){
                qu.push(root -> left);
            }
            if(root -> right){
                qu.push(root -> right);
            }
        }
        res.push_back(temp);
    }
    return res;
}

int Tree_height(TreeNode *root)
{
    if(root == NULL){
        return 0;
    }

    int left_height = Tree_height(root -> left);
    int right_height = Tree_height(root -> right);

    return max(left_height, right_height) + 1;
}

TreeNode *rightRotate(TreeNode *root)
{
    TreeNode *new_root = root -> left;
    TreeNode *T2 = new_root -> right;
    
    new_root -> right = root;
    root -> left = T2;


    return new_root;
}

TreeNode *leftRotate(TreeNode *root)
{
    TreeNode *new_root = root -> right;
    TreeNode *T2 = new_root -> left;

    new_root -> left = root;
    root -> right = T2;
    return new_root;
}

int get_balance(TreeNode *root){
    int left_subtree_height = Tree_height(root -> left);
    int right_subtree_height = Tree_height(root -> right);
    return left_subtree_height - right_subtree_height;
}

TreeNode *Insert(TreeNode *root, int &data, bool avl_balance)
{
    if(root == NULL){
        root = create_new_node(data);
    }
    else if(data <= root -> val){
        root -> left = Insert(root->left, data, avl_balance);
    }else{
        root -> right = Insert(root->right, data, avl_balance);
    }


    if (avl_balance){
        int balance_factor = get_balance(root);

        // Left Left Case
        if(balance_factor > 1 && data < root -> left -> val){
            return rightRotate(root);
        }

        // Right Right Case
        if(balance_factor < -1 && data < root -> right -> val){
            return leftRotate(root);
        }

        // Left Right Case
        if(balance_factor > 1 && data > root -> left -> val){
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }

        // Right Left Case
        if(balance_factor < -1 && data < root -> right -> val){
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }
    }

    return root;
}

TreeNode *create_binary_tree(vector<int> &data, bool avl_balance)
{
    TreeNode *root = create_new_node(data[0]);

    for(int i = 1; i< data.size(); i++){
        // cout << "data: " << i << " , " << data[i] << endl;
        if (data.at(i) == 0){
            continue;
        }
        Insert(root, data[i], avl_balance);
    }
    return root;
}



