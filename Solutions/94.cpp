// 94. Binary Tree Inorder Traversal

#include <vector>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 


 class Solution {
 public:
      std::vector<int> inorderTraversal(TreeNode* root) {

           std::vector<int> vec{};

           if (not root) return vec;

           std::vector<TreeNode*> stack{};
           auto itr{ root };
           
           while (itr || not stack.empty())
           {
                // Iterate to leftmost node
                while (itr)
                {
                     stack.push_back(itr);
                     itr = itr->left;
                }

                // current will be nullptr, so fetch from top of stack
                itr = stack.back(); 
                stack.pop_back();

                vec.push_back(itr->val); // prcoess the node
                itr = itr->right;
           }

           return vec;
      }
 };


 class Solution2 {
 public:
      std::vector<int> inorderTraversal(TreeNode* root) {

           std::vector<int> vec{};

           if (not root) return vec;

           std::vector<TreeNode*> stack{};
           auto itr{ root };

           while (itr || not stack.empty()) {

                if (itr) 
                {
                     stack.push_back(itr);
                     itr = itr->left;
                }
                else 
                {
                     itr = stack.back();
                     stack.pop_back();

                     vec.push_back(itr->val);  // process the node
                     itr = itr->right;
                }
           }

           return vec;
      }
 };
