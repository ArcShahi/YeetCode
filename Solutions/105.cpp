// 105. Construct Binary Tree from Preorder and Inorder Traversal

#include <vector>
#include <unordered_map>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 // TIME COMPLEXITY :O(n)
 
 /*
   pop when going right  else insert as left child
 */

class Solution {
public:
     TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

          std::unordered_map<int, int> hashmap{};
          for (int i{ 0 }; const auto & v : inorder)
               hashmap[v] = i++;

          std::vector<TreeNode*> stack{};
          auto root{ new TreeNode(preorder[0]) };
          stack.push_back(root);

          for (int i{ 1 }; i < preorder.size(); ++i)
          {
               auto node{ new TreeNode(preorder[i]) };
               TreeNode* parent{ nullptr };

               // pop the stack while new node should go right ( testing is right child )
               while (!stack.empty() && hashmap[stack.back()->val]<hashmap[node->val])
               {
                    parent = stack.back();
                    stack.pop_back();
               }

               if (parent) parent->right = node;
               else stack.back()->left = node;

               stack.push_back(node);
          }
          return root;
     }
};