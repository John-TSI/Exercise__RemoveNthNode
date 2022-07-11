#include"../inc/solution.hpp"


ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    if(!head->next){ return nullptr; }  // linked list contained only one node

    ListNode* follower{head}, * leader{head};
    
    while(n--){ leader = leader->next; }  // if n < #nodes: leader is now n nodes ahead of follower, else: n = #nodes and leader = nullptr
    if(!leader)
    {
        ListNode* tmp{head->next};  // tmp points to new head node
        head->next = nullptr;  // current head node is detached from list
        return tmp;
    }

    while(leader->next)
    {
        leader = leader->next;
        follower = follower->next;
    }   // follower now points to node before the node to be removed

    ListNode* tmp{follower->next};  // tmp points to node to be removed
    follower->next = tmp->next;  // follower node points to node after removed node
    tmp->next = nullptr;  // removed node points to nullptr

    return head;
}