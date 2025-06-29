// 236. Lowest Common Ancestor of a Binary Tree

#include <vector>
#include <unordered_map>
#include <unordered_set>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

          if (!root) return nullptr;

          // child->parent
          std::unordered_map<TreeNode*, TreeNode*> parent{};
          std::vector<TreeNode*> stk{};

          parent[root] = nullptr;
          stk.push_back(root);

          while (!parent.count(p) || !parent.count(q))
          {
               auto itr{ stk.back() };
               stk.pop_back();

               if (itr->left)
               {
                    parent[itr->left] = itr;
                    stk.push_back(itr->left);
               }
               if (itr->right)
               {
                    parent[itr->right] = itr;
                    stk.push_back(itr->right);
               }
          }

          std::unordered_set<TreeNode*> ancestors{};

          while (p)
          {
               ancestors.insert(p);
               p = parent[p];
          }
          while (!ancestors.count(q))
          {
               q = parent[q];
          }

          return q;
     }
};

// Recursive

// I'll only allow it for post order stuff


class Solution2 {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if (!root || root == p || root == q) return root;

          auto left = lowestCommonAncestor(root->left, p, q);
          auto right = lowestCommonAncestor(root->right, p, q);

          if (!left) return right;
          if (!right) return left;

          return root;
     }
};