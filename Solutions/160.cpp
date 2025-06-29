// 160. Intersection of Two Linked Lists

#include <iostream>



 struct ListNode 
 {
      int val{};
      ListNode* next{};
      ListNode(int x) : val(x), next(nullptr) {}
     
};


 class Solution {
 public:

      Solution() {
           // Optimizing I/O operations
           std::ios_base::sync_with_stdio(false);
           std::cin.tie(nullptr);
      }

      ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
      {
           if (!headA || !headB) return nullptr;


           auto itrA{ headA };
           auto itrB{ headB };

           while (itrA!=itrB)
           {
                itrA = itrA ? itrA->next : headB;
                itrB = itrB ? itrB->next : headA;
           }
          
           return itrA;
      }
 };
