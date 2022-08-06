#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <variant>
#include <math.h>
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
    string res{"["};
    int one_dimensional_index{0};
    int two_dimensional_index{0};
    cout << "print name: " << name << endl;
    for (auto &v : vector_2d)
    {
        // cout << "1 dimensional index: " << one_dimensional_index << endl;
        one_dimensional_index++;
        res.append("[");
        for (auto &e : v)
        {
            // cout << "2 dimensional index: " << two_dimensional_index << " value: " << e << endl;
            res.append(to_string(e) + ", ");
            two_dimensional_index++;
        }
        res.append("],");
        two_dimensional_index = 0;
    }
    res.append("]");
    cout << res << endl;
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
// level_size = 2^level
bool isSymmetric(TreeNode *root){
    if(root == NULL){
        return 0;
    }

    
    return true;
}



// recursive
int maxDepth2(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int maxLeft = maxDepth(root -> left);
    int maxRight = maxDepth(root -> right);
    return max(maxLeft, maxRight) + 1;
}





int main()
{
    // vector <int> root = {11,7,15,5,9,13,20,3,6,8,10,12,14,18,25};

    vector <int> root = {1,2,2,3,4,4,3};

    // vector <int> root = {3,9,20,15,7};
    // vector <int> root = {1,2};
    TreeNode *root_node = create_binary_tree(root);

    bool result = isSymmetric(root_node);
    cout << "result: " << result << endl;
    // int result2 = isSymmetric2(root_node);
    // cout << "result2: " << result2 << endl;
    // maxDepth2(root_node);



    return 0;
}