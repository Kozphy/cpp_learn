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

void printStack(stack<TreeNode*> &st)
{
    if(st.size() == 0){
        return;
    }

    TreeNode *node = st.top();
    int x = node -> val;
    st.pop();
    printStack(st);

    cout << x << ", ";
    st.push(node);
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
vector<int> PostOrderTraversal(TreeNode *root){
    vector<int> res{};
    stack<TreeNode *> st;
    TreeNode *curr_node = nullptr;

    if(!root){
        return res;
    }

    st.push(root);

    while(st.empty() != 1){
        curr_node = st.top(); 
        if(!curr_node -> left && !curr_node -> right){
            st.pop();
            res.push_back(curr_node -> val);
        }
        if(curr_node -> right){
            st.push(curr_node -> right);
            curr_node -> right = NULL;
        }
        if(curr_node -> left){
            st.push(curr_node -> left);
            curr_node -> left = NULL;
        }
    }
    print("result1", res);
    return res;
}

vector<int> PostOrderTraversal2(TreeNode *root)
{
    vector<int> res{};
    stack<TreeNode *> st;
    TreeNode *curr_node = root;
    TreeNode *pop_node = nullptr;

    if(!root){
        return res;
    }

     
    while(curr_node || st.empty() != 1){
        if(curr_node != NULL){
            st.push(curr_node);
            curr_node = curr_node -> left;
        }else{
            curr_node = st.top();
            if(curr_node -> right != NULL && curr_node -> right != pop_node){
                curr_node = curr_node -> right;
            }else{
                res.push_back(curr_node -> val);
                st.pop();
                pop_node = curr_node;
                curr_node = NULL;
            }
        }
    }

    print("result2: ", res);
    return res;
}

// recursive
void traversal(TreeNode *root, vector<int> &res){
    if(root == NULL){
        return;
    }
    
    traversal(root->left, res);
    traversal(root->right, res);
    res.push_back(root -> val);
}

vector<int> PostOrderTraversal3(TreeNode *root)
{
    vector<int> res{};

    if(root == NULL){
        return res;
    }

    traversal(root -> left, res);
    traversal(root -> right, res);
    res.push_back(root -> val);
    print("result3: ", res);
    return res;
}

int main()
{
    // vector <int> root = {11,7,15,5,9,13,20,3,6,8,10,12,14,18,25};

    vector <int> root = {1,2};
    TreeNode *root_node = create_binary_tree(root);

    // PostOrderTraversal(root_node);
    PostOrderTraversal2(root_node);
    PostOrderTraversal3(root_node);



    return 0;
}