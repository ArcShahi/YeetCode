// 92. Reverse Linked List II


 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
 public:
      ListNode* reverseBetween(ListNode* head, int left, int right) {
           if (!head || left == right) return head;

           // Dummy node to simplify edge case where left == 1
           ListNode s_node{ 0,head};
           auto pvs{ &s_node };

           // Move prev to the node before the 'left' position
           for (int i = 1; i < left; ++i) 
                pvs = pvs->next;
         
            auto itr{ pvs->next };
            auto anchor{ itr }; 
            ListNode* succ{ nullptr };

           for (int i = 0; i <= right - left; ++i)
           {
                succ = itr->next;
                itr->next = pvs->next;
                pvs->next = itr;
                itr = succ;
           }

           anchor->next = itr;
           return s_node.next;
      }
 };

