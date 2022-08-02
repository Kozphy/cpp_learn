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

// recursive
void traversal(TreeNode *root, vector<int> &arr){
    if(root != NULL){
        arr.push_back(root -> val);
        if(root -> left){
            traversal(root->left, arr);
        }
        if(root -> right){
            traversal(root->right, arr);
        }
    }
}

vector<int> preorderTraversal2(TreeNode *root)
{
    vector<int> result{};
    
    traversal(root, result);
    print("result2: ", result);
    return result;
}

int main()
{
    vector <int> root = {3,2,0,0,4,1};

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



    return 0;
}