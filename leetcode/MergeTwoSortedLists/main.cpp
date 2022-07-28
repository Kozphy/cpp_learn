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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    ListNode *head{nullptr};
    ListNode *temp{nullptr};
    head = new ListNode();
    temp = head;

    while(list1 && list2){
        if(list1 -> val <= list2 -> val){
            temp -> next = list1;
            list1 = list1 -> next;
        }else{
            temp -> next = list2;
            list2 = list2 -> next;
        }
        temp = temp -> next;
    }

    if(list1){
        temp -> next = list1;
        list1 = list1 -> next;
    }
    if(list2){
        temp -> next = list2;
        list2 = list2 -> next;
    }

    head = head -> next;

   return head; 
}

ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2){
    if (list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }

    if(list1 -> val <= list2 -> val){
        list1 -> next = mergeTwoLists2(list1 -> next, list2);
        return list1;
    }else{
        list2 -> next = mergeTwoLists2(list1, list2 -> next);
        return list2;
    }
}



int main() {
    // int pos = 1;
    vector<ListNode> list1 = {
        ListNode(1),
        ListNode(2),
        ListNode(4),
    };
    vector<ListNode> list2 = {
        ListNode(1),
        ListNode(3),
        ListNode(4),
    };

    linkNode(list1);
    linkNode(list2);

    print("list1: ", list1);
    print("list2: ", list2);
    // ListNode *result = mergeTwoLists(&list1[0], &list2[0]);
    // cout << boolalpha;
    // print("result ListNode: ", result);
    // cout << endl;
    ListNode *result2 = mergeTwoLists2(&list1[0], &list2[0]);
    cout << boolalpha;
    print("result2 ListNode: ", result2);

    return 0;
}