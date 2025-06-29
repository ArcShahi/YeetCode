// 102. Binary Tree Level Order Traversal

#include <vector>
#include <queue>
#include <iostream>



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // ITERATIVE
 // TIME COMPLEXITY : O(n)
 // SPACE COMPLEXITY : O(n)



 //auto fast_io{ [] {std::ios::sync_with_stdio(false);
 //                   std::cin.tie(nullptr);
 //                   return 0; }() };


class Solution {
public:
     std::vector<std::vector<int>> levelOrder(TreeNode* root) {

          std::vector<std::vector<int>> level{};
          if (not root) return level;


          std::queue<TreeNode*> q{};
          q.push(root);

          while (not q.empty())
          {
               std::vector<int> curr_lvl{};
               int nodes = q.size(); // nodes at this level
       
               for (int i{ 0 }; i < nodes; ++i)
               {
                    auto itr = q.front();
                    q.pop();

                    curr_lvl.push_back(itr->val);

                    if (itr->left) q.push(itr->left);
                    if (itr->right)q.push(itr->right);
               }

               level.push_back(curr_lvl);              
          }

          return level;
     }
};