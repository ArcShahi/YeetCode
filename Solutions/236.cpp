// 236. Lowest Common Ancestor of a Binary Tree

#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
 // ITERATIVE
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(N)

 class Solution {
 public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if (!root) return nullptr;

           // Child to Parent Map
           std::unordered_map<TreeNode*, TreeNode*> parent{ {root,nullptr}};
           std::deque<TreeNode*> dq{root};

           // BFS until both nodes found
           while (!parent.count(p) || !parent.count(q)) {
                
                const auto node{ dq.front() }; dq.pop_front();

                if (node->left) {
                     parent[node->left] = node;
                     dq.push_back(node->left);
                }
                if (node->right) {
                     parent[node->right] = node;
                     dq.push_back(node->right);
                }
           }

           std::unordered_set<TreeNode*> ancestors{};
           for (auto it = p; it; it = parent[it])
                ancestors.insert(it);

           // if found it ancestors that is LCA
           while (!ancestors.count(q)) q = parent[q];

           return q;
      }
 };

// ITERATIVE DFS
// TIME COMPLEIXTY : O(N)
// SPACE COMPLEXITY : O(N) 

 class Solution {
 public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if (!root) return nullptr;

           // Child to Parent Map
           std::unordered_map<TreeNode*, TreeNode*> parent{ {root,nullptr}};
           std::vector<TreeNode*> stk{root};

           // BFS until both nodes found
           while (!parent.count(p) || !parent.count(q)) {
                
                const auto node{ stk.back() }; stk.pop_back();

                if (node->right) {
                     parent[node->right] = node;
                     stk.push_back(node->right);
                }
                if (node->left) {
                     parent[node->left] = node;
                     stk.push_back(node->left);
                }
                
           }

           std::unordered_set<TreeNode*> ancestors{};
           for (auto it = p; it; it = parent[it])
                ancestors.insert(it);

           // if found it ancestors that is LCA
           while (!ancestors.count(q)) q = parent[q];

           return q;
      }
 };


// RECURSIVE
// TIME COMPLEIXTY : O(N)
// SPACE COMPLEXITY : O(N) 

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