// 117. Populating Next Right Pointers in Each Node II

// Definition for a Node.
class Node {
public:
     int val;
     Node* left;
     Node* right;
     Node* next;

     Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

     Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

     Node(int _val, Node* _left, Node* _right, Node* _next)
          : val(_val), left(_left), right(_right), next(_next) {
     }
};

// Connecting them Like linked list

class Solution {
public:
     Node* connect(Node* root) {

          if (!root) return nullptr;

          auto it{ root };
          while (it)
          {
               Node snode{};
               auto tail{ &snode };

               // Iterate current level
               while (it)
               {
                    if (it->left)
                    {
                         tail->next = it->left;
                         tail = tail->next;
                    }

                    if (it->right)
                    {
                         tail->next = it->right;
                         tail = tail->next;
                    }

                    it = it->next;
               }
               it = snode.next;
          }
          return root;
     }
};

/*
 Traverse level by level and connect them like linked lists
*/