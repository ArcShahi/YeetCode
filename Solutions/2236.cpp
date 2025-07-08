// 2236. Root Equals Sum of Children

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(1)
class Solution {
public:
     bool checkTree(TreeNode* root) {

          return root->val == root->left->val + root->right->val;
     }
};