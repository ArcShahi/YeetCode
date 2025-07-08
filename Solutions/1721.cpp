// 1721. Swapping Nodes in a Linked List

#include <utility>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
     ListNode* swapNodes(ListNode* head, int k)
     {
          ListNode s_node{ 0,head };
          auto l{ &s_node };
          auto r{ head };
          auto k_begin{head};

          // Move it 'k' from head
          for (int i{ 1 }; i < k; ++i)
               k_begin = k_begin->next;

          for (int i{ 0 }; i < k; ++i)
               r = r->next;

          while (r)
          {
               l = l->next;
               r = r->next;
          }     

          std::swap(k_begin->val, l->next->val);
          return s_node.next;
          
     }
};