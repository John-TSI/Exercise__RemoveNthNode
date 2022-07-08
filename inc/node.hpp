#ifndef NODE_HPP
#define NODE_HPP


struct ListNode
{
    int val;
    ListNode* next;

    ListNode();
    ListNode(int);
    ListNode(int, ListNode*);
};

#endif //NODE_HPP