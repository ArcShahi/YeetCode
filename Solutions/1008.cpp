// 1008. Construct Binary Search Tree from Preorder Traversal

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
 // SPACE COMPLEXITY: O(N)

 class Solution {
 public:
      TreeNode* bstFromPreorder(std::vector<int>& preorder) {


           auto root{ new TreeNode{preorder[0]} };
           std::vector<TreeNode*> stk{root};


           for (size_t i{ 1 }; i < preorder.size(); ++i)
           {
                auto it{ new TreeNode{preorder[i]} };
                TreeNode* parent{ nullptr };

                while (!stk.empty() && stk.back()->val< it->val)
                {
                     parent = stk.back(); stk.pop_back();
                }
                if (parent) parent->right = it;
                else stk.back()->left = it;

                stk.push_back(it);
           }
           return root;
      }
      
 };


 // TIME COMPLEXITY : O(N^2)
 // SPACE COMPLEXITY : O(N)

class Solution {
public:
     TreeNode* bstFromPreorder(std::vector<int>& preorder) {

          auto root{ new TreeNode{preorder[0]} };
          for (int i{ 1 }; i < preorder.size(); ++i)
          {
               auto node{ new TreeNode{preorder[i]} };
               insert(root, node);
          }
          return root;
     }

private:

    void  insert(TreeNode* root, TreeNode* node)
     {
          auto it{ root };
          TreeNode* parent{ nullptr };

          while (it)
          {
               parent = it;
               it = node->val < it->val ? it->left : it->right;
          }

          if (parent->val < node->val) parent->right = node;
          else parent->left = node;

     }
};