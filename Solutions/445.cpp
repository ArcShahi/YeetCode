
#include <vector>

struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
     {    // Reserve Space of Runtime
          std::vector<int> s1{};
          std::vector<int> s2{};

          // Extract digits from both lists
          while (l1) {
               s1.emplace_back(l1->val);
               l1 = l1->next;
          }

          while (l2) {
               s2.emplace_back(l2->val);
               l2 = l2->next;
          }

          // Create a dummy node for easier linked list construction
          auto s_node{ new ListNode{0} };
          auto tail = s_node;
          int cy{ 0 };

          // Calculate sum from right to left
          while (!s1.empty() || !s2.empty() || cy > 0) 
          {
               int d1 = s1.empty() ? 0 : s1.back();
               int d2 = s2.empty() ? 0 : s2.back();
               int sum = cy + d1 + d2;
               cy = sum / 10;

               if (!s1.empty()) s1.pop_back();
               if (!s2.empty()) s2.pop_back();

               // Create a new node for the current digit
               tail->next = new ListNode(sum % 10);
               tail = tail->next;
          }

          // At this point, we have the result in reverse order (right to left)
          // We need to reverse it to get the final answer

          // Step 1: Disconnect the result from the dummy node
          tail = s_node->next;
          delete s_node;

          // Step 2: Reverse the linked list
          ListNode* pvs{ nullptr };       

          while (tail) {
               auto succ = tail->next;
               tail->next = pvs;
               pvs = tail;
               tail = succ;
          }

          // prev now points to the head of the reversed list
          return pvs;
     }
};