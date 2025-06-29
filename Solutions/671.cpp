// 671. Second Minimum Node In a Binary Tree

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
      int findSecondMinimumValue(TreeNode* root) {
           if (!root) return -1;

           long sec_min = LONG_MAX;  
           std::vector<TreeNode*> stack;
           stack.push_back(root);

           while (!stack.empty())
           {
                auto itr{ stack.back() };
                stack.pop_back();

                // If greater than root val and smaller than sec_min
                if (root->val < itr->val && itr->val < sec_min) {
                     sec_min = itr->val;
                }
                else if (itr->val == root->val) 
                {
                     // Child has same value as parent, need to search this subtree
                     if (itr->right) stack.push_back(itr->right);
                     if (itr->left) stack.push_back(itr->left);
                }
           }

           return (sec_min == LONG_MAX) ? -1 : static_cast<int>(sec_min);
      }
 };