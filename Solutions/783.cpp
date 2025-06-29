// 783. Minimum Distance Between BST Nodes

#include <vector>

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
     int minDiffInBST(TreeNode* root) {

          if (!root) return 0;
          std::vector<TreeNode*> stack{};
          auto itr{ root };

          int diff{ INT_MAX };
          TreeNode* prev{ nullptr };

          while (!stack.empty() || itr)
          {
               if (itr)
               {
                    stack.push_back(itr);
                    itr = itr->left;
               }
               else {
                    itr = stack.back();
                    stack.pop_back();

                    if (prev)
                    {
                         diff = std::min(diff, itr->val - prev->val);
                    }
                    prev = itr;

                    itr = itr->right;
               }
          }
          return diff;

     }
};