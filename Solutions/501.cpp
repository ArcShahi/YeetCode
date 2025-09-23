// 501. Find Mode in Binary Search Tree

#include <vector>
#include <unordered_map>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TODO: FOLLOW UP
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<int> findMode(TreeNode* root) {

          std::vector<int> mode{};

          std::vector<TreeNode*> stk{};
          std::unordered_map<int, int> hmap{};

          auto it{ root };

          while (!stk.empty() || it)
          {
               if (it)
               {
                    stk.push_back(it);
                    it = it->left;
               }
               else
               {
                    it = stk.back(); stk.pop_back();
                    ++hmap[it->val];
                    it = it->right;
               }
          }

          auto freq{ 0 };
          for (const auto& [key, val] : hmap)
               freq = std::max(freq, val);

          for (const auto& [key, val] : hmap)
               if (val == freq) mode.push_back(key);

          return mode;
     }
};