// 143. Reorder List



 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // TIME COMPLEXITY: O(n)
 // SPACE COMPLEXITY : O(1)

class Solution {
public:
     void reorderList(ListNode* head) {

          if (not head || not head->next || not head->next->next) return;


          // Finding the middle

          auto slow{ head };
          auto fast{ head };
          while (fast && fast->next)
          {
               slow = slow->next;
               fast = fast->next->next;
          }

          auto right = slow->next;
          slow->next = nullptr;

          // Reverse right side
          ListNode* pvs{ nullptr };
          auto itr{ right };

          while (itr)
          {
               auto succ = itr->next;
               itr->next = pvs;
               pvs = itr;
               itr = succ;
          }

          
          // Link left side to right side
       
          auto l{ head };
          auto r{ pvs };

          while (r)
          {
               auto lnext = l->next;
               auto rnext = r->next;

               l->next = r;
               r->next = lnext;


               l = lnext;
               r = rnext;
          }
          
     }
};