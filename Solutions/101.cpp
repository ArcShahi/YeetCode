// 101. Symmetric Tree

#include <deque>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 // BFS
class Solution {
public:
     bool isSymmetric(TreeNode* root) {

          if (not root) return false;

          std::deque<TreeNode*> q{};
          q.push_back(root->left);
          q.push_back(root->right);

          while (!q.empty())
          {
               const auto lhs{ q.front() }; 
               q.pop_front();
               const auto rhs{ q.front() };
               q.pop_front();

               if (!lhs && !rhs) continue;
               if (!lhs || !rhs) return false;
               if (lhs->val != rhs->val) return false;

               // Push children in Mirrored order
               q.push_back(lhs->left);
               q.push_back(rhs->right);
               q.push_back(lhs->right);
               q.push_back(rhs->left);
          }

          return true;
     }
};