// 382. Linked List Random Node


#include <cstdlib>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // Reservoir Sampling

class Solution {
public:
     Solution(ListNode* head)
          :node{ head } {}

     int getRandom() {
          int reservior{ node->val };
          int p{ 2 };

          for (auto it{ node->next }; it; it = it->next)
               if (rand() % p++ == 0) reservior = (it->val);
                       
          return reservior;
     }

private:
     ListNode* node{ };   
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */