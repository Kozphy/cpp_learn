#ifndef LINKLISTED_H
#define LINKLISTED_H

#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void linkNode(vector<ListNode> &list_node, int pos);

#endif