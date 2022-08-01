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
    stack<TreeNode *> children_roots{};
    TreeNode *left_p1{nullptr};
    TreeNode *right_p1(nullptr);

    if (!root)
    {
        return result;
    }

    result.push_back(root->val);

    if(root -> left)
    {
       left_p1 = root->left; 
    }


    if(root -> right)
    {
        right_p1 = root->right;
    }

    while (left_p1)
    {
        result.push_back(left_p1->val);
        children_roots.push(left_p1);
        if(left_p1 -> left){
            left_p1 = left_p1->left;
        }else{
            left_p1 = NULL;
        }
    }


    // 1 -> 2 -> 4 -> 7
    while (!children_roots.empty())
    {
        if (children_roots.top()->right)
        {
            result.push_back(children_roots.top() -> right ->val);
        }
        children_roots.pop();
    }


    print("result1: ", result);
    while (right_p1)
    {
        result.push_back(right_p1 -> val);
        if(right_p1 -> left){
            result.push_back(right_p1 -> left -> val);
        }
        if(right_p1 -> right){
            right_p1 = right_p1-> right;
        }else{
            right_p1 = NULL;
        }
    }

    print("result2: ", result);

    return result;
}

int main()
{
    vector<int> root = {3,2,NULL,NULL,4,1};
    // map<int, vector<variant<bool, int>>> node_val = 
    // {
    //     {0, {2, false, true}},
    //     {1, {3, true, false}},
    // };
    TreeNode root_node = create_binary_tree(root);
    preorderTraversal(&root_node);
    // TreeNode root_node = TreeNode(3);
    // TreeNode second = TreeNode(2);
    // TreeNode third = TreeNode(4);
    // TreeNode fourth = TreeNode(1);
    // root_node.left = &second;
    // second.right = &third;
    // third.left = &fourth;

    // TreeNode newNode = NULL;
    // TreeNode preNode = NULL;
    // for (int i = 0; i < node_val.size(); i++){
    //     newNode = TreeNode(get<int>(node_val[i][0]));
    //     if (i == 0){
    //         preNode = addNodeToTree(root_node, newNode, get<bool>(node_val[i][1]),
    //         get<bool>(node_val[i][2]));
    //     }else{
    //         preNode = addNodeToTree(preNode, newNode, get<bool>(node_val[i][1]),
    //         get<bool>(node_val[i][2]));
    //     }
    // }
    // cout << "root_node val: " << root_node.val << endl;
    // cout << "rootNode right: " << root_node.right->val << endl;

    return 0;
}