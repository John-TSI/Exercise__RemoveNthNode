// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<iostream>
#include"../inc/solution.hpp"

// prints data of all nodes linked to the passed head
void PrintData(ListNode* head)
{
	ListNode* p{head};
	if(p == nullptr){ std::cout << "No nodes are linked.\n"; }
	while(p != nullptr)
	{
		std::cout << p->val << '\n';
		p = p->next;
	}
}

int main()
{
	ListNode n4(4);
	ListNode n3(3, &n4);
	ListNode n2(2, &n3);
	ListNode n1(1, &n2); // head node

	ListNode lone{}; // isolated node

	Solution sol{};
	PrintData( sol.removeNthFromEnd(&n1, 1) );

	return 0;
}
