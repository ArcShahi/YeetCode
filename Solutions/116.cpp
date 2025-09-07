// 116. Populating Next Right Pointers in Each Node


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
        : val(_val), left(_left), right(_right), next(_next) {}
};

// BFS
// TIME COMPLEXITY O(n)
// SPACE COMPLEXITY :O(1)


class Solution {
public:
     Node* connect(Node* root) 
     {
          if (!root) return root;

          auto lvl{ root };

          while (lvl->left) 
          {    
               auto it{ lvl };

               while (it) 
               {
                    // Connect left child to right child
                    it->left->next = it->right;

                    // Connect right child to next node's left child
                    if (it->next)
                         it->right->next = it->next->left;
                   
                    it = it->next;
               }

               lvl = lvl->left; 
          }

          return root;
     }
};

