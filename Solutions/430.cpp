//430. Flatten a Multilevel Doubly Linked List

#include <vector>


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// TIME COMPELXITY : O(n)
// SPACE COMPLEXITY: O(1)

// Break and merge
class Solution {
public:
     Node* flatten(Node* head) {

          if (!head) return nullptr;

          auto itr{ head };

          while (itr)
          {
               if (itr->child)
               {
                    auto nxt = itr->next;
                    auto child = itr->child;

                    // connect current to child
                    itr->next = child;
                    child->prev = itr;
                    itr->child = nullptr;

                    auto tail{ child };
                    while (tail->next) tail = tail->next;

                    if (nxt)
                    {
                         tail->next = nxt;
                         nxt->prev = tail;
                    }
               }
               itr = itr->next;
          }
          return head;
     }
};

// TIME COMPLEXITY :O(n)
// SPACE COMPLEXITY: O(n);
class Solution {
public:
     Node* flatten(Node* head) {

          if (!head) return nullptr;

          std::vector<Node*> stk{};
          stk.push_back(head);

          Node snode{};
          auto tail{ &snode };
     
          Node* pvs{ nullptr };
          while (!stk.empty())
          {
               const auto itr{ stk.back() };
               stk.pop_back();

               tail->next = itr;
               itr->prev = tail;
               tail = itr;

               if (itr->next) stk.push_back(itr->next);
               if (itr->child) {
                    stk.push_back(itr->child);
                    itr->child = nullptr;
               }
          }
          snode.next->prev = nullptr;
          return snode.next;
           
     }
};