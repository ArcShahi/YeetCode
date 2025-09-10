// 99. Recover Binary Search Tree

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
 

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     void recoverTree(TreeNode* root) {

          if (!root) return;

          std::vector<TreeNode*> stk{};
    
          TreeNode* it{ root }, *first{}, *sec{}, *prev{};

          while (!stk.empty()|| it)
          {
               if (it)
               {
                    stk.push_back(it);
                    it = it->left;
               }
               else
               {
                    it = stk.back(); stk.pop_back();
                   // Check violation
                    if (prev && prev->val > it->val)
                    {
                         first = first ? first : prev;
                         sec = it;
                    }

                    prev = it;
                    it = it->right;
                    
               }
          }

          if (first && sec) std::swap(first->val, sec->val);
     }

 
};


// TODO : Follow up in constant space using Morris Traversal