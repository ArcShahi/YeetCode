// 142. Linked List Cycle II

struct ListNode
{
     int data{};
     ListNode* next{};

};

#include <iostream>

class Solution {
public:
      
     // For the problem IO is bottleneck
     Solution()
     {
          std::ios::sync_with_stdio(false);
          std::cin.tie(nullptr);
     }
public:

     ListNode* detectCycle(ListNode* head) 
     {
          if (!head || !head->next) return nullptr;

          auto slow{ head };
          auto fast{ head };

          // Detect the cycle
          while (fast&&fast->next)
          {
               slow = slow->next;
               fast = fast->next->next;
               
               if (slow == fast)
               {
                    slow = head;

                    // where the cycle starts
                    while (!(slow == fast))
                    {
                         slow = slow->next;
                         fast = fast->next;
                    }
                    return slow;
               }

          }
          return nullptr;
          
     }
};


// Another Apporach

ListNode* detectCycle(ListNode* head) 
{
     if (!head || !head->next) return nullptr;

     auto slow{ head };
     auto fast{ head };

     // Detect if there's a cycle
     do {
          slow = slow->next;
          fast = fast->next->next;

          // If fast reaches nullptr, there's no cycle
          if (!fast || !fast->next) return nullptr;

     } while (slow != fast);

     // find the start of the cycle
     slow = head;
     while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
     }

     return slow;
}