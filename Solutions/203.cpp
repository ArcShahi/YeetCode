
// 203. Remove Linked List Elements

struct ListNode
{
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
     ListNode* removeElements(ListNode* head, int val)
     {
          if (not head) return nullptr;

          ListNode s_node{ 0,head };
          auto pvs{ &s_node };
          auto itr{ head };

          while (itr)
          {
               if (itr->val == val)
                    pvs->next = itr->next;
               else
                    pvs = itr;

               itr = itr->next;
          }
          return s_node.next;
     }
};