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
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     std::vector<int> preorderTraversal(TreeNode* root) {

          std::vector<int> vec{};
          if (not root) return vec;

          std::vector<TreeNode*> stk{};
          stk.push_back(root);
          while (not stk.empty())
          {
               const auto node = stk.back();
               stk.pop_back();

               vec.push_back(node->val);

               if (node->right) stk.push_back(node->right);
               if (node->left) stk.push_back(node->left);
          }
          return vec;

     }
};

// RECURSIVE

class Solution {
public:
     std::vector<int> preorderTraversal(TreeNode* root) {

          dfs(root);
          return vec;
     }
private:
     std::vector<int> vec{};

     void dfs(TreeNode* node)
     {
          if (!node) return;
          vec.push_back(node->val);
          dfs(node->left);
          dfs(node->right);
     }
};

