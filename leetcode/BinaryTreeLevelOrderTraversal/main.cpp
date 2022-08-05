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
vector<vector<int>> levelOrderTraversal(TreeNode *root){
    vector<vector<int>> res{};
    queue<TreeNode *> qu;
    int level = 0;

    if(!root){
        return res;
    }

    qu.push(root);

    while(qu.size()){
        int level_size = qu.size();
        // cout << "level_size: " << level_size << endl;
        // cout << "level: "  << level << endl;
        res.resize(level + 1);
        res[level].resize(level_size);
        // cout << "res.size(): " << res.size() << endl;;
        // cout << "res" << "[" << level << "].size(): " << res[level].size() << endl;
        for(int i = 0; i< level_size; i++){
            TreeNode *curr_node = qu.front();
            // cout << "i: " << i << endl;
            // cout << "curr_node val: " << curr_node->val << endl;
            res[level][i] = curr_node -> val;
            qu.pop();
            if(curr_node -> left){
                qu.push(curr_node -> left);
            }
            if(curr_node -> right){
                qu.push(curr_node -> right);
            }
        }
        level+=1;

        // cout << endl;

    }

    print("result1", res);
    return res;
}

vector<vector<int>> levelOrderTraversal2(TreeNode *root)
{
    vector<vector<int>> res{};
    queue<TreeNode *> qu;
    if(!root){
        return res;
    }

    qu.push(root);

    while(qu.size()){
        int level_size = qu.size();
        vector<int> level_nodes{};
        for(int i = 0; i< level_size; i++){
            TreeNode *curr_node = qu.front();
            level_nodes.push_back(curr_node -> val);
            qu.pop();
            if(curr_node -> left){
                qu.push(curr_node -> left);
            }
            if(curr_node -> right){
                qu.push(curr_node -> right);
            }
        }
        res.push_back(level_nodes);
    }

    print("result2", res);
    return res;

}

// TODO: complete recursive
// recursive
int tree_height(TreeNode *root){

    if(root == NULL){
        return 0;
    }else{
        int lheight = tree_height(root -> left);
        int rheight = tree_height(root -> right);
        if(lheight > rheight){
            return ++lheight;
        }else{
            return ++rheight;
        }
    }
}

void traversal(TreeNode *root, vector2d<int> &res, int level){
    if(root == NULL){
        return;
    }

    if(level == 0){
        res[0][0] = root -> val;
    }
    cout << 1 << endl;
    res[level].push_back(root -> val);
    traversal(root -> left, res, level++);
    traversal(root -> right, res, level++);

}

vector2d<int> levelOrderTraversal3(TreeNode *root)
{
    vector2d<int> res{};
    int h = tree_height(root);
    int level;

    if(root == NULL){
        return res;
    }

    res.resize(h);

    for(level = 0; level < h; level++){
        res[level].resize(exp2(level));
        traversal(root, res, level);
    }

    print("result3: ", res);
    return res;
}

int main()
{
    vector <int> root = {11,7,15,5,9,13,20,3,6,8,10,12,14,18,25};

    // vector <int> root = {3,9,20,15,7};
    // vector <int> root = {1,2};
    TreeNode *root_node = create_binary_tree(root);

    levelOrderTraversal(root_node);
    levelOrderTraversal2(root_node);
    levelOrderTraversal3(root_node);



    return 0;
}