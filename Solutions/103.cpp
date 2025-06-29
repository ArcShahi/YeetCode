// 103. Binary Tree Zigzag Level Order Traversal
#include <deque>
#include <vector>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // TIME COMPLEXITY : O(n)
 // SPACE COMPLEXITY : O(n)
 
class Solution {
public:
     std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {


          std::vector<std::vector<int>> vec{};
          if (not root) return vec;

          std::deque<TreeNode*> q{};
          q.push_back(root);

          int depth{ 0 };

          while (!q.empty())
          {
               auto width{ q.size() };
               std::vector<int> level{};

               while (width-->0)
               {
                    const auto itr{ q.front() };
                    q.pop_front();

                    level.push_back(itr->val);

                    if (itr->left) q.push_back(itr->left);
                    if (itr->right) q.push_back(itr->right);
                    
               }

               if (depth&1)
               {
                    std::reverse(begin(level), end(level));     
               }
               // increase depth ( or (depth++&1)
               ++depth;
   
               vec.push_back(level);
               
          }
          return vec;
     }
};