// 876. Middle of the Linked List



 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(1)

 class Solution {
 public:
      ListNode* middleNode(ListNode* head)
      {
           auto slow{ head };
           for (auto fast = head; fast && fast->next; fast = fast->next->next)
                slow = slow->next;

           return slow;
      }
 };