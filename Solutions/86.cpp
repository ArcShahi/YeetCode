// 86. Partition List


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 // TIME COMPLEXITY : O(n)
 // SPACE COMPLEXITY : O(1)
 

 // SPLIT TO MERGE ;)

class Solution {
public:
     ListNode* partition(ListNode* head, int x) {

          if (not head) return nullptr;

          ListNode s_smaller{};
          auto stail{ &s_smaller };

          ListNode s_other{};
          auto otail{ &s_other };

          auto itr{ head };

          while (itr)
          {
               if (itr->val < x)
               {
                    stail->next = itr;
                    stail = itr;
               }
               else
               {
                    otail->next = itr;
                    otail = itr;                
               }
               itr = itr->next;
          }

          stail->next = s_other.next;
          otail->next = nullptr;

          return s_smaller.next;
     }
};