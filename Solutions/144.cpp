// 144. Binary Tree  DFS::Preorder Traversal

#include <vector>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // ITERATIVE

class Solution {
public:
     std::vector<int> preorderTraversal(TreeNode* root) {

          std::vector<int> vec{};

          if (not root) return vec;

          std::vector<TreeNode*> stack{};
          stack.push_back(root);
          while (not stack.empty())
          {
               auto node = stack.back();
               stack.pop_back();

               vec.push_back(node->val);

               if (node->right) stack.push_back(node->right);
               if (node->left) stack.push_back(node->left);
          }
          return vec;

     }
};

