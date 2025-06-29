// 2807. Insert Greatest Common Divisors in Linked List
#include <numeric>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 // TIME COMPLEXITY :O(n)
 // SPACE COMPLEXITY : O(n)

class Solution {
public:
     ListNode* insertGreatestCommonDivisors(ListNode* head) {

          if (not head)return nullptr;
          if (not head->next) return head;

          auto f{ head };
          auto s{ head->next };

          while (s)
          {
               int value = std::gcd(f->val, s->val);
               auto node = new ListNode(value, s); // node->next=s;
               f->next = node;

               f = f->next->next;
               s = s->next;
          }

          return head;
     }
};