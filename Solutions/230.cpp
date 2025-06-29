// 230. Kth Smallest Element in a BST
#include <vector>



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // ITERATIVE INORDER

 // TIME COMPLEXITY :O(n)
 // SPACE COMPLEXITY : O(n)
class Solution {

     using Stack = std::vector<TreeNode*>;

public:
     int kthSmallest(TreeNode* root, int k) {

          if (not root) return 0;

          int smallest{};
          Stack stack{};
          
          auto itr{ root };

          while (itr || !stack.empty())
          {
               if (itr)
               {
                    stack.push_back(itr);
                    itr = itr->left;
               }
               else
               {
                    itr = stack.back();
                    stack.pop_back();

                    smallest = itr->val;
                    itr = itr->right;

                    if (--k == 0) return smallest;
               }
          }
          return smallest;
     }
};

