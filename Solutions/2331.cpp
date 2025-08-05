// 2331. Evaluate Boolean Binary Tree\

#include <vector>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 bool evaluate(const TreeNode* node, const TreeNode* left, const TreeNode* right)
 {
      if (node->val == 2) return left->val || right->val;
      if (node->val == 3) return left->val && right->val;
      return 0;
 }
 // ITERATIVE POST-ORDER

class Solution {
public:
     bool evaluateTree(TreeNode* root) {

          if (!root) return false;

          std::vector<TreeNode*> stk{};
          auto it{ root };
          TreeNode* last{ nullptr };

          while (!stk.empty() || it)
          {
               if (it) 
               {
                    stk.push_back(it);
                    it = it->left;
               }
               else 
               {
                    auto top{ stk.back() };

                    if (top->right && last!=top->right)
                         it = top->right;
                    else
                    {
                         if (top->left && top->right)
                              top->val = evaluate(top, top->left, top->right);
                         
                         last = top;
                         stk.pop_back();
                    }
               }
          }
          return root->val;
     }
};

// RECURSIVE

class Solution {
public:
     bool evaluateTree(TreeNode* root) {
          // It's a leaf node: return its boolean value directly
          if (!root->left && !root->right) 
               return root->val;
         
          // Recurse into left and right subtrees
          bool left = evaluateTree(root->left);
          bool right= evaluateTree(root->right);

          // Internal node: evaluate based on the operator
          if (root->val == 2)      return left || right;  // OR
          else if (root->val == 3) return left && right;  // AND

          return false;  // fallback 
     }
};
