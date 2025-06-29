
// 328. Odd Even Linked List


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
     ListNode* oddEvenList(ListNode* head)
     {
          // Sentinel Nodes
          ListNode s_even{ 0 }, s_odd{ 0 };

          auto even_tail{ &s_even };
          auto odd_tail{ &s_odd };
          auto idx{ 1 };

          auto itr{ head };

          while (itr)
          {
               if (idx++ & 1)
               {
                    odd_tail->next = itr;
                    odd_tail = odd_tail->next;
               }
               else
               {
                    even_tail->next = itr;
                    even_tail = even_tail->next;
               }

               itr = itr->next;

          }

          even_tail->next = nullptr;
          odd_tail->next = s_even.next;

          return s_odd.next;
     }
};

