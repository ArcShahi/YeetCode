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

          auto itr{ root };

          while (itr)
          {
               Node snode{};
               auto tail{ &snode };

               // Iterate current level
               while (itr)
               {
                    if (itr->left)
                    {
                         tail->next = itr->left;
                         tail = tail->next;
                    }

                    if (itr->right)
                    {
                         tail->next = itr->right;
                         tail = tail->next;
                    }

                    itr = itr->next;
               }
               itr = snode.next;
          }
          return root;
     }
};