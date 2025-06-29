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
 
class Solution {
public:
     int minDepth(TreeNode* root) 
     {
          if (not root) return 0;

          int depth{1};

          std::deque<TreeNode*> q{};
          q.push_back(root);

          while (not q.empty())
          {
               auto width{ q.size() };

               while (width-->0)
               {
                    const auto itr{ q.front() };
                    q.pop_front();

                    // If no Leaf return
                    if (!itr->left && !itr->right) return depth;
                    if (itr->left) q.push_back(itr->left);
                    if (itr->right) q.push_back(itr->right);

               }

               ++depth;

          }
          return depth;
     }
};