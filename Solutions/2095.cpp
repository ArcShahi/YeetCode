
// 2095. Delete the Middle Node of a Linked List

 
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
     ListNode* deleteMiddle(ListNode* head) 
     {
          if (not head || not head->next) return nullptr;

          auto slow{ head };
          auto fast{ head };
          ListNode* prev_mid{ nullptr };

          while (fast && fast->next)
          {
               prev_mid = slow;
               slow = slow->next;
               fast = fast->next->next;
          }
          
          prev_mid->next = slow->next;
          
          return head;
     }
};