#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

template <typename T>
using vector2d = vector<vector<T>>;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

template <typename C>
void print(string name, const vector<C> &vector_1d)
{
    cout << name << ": ";
    for (const auto &x: vector_1d) {
         cout << x << ' ';
    }
    cout << '\n';
}


void print(string name, vector<ListNode> &node){
    cout << "print " << name << endl;
    
    for(int i = 0; i< node.size(); i++){
        cout <<  "node: " << i << endl;
        cout << "node address: " << &node[i] << endl;
        cout << "node value: " << node[i].val << endl;
        cout << "node next: " << node[i].next << endl;
        cout << endl;
    }
}
void print(string name, ListNode *node){
    cout << "print " << name << endl;

    while(node -> next != NULL){
        cout << "node val: "<< node -> val << endl;
        cout << "node address: " << node << endl;
        cout << "node next: " << node -> next << endl;
        node = node -> next;
    }
    // print last node
    cout << "node val: "<< node -> val << endl;
    cout << "node address: " << node << endl;
    cout << "node next: " << node -> next << endl;
}

template <typename T, typename C>
void print(string name, map<T, C> &mapping){
    cout << "print map name: " << name << endl;
    for (auto &v: mapping){
        cout << v.first << " : " << v.second << endl;
    }
}

template <typename C>
void print(string name, vector2d<C> &vector_2d){
    int one_dimensional_index{0};
    int two_dimensional_index {0};
    cout << "print name: " << name << endl;
    for (auto &v: vector_2d){
        cout << "1 dimensional index: " << one_dimensional_index << endl;
        one_dimensional_index++;
        for(auto &e: v){
            cout << "2 dimensional index: " << two_dimensional_index <<  " value: " << e << endl;
            two_dimensional_index++;
        }
        two_dimensional_index = 0;
    }
}



template<typename T, typename C>
bool create_hashmap(vector<T> &nums, map<T, C> &mapping){
    for (auto &v: nums){
        if (mapping.find(v) != mapping.end()){
            mapping[v] += 1;
        }else {
            mapping[v] = 1;
        }
    }
    return true;
}



void linkNode(vector<ListNode> &list_node, int pos = -1){
    // link node
    for (int i = 0; i < list_node.size(); i++){
        if (i != (list_node.size()-1)){
            list_node[i].next = &list_node[i + 1];
        }else if(i == (list_node.size() - 1) && pos >=0){
            list_node[i].next = &list_node[pos];
        }
    }
}

ListNode *removeElements(ListNode *head, int val){

    ListNode *result = head; 
    ListNode *prevNode = nullptr;

    if (!result){
        return NULL;
    }
    
    while(head && head -> next){
        cout << head -> val << endl;
        if (head -> next -> val == val){
            head -> next = head -> next -> next;
        }else if(head -> val == val){
            prevNode = head;
            head = head -> next;
            prevNode -> next = NULL;
            result = head;
        }
        else{
            head = head -> next;
        }
    }

    if (head -> val == val){
        return NULL;
    }

    return result;
}

int main() {
    // int pos = 1;
    vector<ListNode> head = {
        ListNode(1),
        ListNode(2),
        ListNode(7),
        ListNode(7),
        ListNode(7),
        ListNode(7),
        ListNode(7),

    };
    int val = 1;

    linkNode(head);

    print("head: ", head);
    ListNode *result = removeElements(&head[0], val);
    cout << boolalpha;
    print("result ListNode: ", result);
    // cout << endl;



    return 0;
}