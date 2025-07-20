// 98. Validate Binary Search Tree

#include <vector>
#include <tuple>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(H)

class Solution {
public:
     bool isValidBST(TreeNode* root) {

          if (!root) return true;

          std::vector<std::tuple<TreeNode*, long, long>> stk{};
          stk.push_back({ root,LONG_MIN,LONG_MAX });

          while (!stk.empty())
          {
               auto [it, min, max] = stk.back(); stk.pop_back();
               if (!it) continue;

               if (it->val <= min || max <= it->val) return false;

               if (it->right) stk.push_back({ it->right,it->val,max });
               if (it->left) stk.push_back({ it->left,min,it->val });
          }
          return true;
     }

};