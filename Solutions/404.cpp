// 404. Sum of Left Leaves

#include <vector>

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
 
class Solution {
public:
     int sumOfLeftLeaves(TreeNode* root) {

          if (!root) return 0;

          std::vector<TreeNode*> stk{ root };
          int sum{};

          while (!stk.empty())
          {
               const auto it{ stk.back() }; stk.pop_back();

               if (it->left)
               {
                    if (!it->left->left && !it->left->right) sum += it->left->val;
                    else stk.push_back(it->left);
               }

               if (it->right) stk.push_back(it->right);
          }
          return sum;
       
     }
};