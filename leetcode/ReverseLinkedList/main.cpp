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

// iterator
ListNode *reverseLinkListed(ListNode *head){
    ListNode *preNode = nullptr;    
    ListNode *curNode = head;
    ListNode *nextNode = nullptr;

    if (!head || !head -> next){
        return head;
    }

    while(head && head -> next){
        head = head -> next;
        cout << "curNode val: " << curNode -> val << endl;
        nextNode = head;
        curNode -> next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }

    // process last node
    head -> next = preNode;
    return head;
}

// recursive
ListNode *reverseLinkListed2(ListNode *head){
    if(head == NULL || head -> next == NULL){
        cout << "last node val: " <<  head -> val << endl;
        return head;
    }

    if(head && head -> next){
        cout << "head val: " << head -> val << endl;
        ListNode *tail = reverseLinkListed(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return tail;
    }
    return head;
}

int main() {
    // int pos = 1;
    vector<ListNode> head = {
        ListNode(1),
        ListNode(2),
        ListNode(3),
        ListNode(4),
        ListNode(5),
    };
    int val = 7;

    linkNode(head);

    // print("head: ", head);
    ListNode *result = reverseLinkListed(&head[0]);
    cout << boolalpha;
    print("result ListNode: ", result);

    // ListNode *result2 = reverseLinkListed2(&head[0]);
    // cout << boolalpha;
    // print("result2 ListNode: ", result2);
    // cout << endl;




    return 0;
}