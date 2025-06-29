// 100. Same Tree
#include <queue>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

 // BFS Iterative
 class Solution {
 public:
      bool isSameTree(TreeNode* p, TreeNode* q) {
           std::queue<TreeNode*> q1{}, q2{};
           q1.push(p);
           q2.push(q);

           while (!q1.empty() && !q2.empty()) 
           {
                auto i = q1.front(); q1.pop();
                auto j = q2.front(); q2.pop();

                if (!i && !j) continue;
                //  test if both structure and values are same
                if (!i || !j || i->val != j->val) return false;

                q1.push(i->left);
                q1.push(i->right);

                q2.push(j->left);
                q2.push(j->right);
           }

           return q1.empty() && q2.empty();
      }
 };
