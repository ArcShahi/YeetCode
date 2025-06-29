// 104. Maximum Depth of Binary Tree
#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // DFS PRE_ORDER
class Solution {
public:
     int maxDepth(TreeNode* root)
     {
          if (not root) return 0;
          // Push node and current depth 
          std::vector<std::pair<TreeNode*, int>> stack{};

          stack.push_back({ root,1 });
          int max_depth{ 0 };

          while (!stack.empty())
          {
               const auto [node, depth] {stack.back()};
               stack.pop_back();

               max_depth = std::max(max_depth, depth);

               if (node->right) stack.push_back({ node->right,depth+1 });
               if (node->left)stack.push_back({ node->left,depth+1});
          }
         
          return max_depth;
     }
};



