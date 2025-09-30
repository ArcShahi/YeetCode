// 2265. Count Nodes Equal to Average of Subtree


#include <vector>
#include <utility>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(H)
 
class Solution {
public:
     int averageOfSubtree(TreeNode* root) {

          int count{ 0 };
          dfs(root,count);
          return count;
     }
 
     std::pair<int, int> dfs(TreeNode* node, int& count)
     {
          if (!node) return { 0,0 };

          auto [lsum, lsize] = dfs(node->left, count);
          auto [rsum, rsize] = dfs(node->right, count);

          auto sum = lsum + rsum + node->val;
          auto size = lsize + rsize + 1;

          if (sum / size == node->val) ++count;

          return { sum,size };
     }
};