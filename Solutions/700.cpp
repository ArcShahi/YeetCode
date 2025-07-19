// 700. Search in a Binary Search Tree



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(1)

class Solution {
public:
     TreeNode* searchBST(TreeNode* root, int val) {

          if (!root) return nullptr;

          auto it{ root };
          while (it)
          {
               if (it->val == val) return it;
               if (it->val < val) it = it->right;
               else it = it->left;
          }
          return nullptr;
     }
};