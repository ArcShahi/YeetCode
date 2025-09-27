// 617. Merge Two Binary Trees

#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // ITERATIVE DFS

 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(N)

class Solution {
public:
     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        
          if (!root1 && !root2) return nullptr;
          if (!root1 || !root2) return root1 ? root1 : root2;

          std::vector<TreeNode*> stk{ root1 }, stk2{ root2 };

          while (!stk.empty())
          {
               auto it{ stk.back() }; stk.pop_back();
               auto kt{ stk2.back() }; stk2.pop_back();

               it->val += kt->val;

               if (!it->right && kt->right)
               {
                    it->right = kt->right;
               }           
               else if (it->right && kt->right)
               {
                    stk.push_back(it->right);
                    stk2.push_back(kt->right);
               }

               if (!it->left && kt->left)
               {
                    it->left = kt->left;
               }
               else if (it->left && kt->left) 
               {
                    stk.push_back(it->left);
                    stk2.push_back(kt->left);
               }
          
          }

          return root1;
     }
};


// RECURSIVE DFS

class Solution {
public:
     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

          if (!root1) return root2;
          if (!root2) return root1;
          if (!root1 && root2) return nullptr;

          root1->val += root2->val;

          root1->left = mergeTrees(root1->left, root2->left);
          root1->right = mergeTrees(root1->right, root2->right);

          return root1;

     }
};