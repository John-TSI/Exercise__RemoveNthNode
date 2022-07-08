#include"../inc/solution.hpp"


ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* follower{head};
    ListNode* leader{head};
    
    int count{1};
    for(int i{0}; i<n; ++i)
    {
        if(leader->next != nullptr)
        {
            leader = leader->next;
            ++count;
        }
    }   // leader is now n%(#links) links ahead of follower

    while(leader->next != nullptr)
    {
        leader = leader->next;
        follower = follower->next;
        ++count;
    }   // follower now points to node before the node to be removed, count = number of nodes in list

    if(count == 1){ head = nullptr; }
    else if(n == count)
    {
        ListNode* tmp{head->next};  // tmp points to new head node
        head->next = nullptr;  // current head node is detached from list
        head = tmp;  // head points to new head node
    }
    else
    {
        ListNode* tmp{follower->next};  // tmp points to node to be removed
        follower->next = tmp->next;  // follower node points to node after removed node
        tmp->next = nullptr;  // removed node points to nullptr
    }

    return head;
}