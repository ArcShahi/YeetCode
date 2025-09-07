// 637. Average of Levels in Binary Tree

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
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY: O(N)

class Solution {
public:
     std::vector<double> averageOfLevels(TreeNode* root) {

          std::vector<double> avg{};
          std::deque<TreeNode*> q{};
          q.push_back(root);

          while (!q.empty())
          {
               int width = q.size();
               double sum{ 0 };
               for (int i{ 0 }; i < width; ++i)
               {
                    const auto it{ q.front()}; q.pop_front();

                    sum += it->val;
                    if (it->left) q.push_back(it->left);
                    if (it->right) q.push_back(it->right);
               }
               avg.push_back(sum/width);
          }

          return avg;
     }
};