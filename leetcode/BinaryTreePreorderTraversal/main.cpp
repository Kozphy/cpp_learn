#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
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



vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result{};
    stack<TreeNode *> children_roots{};
    TreeNode *left_p1{root->left};
    TreeNode *right_p1(root->right);

    if (!root)
    {
        return result;
    }

    result.push_back(root->val);

    if(!left_p1)
    {
        result.push_back(left_p1 -> val);
    }

    if(!right_p1)
    {
        result.push_back(right_p1 -> val);
    }

    while (left_p1 && left_p1->left)
    {
        result.push_back(left_p1->val);
        children_roots.push(left_p1);
        left_p1 = left_p1->left;
    }

    // add left side last value
    if(left_p1){
        result.push_back(left_p1 -> val);
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

    while (right_p1 && right_p1->right)
    {
        if(right_p1 -> left){
            result.push_back(right_p1 -> left -> val);
        }
        result.push_back(right_p1 -> val);
        right_p1 = right_p1-> right;
    }

    // add right last value
    if(right_p1)
    {
        result.push_back(right_p1 -> val);
    }
}

int main()
{
    TreeNode binary_root = TreeNode(1);
    // TODO: fix no matching function
    TreeNode second_root = addNodeToTree(binary_root, TreeNode(2), false, true);
    addNodeToTree(second_root, TreeNode(3), true, false);
    preorderTraversal(&binary_root);

    return 0;
}