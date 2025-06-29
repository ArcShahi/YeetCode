// 138. Copy List with Random Pointer

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) 
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include <iostream>

//  TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1) constant

const auto FAST_IO = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {

public:
     // IO slow the runtime
     Solution()
     {
          std::ios::sync_with_stdio(false);
          std::cin.tie(nullptr);
     }

public:
     Node* copyRandomList(Node* head)
     {
          if (not head)return nullptr;

          auto itr{ head };
          // Merge both
          while (itr)
          {
               auto node{ new Node(itr->val) };  // Create a copy of current node
               auto succ = itr->next;            // Save the next node
               itr->next = node;                 // Link current node to its copy
               node->next = succ;                // Link the copy to the next original node
               itr = succ;                       // Move to the saved next node
          }

          itr = head;

          // Update the Random Pointer
          while (itr)
          {   // make sure random ptr doesn't point to nullptr
               itr->next->random = itr->random ? itr->random->next : nullptr;
               itr = itr->next->next;
          }

          // Split 

          Node s_node{ 0 };
          auto tail{ &s_node };

          itr = head;

          while (itr)
          {
               auto cpy_node = itr->next;
               auto og_next = itr->next->next;

               tail->next = cpy_node;
               itr->next = og_next;

               itr = og_next;
               tail = cpy_node; // or tail=tail->next;
          }
          return s_node.next;
     }
};