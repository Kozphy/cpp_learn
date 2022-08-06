#include "linklisted.h"

using namespace std;

void linkNode(vector<ListNode> &list_node, int pos = -1)
{
    // link node
    for (int i = 0; i < list_node.size(); i++)
    {
        if (i != (list_node.size() - 1))
        {
            list_node[i].next = &list_node[i + 1];
        }
        else if (i == (list_node.size() - 1) && pos >= 0)
        {
            list_node[i].next = &list_node[pos];
        }
    }
}