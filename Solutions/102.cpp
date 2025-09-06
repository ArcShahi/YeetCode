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

          std::vector<std::vector<int>> vec{};
          if (!root) return vec;

          std::deque<TreeNode*> q{};
          q.push_back(root);

          while (!q.empty())
          {
               std::vector<int> lvl{};
               int width = q.size(); // nodes at this level
       
               for (int i{ 0 }; i < width; ++i)
               {
                    const auto it{ q.front() }; q.pop_front();

                    lvl.push_back(it->val);

                    if (it->left) q.push_back(it->left);
                    if (it->right)q.push_back(it->right);
               }

               vec.push_back(lvl);              
          }

          return vec;
     }
};