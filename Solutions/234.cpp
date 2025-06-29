
// 234. Palindrome Linked List


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
      bool isPalindrome(ListNode* head)
      {
           if (not head) return true;

           auto slow{ head };
           auto fast{ head };
           // PHASE 1 : FIND THE MIDDLE
           while (fast&&fast->next)
           {
                slow = slow->next;
                fast = fast->next->next;
           }

           // PHASE 2 : REVERSE 2nd Half
           ListNode* pvs{ nullptr };
           auto itr{ slow };

           while (itr)
           {
                auto succ = itr->next;
                itr->next = pvs;
                pvs = itr;
                itr = succ;
           }
           // PHASE 3 : COMPARE
           auto left{ head };
           auto right{ pvs };

           while (right)
           {
                if (left->val != right->val) return false;

                left = left->next;
                right = right->next;
           }
           return true;
      }
 };