// 2487. Remove Nodes From Linked List

#include <vector>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(N)
 
class Solution {
public:
     ListNode* removeNodes(ListNode* head) {
        
          std::vector<ListNode*> stk{};
          for (auto it{ head }; it; it = it->next)
          {
               while (!stk.empty() && stk.back()->val<it->val)
                    stk.pop_back();

               stk.push_back(it);
          }

          ListNode dummy{ 0 };
          auto tail{ &dummy };

          for (auto& node : stk)
          {
               tail->next = node;
               tail = tail->next;
          }
          tail->next = nullptr;
          return dummy.next;
         
     }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     ListNode* removeNodes(ListNode* head) {
        
          head = reverse_list(head);
          auto it{ head };
          int max{ it->val };

          while (it->next)
          {
               if (it->next->val < max)
                    it->next = it->next->next;
               else
               {
                    it = it->next;
                    max = it->val;
               }
          }

          return reverse_list(head);  
     }

private:
     ListNode* reverse_list(ListNode* head)
     {
          ListNode* pvs{ nullptr };
          auto it{ head };

          while (it)
          {
               auto succ{ it->next };
               it->next = pvs;
               pvs = it;
               it = succ;
          }
          return pvs;
     }
};