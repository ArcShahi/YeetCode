// 1302. Deepest Leaves Sum
#include <vector> // for DFS
#include <deque>// for BFS



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // BFS
 // TIME COMPLEXITY : O(n)
 // SPACE COMPLEXITY : O(n)
 
class Solution {
public:
     int deepestLeavesSum(TreeNode* root) {

          if (!root)return 0;
          std::deque<TreeNode*> q{};
          q.push_back(root);

          int sum{ 0 };
          while (!q.empty())
          {
               int width = q.size();
               int lvl_sum{ 0 };
               while (width-->0)
               {
                    const auto itr{ q.front() };
                    q.pop_front();
                    lvl_sum += itr->val;

                    if (itr->left)q.push_back(itr->left);
                    if (itr->right)q.push_back(itr->right);
               }
               sum = lvl_sum;
          }
          return sum;
       
     }
};

// DFS
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY :O(n)

class Solution2 {
public:
     int deepestLeavesSum(TreeNode* root) {

          if (!root)return 0;
          std::vector<std::pair<TreeNode*, int>> stk{};
          stk.push_back({ root,1 });
          int max_depth{ 0 };
          // Find the max depth
          while (!stk.empty())
          {
               const auto [node, depth] = stk.back();
               stk.pop_back();
               max_depth = std::max(max_depth, depth);

               if (node->right)stk.push_back({ node->right,depth + 1 });
               if (node->left)stk.push_back({ node->left,depth + 1 });
          }
          stk.clear();

          stk.push_back({ root,1 });

          // Sum the nodes which are on same depth as max_depth
          int sum{ 0 };
          while (!stk.empty())
          {
               const auto [node, depth] = stk.back();
               stk.pop_back();

               if (depth == max_depth) sum += node->val;

               if (node->right)stk.push_back({ node->right,depth + 1 });
               if (node->left)stk.push_back({ node->left,depth + 1 });
          }
          return sum;
     }
};