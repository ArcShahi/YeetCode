// 543. Diameter of Binary Tree

#include <utility>

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
     int diameterOfBinaryTree(TreeNode* root) {

          dfs(root);
          return diameter;
     }

private:
     int diameter{ 0 };
     int dfs(TreeNode* node)
     {
          if (!node)return 0;
          
          int lh{ dfs(node->left) };
          int rh{ dfs(node->right) };

          diameter = std::max(diameter, lh + rh);
          return 1 + std::max(lh, rh);
     }
      
};
