// 206. Reverse Linked List



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
      ListNode* reverseList(ListNode* head)
      {
           if (not head) return nullptr;

           ListNode* pvs{ nullptr };
           auto itr{ head };

           while (itr)
           {  // save next so Link doesn't get lost
                auto succ{ itr->next };
                itr->next = pvs;

                pvs = itr;
                itr = succ;
           }
           return pvs; // new head after reversal
      }
 };