// 1315. Sum of Nodes with Even-Valued Grandparent

#include <deque>

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

  // RECURSIVE DFS PREORDER

class Solution {
public:
     int sumEvenGrandparent(TreeNode* root) {

          return dfs(root, nullptr, nullptr);
     }
private:
    
     int dfs(TreeNode* node, TreeNode* parent, TreeNode* gparent)
     {
          if (!node) return 0;

          int sum{ 0 };
          if (gparent && gparent->val % 2 == 0) sum += node->val;

          sum += dfs(node->left, node, parent);
          sum += dfs(node->right, node, parent);

          return sum;
     }
};


// BFS

class Solution {
public:
     int sumEvenGrandparent(TreeNode* root) {

          if (!root) return 0;

          std::deque<TreeNode*> q{ root };
          int sum{ 0 };

          while (!q.empty())
          {
               const auto it{ q.front() }; q.pop_front();

               if (it->val % 2 == 0)
               {
                    if (it->left) sum += value_of(it->left->left) + value_of(it->left->right);
                    if (it->right) sum += value_of(it->right->left) + value_of(it->right->right);
               }

               if (it->left) q.push_back(it->left);
               if (it->right) q.push_back(it->right);
               
          }

          return sum;
     }
private:

     int value_of(TreeNode* root)
     {
          return root ? root->val : 0;
     }
};