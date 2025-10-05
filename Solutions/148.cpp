// 148. Sort List


#include <vector>
#include <algorithm>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 //  TIME COMPLEXITY : O(NlogN)
 // SPACE COMPLEXITY : O(N)

 // TODO SPACE (1)

class Solution {
public:
     ListNode* sortList(ListNode* head) {

          std::vector<ListNode*> vec{};
          for (auto it{ head }; it; it = it->next)
               vec.push_back(it);

          std::ranges::sort(vec, [](const ListNode* a, const ListNode* b) 
               {return a->val < b->val; });

          ListNode dummy{};
          auto tail{ &dummy };

          for (auto& i : vec)
          {
               tail->next = i;
               tail = tail->next;
          }

          tail->next = nullptr;
          return dummy.next;

     }
};