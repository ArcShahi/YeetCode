// 1261. Find Elements in a Contaminated Binary Tree
#include <vector>
#include <unordered_set>
#include <algorithm>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 // PRE-ORDER + HASHSET

class FindElements {
public:
     FindElements(TreeNode* root) {
          if (!root) return;
          std::vector<TreeNode*> stk{};
          stk.reserve(1000);
          set.reserve(1000);
          root->val = 0;
          stk.push_back(root);

          while (!stk.empty())
          {
               auto itr{ stk.back() };
               stk.pop_back();
               set.insert(itr->val);

               if (itr->right)
               {    
                    itr->right->val = 2 * itr->val + 2;
                    stk.push_back(itr->right);
               }
               if (itr->left)
               {
                    itr->left->val = 2 * itr->val + 1;
                    stk.push_back(itr->left);
               }
          }

     }

     bool find(int target) {
          return set.find(target) != set.end();
     }

private:
     std::unordered_set<int> set{};  
};

// ANOTHER SOLUTION BFS +  BINARY SEARCH ( CACHE FRIENDLY CUZ the elements will be sorted )

