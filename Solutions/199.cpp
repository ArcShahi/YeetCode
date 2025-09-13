// 199. Binary Tree Right Side View

#include <vector>
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
 // SPACE COMPLEXITY : O(N)

 // BFS and inserte last of every level

class Solution {
public:
     std::vector<int> rightSideView(TreeNode* root) {

          if (!root) return {};

          std::deque<TreeNode*> q{ root };
          std::vector<int> vec{};

          while (!q.empty())
          {
               TreeNode* last{};

               int width=q.size();
               while (width-->0)
               {
                    auto it{ q.front() }; q.pop_front();
                    last = it;

                    if (it->left) q.push_back(it->left);
                    if (it->right) q.push_back(it->right);
               }

               if (last) vec.push_back(last->val);
          }
          return vec;
     }
};