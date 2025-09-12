// 24. Swap Nodes in Pairs



 struct ListNode {
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
     ListNode* swapPairs(ListNode* head) {

          if (!head) return head;

          ListNode dummy{ 0 };
          auto tail{ &dummy };

          auto it{ head };
          while (it && it->next)
          {
               auto jump{ it->next->next };
               auto second{ it->next };
              
               tail->next = second;
               second->next = it;
               tail = it;
               it = jump;
          }
          tail->next = it; // Attach reamaining if any
          return dummy.next;
         
     }
};