// 701. Insert into a Binary Search Tree




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// TIME COMPLEXITY : O(H) H:Height of the tree
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     TreeNode* insertIntoBST(TreeNode* root, int val) {

          auto node{ new TreeNode(val) };
          if (!root) return node;

          auto it{ root };
          TreeNode* parent{ nullptr };
          while (it)
          { 
               parent = it;
               if (it->val < val) it = it->right;
               else it = it->left;
          }

          if (parent->val < val) parent->right = node;
          else parent->left = node;

          return root;
     }
};