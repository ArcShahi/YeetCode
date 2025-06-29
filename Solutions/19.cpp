// 19. Remove Nth Node From End of List


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// Sentinel node 
		ListNode s_node{ 0,head };

		auto l{ &s_node };
		auto r{ head };
		// 'r' is 'n' ahead of 'l'
		for (int i{ 0 }; i < n; ++i)
			r = r->next;

		while (r)
		{
			l = l->next;
			r = r->next;
		}
		// 'l' points just before the element to be removed
		l->next = l->next->next;

		return s_node.next;
		
	}
};