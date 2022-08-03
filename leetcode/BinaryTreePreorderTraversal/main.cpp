#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <variant>
#include "tree.h"
#include "linklisted.h"

using namespace std;

template <typename T>
using vector2d = vector<vector<T>>;

template <typename C>
void print(string name, const vector<C> &vector_1d)
{
    cout << name << ": ";
    for (const auto &x : vector_1d)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

void print(string name, vector<ListNode> &node)
{
    cout << "print " << name << endl;

    for (int i = 0; i < node.size(); i++)
    {
        cout << "node: " << i << endl;
        cout << "node address: " << &node[i] << endl;
        cout << "node value: " << node[i].val << endl;
        cout << "node next: " << node[i].next << endl;
        cout << endl;
    }
}
void print(string name, ListNode *node)
{
    cout << "print " << name << endl;

    while (node->next != NULL)
    {
        cout << "node val: " << node->val << endl;
        cout << "node address: " << node << endl;
        cout << "node next: " << node->next << endl;
        node = node->next;
    }
    // print last node
    cout << "node val: " << node->val << endl;
    cout << "node address: " << node << endl;
    cout << "node next: " << node->next << endl;
}

template <typename T, typename C>
void print(string name, map<T, C> &mapping)
{
    cout << "print map name: " << name << endl;
    for (auto &v : mapping)
    {
        cout << v.first << " : " << v.second << endl;
    }
}

template <typename C>
void print(string name, vector2d<C> &vector_2d)
{
    int one_dimensional_index{0};
    int two_dimensional_index{0};
    cout << "print name: " << name << endl;
    for (auto &v : vector_2d)
    {
        cout << "1 dimensional index: " << one_dimensional_index << endl;
        one_dimensional_index++;
        for (auto &e : v)
        {
            cout << "2 dimensional index: " << two_dimensional_index << " value: " << e << endl;
            two_dimensional_index++;
        }
        two_dimensional_index = 0;
    }
}

template <typename T, typename C>
bool create_hashmap(vector<T> &nums, map<T, C> &mapping)
{
    for (auto &v : nums)
    {
        if (mapping.find(v) != mapping.end())
        {
            mapping[v] += 1;
        }
        else
        {
            mapping[v] = 1;
        }
    }
    return true;
}


// Iterative
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result{};
    stack<TreeNode *> all_roots{};

    if (!root)
    {
        return result;
    }

    all_roots.push(root);

    while(all_roots.empty() != 1){
        TreeNode *node = all_roots.top();
        all_roots.pop();
        result.push_back(node -> val);
        if(node -> right){
            all_roots.push(node -> right);
        }
        if(node -> left){
            all_roots.push(node -> left);
        }
    }

    print("result1: ", result);
    return result;
}
vector<int> preorderTraversal2(TreeNode *root){
    vector<int> res{};
    stack<TreeNode *> st{};
    TreeNode *curr_node = root;

    if(!root){
        return res;
    }

    while(curr_node || st.empty() != 1){
        while(curr_node){
            st.push(curr_node);
            res.push_back(curr_node -> val);
            curr_node = curr_node-> left;
        }
        curr_node = st.top();
        st.pop();
        curr_node = curr_node -> right;
        
    }
    print("result2: ", res);
    return res;
}

// recursive
void traversal(TreeNode *root, vector<int> &res){
    if(root != NULL){
        res.push_back(root -> val);
        if(root -> left){
            traversal(root->left, res);
        }
        if(root -> right){
            traversal(root->right, res);
        }
    }
}

vector<int> preorderTraversal3(TreeNode *root)
{
    vector<int> result{};
    
    traversal(root, result);
    print("result3: ", result);
    return result;
}

vector<int> preorderTraversal4(TreeNode *root)
{
    vector<int> res{};
    if(!root){
        return res;
    }
    res.push_back(root -> val);
    traversal(root -> left, res);
    traversal(root -> right, res);
    print("result4: ", res);
    return res;
}

int main()
{
    vector <int> root = {11,7,15,5,9,13,20,3,6,8,10,12,14,18,25};

    TreeNode *root_node = create_binary_tree(root);
    // TreeNode root_node = TreeNode(3);
    // TreeNode second = TreeNode(2);
    // TreeNode third = TreeNode(4);
    // TreeNode fourth = TreeNode(1);
    // root_node.left = &second;
    // second.right = &third;
    // third.left = &fourth;
    preorderTraversal(root_node);
    preorderTraversal2(root_node);
    preorderTraversal3(root_node);
    preorderTraversal4(root_node);



    return 0;
}