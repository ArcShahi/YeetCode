// 173. Binary Search Tree Iterator

#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class BSTIterator {
public:
     BSTIterator(TreeNode* root) {
          for (auto it{ root }; it; it = it->left)
               stk.push_back(it);
     }

     int next() {
          auto node{ stk.back() }; stk.pop_back();
          int val{ node->val };

          for (auto it{ node->right }; it; it = it->left)
               stk.push_back(it);
          
          return val;        
     }

     bool hasNext() {
          return !stk.empty();
     }
private:
     std::vector<TreeNode*> stk{};
};
