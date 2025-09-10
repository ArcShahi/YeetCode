// 110. Balanced Binary Tree

#include <deque>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// RECURSIVE

 class Solution {
 public:
      bool isBalanced(TreeNode* root) {
           return checkHeight(root) != -1;
      }

 private:
      int checkHeight(TreeNode* root) {
           if (!root) return 0;

           int left = checkHeight(root->left);
           // left subtree is not balanced
           if (left == -1) return -1;

           int right = checkHeight(root->right);
           // right subtree is not balanced
           if (right == -1) return -1; 

           // current node not balanced
           if (abs(left - right) > 1) return -1; // current node not balanced

           return 1 + std::max(left, right);
      }
 };
