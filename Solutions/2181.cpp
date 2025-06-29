// 2181. Merge Nodes in Between Zeros





 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // IN PLACE MODIFICATION
 // TIME COMPLEXITY :O(n)
 // SPACE COMPLEXITH :O(1)
class Solution {
public:
     ListNode* mergeNodes(ListNode* head) {

          if (!head) return nullptr;

          auto p{ head };
          int sum{ 0 };

          for (auto x{ head->next }; x; x = x->next)
          {
               if (x->val == 0)
               {
                    p->val = sum;
                    p->next = x->next;
                    p = x->next;
                    sum = 0;
               }
               else
               {
                    sum += x->val;
               }
          }
      
          return head;
     }
};

// NEW LIST CREATION
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY :O(n)
class Solution2 {
public:
     ListNode* mergeNodes(ListNode* head) {

          if (!head) return nullptr;

          ListNode snode{};
          auto tail{ &snode };
          int val{ 0 };
          for (auto itr = head->next; itr; itr = itr->next)
          {
               if (itr->val == 0)
               {
                    tail->next = new ListNode(val);
                    tail = tail->next;
                    val = 0;
               }
               else
               {
                    val += itr->val;
               }
          }
          return snode.next;

     }
};
