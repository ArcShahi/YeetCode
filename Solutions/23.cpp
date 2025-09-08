// 23. Merge k Sorted Lists

#include <vector>
#include <algorithm>
#include <queue>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

// PRIORITY QUEUE 
// TIME COMPLEXITY : O(NlogK)
// SPACE COMPLEXITY: O(K): cuz it only holds root

class Solution {
public:
     ListNode* mergeKLists(std::vector<ListNode*>& lists) {

          auto cmp = [](const ListNode* a, const ListNode* b) {return a->val > b->val; };
          std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq{};

          for (auto node : lists)
               if (node) pq.push(node);

          // Create Forward list
          ListNode dummy{ 0 };
          auto tail{ &dummy };

          while (!pq.empty())
          {
               auto smallest{ pq.top() }; pq.pop();
               tail->next = smallest;
               tail = tail->next;

               if (smallest->next) pq.push(smallest->next);
          }
          tail->next = nullptr;
          return dummy.next;
     }
};

// SORTING
// TIME COMPLEXITY : O(nLogn)
// SPACE COMPLEXITY: O(n)


class Solution2 {
public:
     ListNode* mergeKLists(std::vector<ListNode*>& lists) {

          std::vector<ListNode*> vec{};
          vec.reserve(100);

          for (auto& node : lists)
               for (auto it{ node }; it; it = it->next)
                    vec.push_back(it);


          std::sort(begin(vec), end(vec),
               [](const ListNode* a, const ListNode* b) {return a->val < b->val; });


          // Create Forward list
          ListNode dummy{ 0 };
          auto tail{ &dummy };

          for (auto& node : vec)
          {
               tail->next = node;
               tail = tail->next;
          }
          tail->next = nullptr;

          return dummy.next;
     }
};