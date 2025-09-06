// 104. Maximum Depth of Binary Tree
#include <vector>
#include <queue>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // DFS PRE_ORDER

 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY: O(N)

class Solution {
public:
     int maxDepth(TreeNode* root)
     {
          if (not root) return 0;

          
          std::vector<std::pair<TreeNode*, int>> stk{};
          // Push node and current depth 
          stk.push_back({ root,1 });
          int max_depth{ 0 };

          while (!stk.empty())
          {
               const auto [node, depth] {stk.back()}; stk.pop_back();
               max_depth = std::max(max_depth, depth);

               if (node->right) stk.push_back({ node->right,depth+1 });
               if (node->left)stk.push_back({ node->left,depth+1});
          }
         
          return max_depth;
     }
};

// BFS
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     int maxDepth(TreeNode* root)
     {
          if (not root) return 0;
          
          std::deque<TreeNode*> q{};
          q.push_back(root);
          int depth{ 0 };

          for (; !q.empty(); ++depth)
          {
               int width = q.size();
               while (width--)
               {
                    const auto it{ q.front() }; q.pop_front();
                    
                    if (it->left) q.push_back(it->left);
                    if (it->right) q.push_back(it->right);
               }
          }

          return depth;
     }
};


// RECURSIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
     int maxDepth(TreeNode* root)
     {
          if (not root) return 0;
          return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
     }
};