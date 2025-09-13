// 105. Construct Binary Tree from Preorder and Inorder Traversal

#include <vector>
#include <unordered_map>
#include <span>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // ITERAIVE 
 // TIME COMPLEXITY :O(N)
 // SPACE COMPLEXITY : O(N)

 /*
   pop when going right  else insert as left child
 */

class Solution {
public:
     TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

          std::unordered_map<int, int> pos{};
          
          for (int i{ 0 }; i < inorder.size(); ++i)
               pos[inorder[i]] = i;

          std::vector<TreeNode*> stk{};
          auto root{ new TreeNode(preorder[0]) };
          stk.push_back(root);

          for (int i{ 1 }; i < preorder.size(); ++i)
          {
               auto node{ new TreeNode(preorder[i]) };
               TreeNode* parent{ nullptr };

               // Find correct parent by popping nodes that should be ancestors
               while (!stk.empty() && pos[stk.back()->val]< pos[node->val])
               {
                    parent = stk.back();
                    stk.pop_back();
               }

               if (parent) parent->right = node;
               else stk.back()->left = node;

               stk.push_back(node);
          }
          return root;
     }
};

// RECURSIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

          for (int i{ 0 }; i < inorder.size(); ++i)
               imap[inorder[i]] = i;

          return make_tree(preorder, inorder);
     }

private:

     std::unordered_map<int, int> imap{};

     TreeNode* make_tree(std::span<int> pre, std::span<int> in)
     {
          if (pre.empty()) return nullptr;
          auto root{ new TreeNode(pre[0]) };
         // Convert from absolute position to relative position due to std::span
          const int i{ imap[pre[0]] - imap[in[0]] }; // root index
 
          root->left = make_tree(pre.subspan(1, i), in.first(i));
          root->right = make_tree(pre.subspan(i + 1), in.subspan(i + 1));

          return root;
     }  
};
