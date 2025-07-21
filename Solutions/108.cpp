// 108. Convert Sorted Array to Binary Search Tree

#include <vector>
#include <tuple>

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
     TreeNode* sortedArrayToBST(std::vector<int>& nums) {
          if (nums.empty()) return nullptr;

          const int n = nums.size();
          
          auto root{ new TreeNode(0) };
          std::vector<std::tuple<TreeNode*, int, int>> stk{};
          stk.emplace_back(root, 0, n-1);

          while (!stk.empty())
          {
               const auto [node, l, r] = stk.back(); stk.pop_back();

               const int mid{ l + (r - l) / 2 };
               node->val = nums[mid];

               // Left child
               if (l < mid)
               {
                    node->left = new TreeNode(0);
                    stk.emplace_back(node->left, l, mid - 1);
               }
               // Right Child
               if (mid < r)
               {
                    node->right = new TreeNode(0);
                    stk.emplace_back(node->right, mid + 1, r);
               }

          }
          return root;
     }
};