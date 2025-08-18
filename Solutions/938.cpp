// 938. Range Sum of BST

#include <vector>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXTIY : O(N)

class Solution {
public:
     int rangeSumBST(TreeNode* root, int low, int high) {

          if (!root) return 0;

          std::vector<TreeNode*> stk{};
          stk.push_back(root);

          int sum{ 0 };

          while (!stk.empty())
          {
               const auto it{ stk.back() }; 
               stk.pop_back();
               if (!it) continue;

               if (low <= it->val && it->val <= high) sum += it->val;

               if (it->val<high)stk.push_back(it->right);
               if (low < it->val) stk.push_back(it->left);
          }

          return sum;
     }
};