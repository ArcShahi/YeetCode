// 226. Invert Binary Tree
#include <queue>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // ITERATIVE BFS
 // TIME COMPLEXITY : O(n)
 // SPACE COMPLEXITY : O(w) w:width

class Solution {
public:
     TreeNode* invertTree(TreeNode* root) {

          if (not root) return nullptr;

          std::queue<TreeNode*> q{};
          q.push(root);

          while (not q.empty())
          {
               auto itr = q.front();
               q.pop();

               // Swap'
               std::swap(itr->left, itr->right);

               if (itr->left) q.push(itr->left);
               if (itr->right) q.push(itr->right);
          }

          return root;
     }
};

// ITERATIVE DFS ( PREORDER)
//  TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(h) height of tree

class Solution2 {
public:
     TreeNode* invertTree(TreeNode* root) {
          if (!root) return nullptr;

          std::vector<TreeNode*> stack{};
          stack.push_back(root);

          while (not stack.empty()) 
          {
               auto itr = stack.back();
               stack.pop_back();

               // Swap left and right children
               std::swap(itr->left, itr->right);

               // Push children (if not null)
               if (itr->right) stack.push_back(itr->right);
               if (itr->left)  stack.push_back(itr->left);
          }

          return root;
     }
};


// RECURSIVE
// SPACE COMPLEXITY : O(h) height of tree
class Solution3 {
public:
     TreeNode* invertTree(TreeNode* root) {

          if (not root) return nullptr;

          // swap
          std::swap(root->left, root->right);

          // Recurse on children
          invertTree(root->left);
          invertTree(root->right);

          return root;
     }
};


