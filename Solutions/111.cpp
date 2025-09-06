// 111. Minimum Depth of Binary Tree

#include <deque>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY: O(N)


class Solution {
public:
     int minDepth(TreeNode* root) 
     {
          if (!root) return 0;

          std::deque<TreeNode*> q{};
          q.push_back(root);   
          int depth{ 1 };

          for (; !q.empty(); ++depth)
          {
               int width = q.size();            
               while (width-->0)
               {
                    const auto it{ q.front() }; q.pop_front();

                    // If not leaf return that's our min depth
                    if (!it->left && !it->right)  return depth;
                    if (it->left) q.push_back(it->left);
                    if (it->right) q.push_back(it->right);
               }
          }
          return depth;
     }
};