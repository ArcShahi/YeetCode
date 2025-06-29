// 61. Rotate List


struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
     ListNode* rotateRight(ListNode* head, int k) 
     {
          if (not head) return nullptr;

          auto tail{ head };
          int n{ 1 };

          while (tail->next){
            tail = tail->next;
            ++n;
          }
          
          //  if k is a multiple of n, no rotation needed
          k = k % n;
          if (k == 0) return head;

          // Make is Circular
          tail->next = head;

          auto ntail{ head };
          for (int i{1 }; i < n - k; ++i) {
               ntail = ntail->next;
          }

       
          auto nhead{ ntail->next };
          ntail->next = nullptr;
        

          return nhead;
     }
};