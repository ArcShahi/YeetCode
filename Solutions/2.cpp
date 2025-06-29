// Add Two Numbers

  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

          int cy{ 0 };
          ListNode s_node{ 0 };
          ListNode* tail{ &s_node };

          // Directly iterating cuz we don't need these Forward list later
          while (l1 || l2 || cy)
          {
               int d1 = l1 ? l1->val : 0;
               int d2 = l2 ? l2->val : 0;
               int sum = cy + d1 + d2;
               cy = sum / 10;

               // Insert at back
               auto node = new ListNode(sum % 10);
               tail->next = node;
               tail = node;

               if (l1) l1 = l1->next;
               if (l2) l2 = l2->next;
          }

          return s_node.next;
     }

};