// 114. Flatten Binary Tree to Linked List


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
     void flatten(TreeNode* root) {

          if (!root) return;

          std::vector<TreeNode*> stack{};
          stack.push_back(root);
          TreeNode* prev{ nullptr };

          while (!stack.empty())
          {
               auto itr{ stack.back() };
               stack.pop_back();
              
               if (prev)
               {
                    prev->right = itr;
                    prev->left = nullptr;
               }

               prev = itr;

               if (itr->right)stack.push_back(itr->right);
               if (itr->left) stack.push_back(itr->left);

          }

     }
};