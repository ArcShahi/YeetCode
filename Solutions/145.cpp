// 145. Binary Tree Postorder Traversal

#include <vector>

struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

// ITERATIVE

class Solution {
public:
     std::vector<int> postorderTraversal(TreeNode* root)
     {
          std::vector<int> result{};
          std::vector<TreeNode*> stack;

          auto itr{ root };
          TreeNode* last_visited{ nullptr };

          while (itr || not stack.empty())
          {
               if (itr) 
               {
                    // Go as left as possible
                    stack.push_back(itr);
                    itr = itr->left;
               }
               else 
               {
                    auto top_node{ stack.back() };

                    // If right child exists and wasn't visited yet, go right
                    if (top_node->right && last_visited != top_node->right) 
                    {
                         itr = top_node->right;
                    }
                    else 
                    {
                         // Both left and right are done, process the node
                         result.push_back(top_node->val);
                         last_visited = top_node;
                         stack.pop_back();
                    }
               }
          }

          return result;
     }
};

//  RECURSION

class Solution {
public:
     std::vector<int> postorderTraversal(TreeNode* root)
     {
          dfs(root);
          return vec;
     }
private:
     std::vector<int> vec{};

     void dfs(TreeNode* node)
     {
          if (!node) return;

          dfs(node->left);
          dfs(node->right);
          vec.push_back(node->val);
     }
};