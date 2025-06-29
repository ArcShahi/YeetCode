//
struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverse_list(ListNode* head)
{
  
     ListNode* pvs{ nullptr };
     auto itr{ head };

     while (itr)
     {
          auto succ = itr->next;
          itr->next = pvs;

          pvs = itr;
          itr = succ;
     }

     return pvs;
}


class Solution {
public:
     ListNode* doubleIt(ListNode* head) 
     {    
          if (!head) return nullptr;
          // Reversed the list
          head = reverse_list(head);

          ListNode s_node{ 0 };
          auto tail{ &s_node };
          int cy{ 0 };

          while (head || cy)
          { 
               int dval = (head ? (head->val * 2) : 0) + cy;
               cy=dval/10;

               auto node{ new ListNode(dval % 10) };
               tail->next = node;
               tail = node;

               if (head) head = head->next;
          }

          s_node.next = reverse_list(s_node.next);
          return s_node.next;

     }
};

// APPROACH 2
#include <vector>

class Solution2 {
public:
     ListNode* doubleIt(ListNode* head) {
          std::vector<int> stack{};
          auto itr{ head };

          // Push all nodes to the stack
          while (itr) {
               stack.push_back(itr->val);
                itr = itr->next;
          }

          int cy{ 0 };
        
          ListNode s_node{ 0 };
          auto root{ &s_node };

          while (!stack.empty() || cy) 
          {
               int dval = (stack.empty() ? 0 : stack.back()*2) + cy;
               stack.pop_back();
               cy = dval / 10;

               auto node{ new ListNode(dval % 10) };
               node->next = root;
               root = node;

          }
         
          return head;
     }
};


