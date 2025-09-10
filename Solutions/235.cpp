// 235. Lowest Common Ancestor of a Binary Search Tree

#include <deque>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 // TIME COMPLEXITY : O(H)
 // SPACE COMPLEXITY : O(1)

class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

          if (!root || !p || !q) return nullptr;

          auto it{ root };

          while (it)
          {
               const auto num{ it->val };
               // Both p,q are smaller
               if (p->val < num && q->val <num) it = it->left;
               else if (num < p->val && num < q->val) it = it->right;
               else return it;
          }
          return nullptr;
     }
};


// RECURSIVE
// TIME COMPLEXITY : O(H)
// SPACE COMPLEXITY : O(H)

class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

          if (!root || !p || !q) return nullptr;

          const int num{ root->val };
          if (p->val < num && q->val < num) return lowestCommonAncestor(root->left, p, q);
          else if (num < p->val && num < q->val) return lowestCommonAncestor(root->right, p, q);
          else return root;
     }
};