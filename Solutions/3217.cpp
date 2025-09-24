// 3217. Delete Nodes From Linked List Present in Array

#include <vector>
#include <unordered_set>

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
     ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {

          std::unordered_set set(begin(nums), end(nums));

          ListNode dummy{};
          auto tail{ &dummy };

          for (auto it{ head }; it; it = it->next)
          {
               if (!set.contains(it->val))
               {
                    tail->next = it;
                    tail = tail->next;
               }
          }

          tail->next = nullptr;
          return dummy.next;
     }
};