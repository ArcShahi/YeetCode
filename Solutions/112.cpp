// 112. Path Sum

#include <vector>



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// DFS - PRE-ORDER
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     bool hasPathSum(TreeNode* root, int targetSum) 
     {
          if (!root) return false;

          std::vector<std::pair<TreeNode*, int>> stk{};
          stk.push_back({ root,root->val });

          while (!stk.empty())
          {
               const auto [node, sum] {stk.back()};stk.pop_back();

               //  If leaf and sum found
               if (sum == targetSum && !node->left && !node->right) return true;
               if (node->right) stk.push_back({ node->right,sum + node->right->val });
               if (node->left) stk.push_back({ node->left,sum + node->left->val });

          }
          return false;
     }
};