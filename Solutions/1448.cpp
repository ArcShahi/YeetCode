// 1448. Count Good Nodes in Binary Tree

#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(N)

class Solution {
public:
     int goodNodes(TreeNode* root) {

          if (!root->left && !root->right) return 1;

          std::vector<std::pair<TreeNode*,int>> stk{};
          stk.push_back({ root,root->val });

          int count{ 0 };
          while (!stk.empty())
          {
               const auto [node, max] = stk.back();
               stk.pop_back();

               if (node->val >= max) ++count;

               int umax{ std::max(max,node->val) };

               if (node->right) stk.push_back({ node->right,umax });
               if (node->left) stk.push_back({ node->left,umax });
          }
          return count;
     }
};