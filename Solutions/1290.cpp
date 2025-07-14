// 1290. Convert Binary Number in a Linked List to Integer

#include <string>
#include <algorithm>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // TIME COMPLEXITY  : O(N)
 // SPACE COMPLEXITY : O(1)
class Solution {
public:
     int getDecimalValue(ListNode* head) {
          if (!head->next) return head->val;

          int dec{ 0 };
          while (head)
          {
               dec = (dec << 1) | head->val;
               head = head->next;
          }
          return dec;
     }
};