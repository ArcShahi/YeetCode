// 94. Binary Tree Inorder Traversal

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
 // SPACE COMPLEXITY : O(N)

 class Solution {
 public:
      std::vector<int> inorderTraversal(TreeNode* root) {

           std::vector<int> vec{};
           if (not root) return vec;

           std::vector<TreeNode*> stk{};
           auto it{ root };
           
           while (it || not stk.empty())
           {
                // Iterate to leftmost node
                while (it)
                {
                     stk.push_back(it);
                     it = it->left;
                }

                // current will be nullptr, so fetch from top of stk
                it = stk.back(); 
                stk.pop_back();

                vec.push_back(it->val); // prcoess the node
                it = it->right;
           }

           return vec;
      }
 };


 class Solution2 {
 public:
      std::vector<int> inorderTraversal(TreeNode* root) {

           std::vector<int> vec{};

           if (not root) return vec;

           std::vector<TreeNode*> stk{};
           auto it{ root };

           while (it || not stk.empty()) {

                if (it) 
                {
                     stk.push_back(it);
                     it = it->left;
                }
                else 
                {
                     it = stk.back();
                     stk.pop_back();
                     vec.push_back(it->val);  // process the node
                     it = it->right;
                }
           }
           return vec;
      }
 };

 // RECURSIVE

 class Solution3 {
 public:
      std::vector<int> inorderTraversal(TreeNode* root) {

           dfs(root);
           return vec;
      }
 private:
      std::vector<int> vec{};

      void dfs(TreeNode* node)
      {
           if (!node) return;

           dfs(node->left);
           vec.push_back(node->val);
           dfs(node->right);
      }
 };


