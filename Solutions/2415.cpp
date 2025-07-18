// 2415. Reverse Odd Levels of Binary Tree

#include <deque>
#include <vector>
#include <algorithm>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 /*
  Traverse the tree level by level using BFS. For odd levels, collect nodes,
  and reverse their values. Use two pointers to swap values in place.
 */

 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY :O(N)
 class Solution {
 public:  
      TreeNode* reverseOddLevels(TreeNode* root) {
           if (!root) return nullptr;

           std::deque<TreeNode*> q{};
           q.push_back(root);
           bool flag{ false }; // false: even level, true: odd level

           nodes.reserve(100);

           while (!q.empty())
           {
                auto width{ q.size() };
                nodes.clear(); 

                while (width--> 0)
                {
                     auto it{ q.front() }; q.pop_front();
                     nodes.push_back(it);

                     if (it->left) q.push_back(it->left);
                     if (it->right) q.push_back(it->right);
                }

                if (flag) reverse_level();
                flag = !flag;
           }

           return root;
      }

 private:
      std::vector<TreeNode*> nodes{};

 private:
      void reverse_level() {
           auto l{ begin(nodes) };
           auto r{ end(nodes) - 1 };
           while (l < r)
                std::swap((*l++)->val, (*r--)->val); 
      }
 };
