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
    ListNode(int x) : val(x), next(NULL){}
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
    cout << "print: " << name << endl;
    
    for(int i = 0; i< node.size(); i++){
        cout <<  "node: " << i << endl;
        cout << "node address: " << &node[i] << endl;
        cout << "node value: " << node[i].val << endl;
        cout << "node next: " << node[i].next << endl;
        cout << endl;
    }
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

bool hasCycle(ListNode *head){
    map<ListNode*, int> mapping;

    ListNode *current_node = head;
    if (current_node == NULL){
        return false;
    }

    while(current_node -> next != NULL){
        if(mapping[current_node]++ > 1){
            return true;
        }
        current_node = current_node -> next;

    }

    return false;
}

bool hasCycle2(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast->next->next;
        slow = slow -> next;
        if(fast == slow){
            return true;
        }
    }
    return false;

}

int main() {
    int pos = 1;
    vector<ListNode> head = {
        ListNode(3),
        ListNode(2),
        ListNode(0),
        ListNode(-4),
    };

    // link node
    for (int i = 0; i < head.size(); i++){
        if (i != (head.size()-1)){
            head[i].next = &head[i + 1];
        }else if(i == (head.size() - 1) && pos >=0){
            head[i].next = &head[pos];
        }
    }

    print("head ListNode: ", head);
    bool result = hasCycle(&head[0]);
    cout << boolalpha;
    cout << "result: " << result << endl;
    cout << endl;
    bool result2 = hasCycle2(&head[0]);
    cout << "result2: " << result2 << endl;
    cout << endl;


    return 0;
}