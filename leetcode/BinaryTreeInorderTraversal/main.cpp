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
vector<int> InorderTraversal(TreeNode *root)
{
    vector<int> res{};
    stack<TreeNode *> st;
    TreeNode *curr_node = root;

    if(!root){
        return res;
    }

    while(curr_node || st.empty() != 1){
        while (curr_node) {
            st.push(curr_node);
            curr_node = curr_node -> left;
        }
        curr_node = st.top();
        st.pop();
        res.push_back(curr_node -> val);
        curr_node = curr_node -> right;
    }

    print("result1: ", res);
    return res;
}

// recursive
void traversal(TreeNode *root, vector<int> &res){
    if(root == NULL){
        return;
    }
    
    traversal(root->left, res);
    res.push_back(root -> val);
    traversal(root->right, res);
}

vector<int> InorderTraversal2(TreeNode *root)
{
    vector<int> res{};

    if(root == NULL){
        return res;
    }

    traversal(root -> left, res);
    res.push_back(root -> val);
    traversal(root -> right, res);
    print("result2: ", res);
    return res;
}

int main()
{
    vector <int> root = {11,7,15,5,9,13,20,3,6,8,10,12,14,18,25};

    TreeNode *root_node = create_binary_tree(root);

    InorderTraversal(root_node);
    InorderTraversal2(root_node);



    return 0;
}