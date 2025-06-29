// 106. Construct Binary Tree from Inorder and Postorder Traversal

#include <vector>
#include <unordered_map>
#include <algorithm>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // ITERATIVE 
 // TIME COMPLEXITY: O(n)
 /*
  pop when going left  else insert as right child
 */
class Solution {
public:
     TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {

          std::unordered_map<int, int>  hashmap{};
          for (int i{ 0 };const auto& v : inorder)
               hashmap[v]=i++;

          const auto root{ new TreeNode(postorder.back()) };
          postorder.pop_back();

          std::vector<TreeNode*> stack{};
          stack.push_back(root);
        

          while (!postorder.empty())
          {
               const auto node{ new TreeNode(postorder.back()) };
               postorder.pop_back();

               TreeNode* parent{ nullptr };

               while (!stack.empty() && hashmap[node->val]<hashmap[stack.back()->val])
               {
                    parent = stack.back();
                    stack.pop_back();
               }

               if (parent) parent->left = node;
               else stack.back()->right = node;

               stack.push_back(node);                   
          }

          return root;
     }
};
